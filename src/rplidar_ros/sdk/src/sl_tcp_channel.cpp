/*
 * Slamtec LIDAR SDK
 *
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

#include "sl_lidar_driver.h"
#include "hal/abs_rxtx.h"
#include "hal/socket.h"


namespace sl {
    
    class TcpChannel : public IChannel
    {
    public:
        TcpChannel(const std::string& ip, int port) : _binded_socket(rp::net::StreamSocket::CreateSocket()) {
            _ip = ip;
            _port = port;
        }

        bool bind(const std::string & ip, sl_s32 port)
        {
            _socket = rp::net::SocketAddress(ip.c_str(), port);
            return true;
        }

        bool open()
        {
            if(!bind(_ip, _port))
                return false;
            return IS_OK(_binded_socket->connect(_socket));
            
        }

        void close()
        {
            _binded_socket->dispose();
            _binded_socket = NULL;
        }
        void flush()
        {
        
        }

        sl_result waitForDataExt(size_t& size_hint, sl_u32 timeoutInMs)
        {
            u_result ans;
            size_hint = 0;
            ans = _binded_socket->waitforData(timeoutInMs);

            switch (ans) {
            case RESULT_OK:
                size_hint = 1024; //dummy value
                break;
            }

            return ans;
        }

        bool waitForData(size_t size, sl_u32 timeoutInMs, size_t* actualReady)
        {
            if (actualReady)
                *actualReady = size;
            return (_binded_socket->waitforData(timeoutInMs) == RESULT_OK);

        }

        int write(const void* data, size_t size)
        {
            return _binded_socket->send(data, size);
        }

        int read(void* buffer, size_t size)
        {
            size_t lenRec = 0;
            _binded_socket->recv(buffer, size, lenRec);
            return (int)lenRec;
        }

        void clearReadCache() {}

        void setStatus(_u32 flag){}

        int getChannelType() {
            return CHANNEL_TYPE_TCP;
        }
    private:
        rp::net::StreamSocket * _binded_socket;
        rp::net::SocketAddress _socket;
        std::string _ip;
        int _port;
    };
    Result<IChannel*> createTcpChannel(const std::string& ip, int port)
    {
        return new  TcpChannel(ip, port);
    }
}