/*
 *  RPLIDAR SDK
 *
 *  Copyright (c) 2009 - 2014 RoboPeak Team
 *  http://www.robopeak.com
 *  Copyright (c) 2014 - 2020 Shanghai Slamtec Co., Ltd.
 *  http://www.slamtec.com
 *
 */
/*
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once
namespace rp{ namespace hal{

class Event
{
public:
    
    enum
    {
        EVENT_OK = 1,
        EVENT_TIMEOUT = 0xFFFFFFFF,
        EVENT_FAILED = 0,
    };
    
    Event(bool isAutoReset = true, bool isSignal = false)
#ifdef _WIN32
        : _event(NULL)
#else
        : _is_signalled(isSignal)
        , _isAutoReset(isAutoReset)
#endif
    {
#ifdef _WIN32
        _event = CreateEvent(NULL, isAutoReset?FALSE:TRUE, isSignal?TRUE:FALSE, NULL); 
#else
        pthread_mutex_init(&_cond_locker, NULL);
        pthread_condattr_init(&_cond_attr);
#ifdef _MACOS
        // sadly, there is no monotonic clock support for pthread cond variable on MACOS
        // if time slew is a big issue, try to reimplement it using kqueue/kevent
#else
        pthread_condattr_setclock(&_cond_attr, CLOCK_MONOTONIC);
#endif
        pthread_cond_init(&_cond_var, &_cond_attr);
       
#endif
    }

    ~ Event()
    {
        release();
    }

    void set( bool isSignal = true )
    {
        if (isSignal){
#ifdef _WIN32
            SetEvent(_event);
#else
            pthread_mutex_lock(&_cond_locker);
               
            if ( _is_signalled == false )
            {
                _is_signalled = true;
                pthread_cond_signal(&_cond_var);
            }
            pthread_mutex_unlock(&_cond_locker);
#endif
        }
        else
        {
#ifdef _WIN32
            ResetEvent(_event);
#else
            pthread_mutex_lock(&_cond_locker);
            _is_signalled = false;
            pthread_mutex_unlock(&_cond_locker);
#endif
        }
    }
    
    unsigned long wait( unsigned long timeout = 0xFFFFFFFF )
    {
#ifdef _WIN32
        switch (WaitForSingleObject(_event, timeout==0xFFFFFFF?INFINITE:(DWORD)timeout))
        {
        case WAIT_FAILED:
            return EVENT_FAILED;
        case WAIT_OBJECT_0:
            return EVENT_OK;
        case WAIT_TIMEOUT:
            return EVENT_TIMEOUT;
        }
        return EVENT_OK;
#else
        unsigned long ans = EVENT_OK;
        pthread_mutex_lock( &_cond_locker );

        if ( !_is_signalled )
        {
            
                if (timeout == 0xFFFFFFFF){
                    pthread_cond_wait(&_cond_var,&_cond_locker);
                }else
                {
                    int timewaitresult = 0;
#ifdef _MACOS
                    timespec wait_time;
                    
                    wait_time.tv_sec = timeout / 1000;
                    wait_time.tv_nsec = (timeout%1000)*1000000ULL;
                
                    timewaitresult = pthread_cond_timedwait_relative_np(&_cond_var,&_cond_locker,&wait_time);
#else
                    timespec wait_time;
                    clock_gettime(CLOCK_MONOTONIC, &wait_time);

                    wait_time.tv_sec += timeout / 1000;
                    wait_time.tv_nsec += (timeout%1000)*1000000ULL;
                
                    if (wait_time.tv_nsec >= 1000000000)
                    {
                       ++wait_time.tv_sec;
                       wait_time.tv_nsec -= 1000000000;
                    }
                    timewaitresult = pthread_cond_timedwait(&_cond_var,&_cond_locker,&wait_time);
#endif

                    switch (timewaitresult)
                    {
                    case 0:
                        // signalled
                        break;
                    case ETIMEDOUT:
                        // time up
                        ans = EVENT_TIMEOUT;
                        goto _final;
                        break;
                    default:
                        ans = EVENT_FAILED;
                        goto _final;
                    }
       
            }
        }
          
        //assert(_is_signalled);

        if ( _isAutoReset )
        {
            _is_signalled = false;
        }
_final:
        pthread_mutex_unlock( &_cond_locker );

        return ans;
#endif
        
    }
protected:

    void release()
    {
#ifdef _WIN32
        CloseHandle(_event);
#else
        pthread_mutex_destroy(&_cond_locker);
        pthread_cond_destroy(&_cond_var);
#endif
    }

#ifdef _WIN32
        HANDLE _event;
#else
        pthread_cond_t         _cond_var;
        pthread_mutex_t        _cond_locker;
        pthread_condattr_t     _cond_attr;
        bool                   _is_signalled;
        bool                   _isAutoReset;
#endif
};
}}
