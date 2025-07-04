#ifndef DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP
#define DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP

// #include <cstring>
#include <sstream>
// #include <cstdlib>
#include <libserial/SerialPort.h>
#include <iostream>


LibSerial::BaudRate convert_baud_rate(int baud_rate)
{
  // Just handle some common baud rates
  switch (baud_rate)
  {
    case 1200: return LibSerial::BaudRate::BAUD_1200;
    case 1800: return LibSerial::BaudRate::BAUD_1800;
    case 2400: return LibSerial::BaudRate::BAUD_2400;
    case 4800: return LibSerial::BaudRate::BAUD_4800;
    case 9600: return LibSerial::BaudRate::BAUD_9600;
    case 19200: return LibSerial::BaudRate::BAUD_19200;
    case 38400: return LibSerial::BaudRate::BAUD_38400;
    case 57600: return LibSerial::BaudRate::BAUD_57600;
    case 115200: return LibSerial::BaudRate::BAUD_115200;
    case 230400: return LibSerial::BaudRate::BAUD_230400;
    default:
      std::cout << "Error! Baud rate " << baud_rate << " not supported! Default to 57600" << std::endl;
      return LibSerial::BaudRate::BAUD_57600;
  }
}

class ArduinoComms
{

public:

  ArduinoComms() = default;

  void connect(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms)
  {  
    timeout_ms_ = timeout_ms;
    serial_conn_.Open(serial_device);
    serial_conn_.SetBaudRate(convert_baud_rate(baud_rate));
  }

  void disconnect()
  {
    serial_conn_.Close();
  }

  bool connected() const
  {
    return serial_conn_.IsOpen();
  }

  void read_encoder_values(int &enc_1, int &enc_2)
  {
    serial_conn_.FlushIOBuffers(); 
    serial_conn_.Write("$upload:1,0,0#\r\n");
    // std::cerr << "Message sent: " << "$upload:1,0,0#" << std::endl;

    // Read response from hardware
    std::string response;
    try
    {
      serial_conn_.ReadLine(response, '\r\n', timeout_ms_);
      // std::cerr << "Received after sending message: " << response << std::endl;
      // Find the colon and hash to extract the data part
      auto start = response.find(":");
      auto end = response.find("#");
      if (start != std::string::npos && end != std::string::npos && end > start)
      {
          std::string data = response.substr(start + 1, end - start - 1);
          std::stringstream ss(data);
          std::string item;
          int values[4];
          int i = 0;
          while (std::getline(ss, item, ',') && i < 4)
          {
            values[i++] = std::stoi(item);
          }
          enc_1 = values[0];
          enc_2 = values[1];
      } 
    }
    catch (const LibSerial::ReadTimeout&)
    {
      std::cerr << "Read timeout: No response received from hardware." << std::endl;
    }
  }

  void set_motor_values(int val_1, int val_2)
  {
    std::stringstream ss;
    ss << "$spd:" << val_1 << "," << val_2 << ",0,0#\r\n";
    serial_conn_.FlushIOBuffers(); 
    serial_conn_.Write(ss.str());
    // std::cerr << "testval_1: " << val_1 << ", val_2: " << val_2 << std::endl; // Debug print
  }

  void send_message(std::string message)
  {
    serial_conn_.FlushIOBuffers(); 
    serial_conn_.Write(message);
    std::cerr << "Message sent: " << message << std::endl;

    // Read response from hardware
    std::string response;
    try
    {
      serial_conn_.ReadLine(response, '\r\n', timeout_ms_);
      std::cerr << "Received after sending message: " << response << std::endl;
    }
    catch (const LibSerial::ReadTimeout&)
    {
      std::cerr << "Read timeout: No response received from hardware." << std::endl;
    }
  }

  void read_battery() //cant really function yet
  {
    serial_conn_.FlushIOBuffers(); 
    serial_conn_.Write("$read_vol#\r\n");
    std::string response;
    try
    {
      serial_conn_.ReadLine(response, '\r\n', timeout_ms_);
      std::cerr << "Received battery value: " << response << std::endl; // Debug print
    }
    catch (const LibSerial::ReadTimeout&)
    {
      std::cerr << "Read timeout: No response received from hardware." << std::endl;
    }
  }


  void set_motor_type(int motor_type)
  {
    std::stringstream ss;
    ss << "$mtype:" << motor_type << "#\r\n";
    send_message(ss.str());
  }

  void set_motor_deadband(int motor_deadband)
  {
    std::stringstream ss;
    ss << "$deadzone:" << motor_deadband << "#\r\n";
    send_message(ss.str());
  }

  void set_motor_phase_lines(int motor_phase_lines)
  {
    std::stringstream ss;
    ss << "$mline:" << motor_phase_lines << "#\r\n";
    send_message(ss.str());
  }

  void set_motor_reduction_ratio(int reduction_ratio)
  {
    std::stringstream ss;
    ss << "$mphase:" << reduction_ratio << "#\r\n";
    send_message(ss.str());
  }

  void set_wheel_diameter(float wheel_diameter)
  {
    std::stringstream ss;
    ss << "$wdiameter:" << wheel_diameter << "#\r\n";
    send_message(ss.str());
  }

  void set_pid_values(int k_p, int k_d, int k_i)
  {
    std::stringstream ss;
    ss << "$MPID:" << k_p << "," << k_i << "," << k_d << "#\r\n";
    send_message(ss.str());
  }

  void stop_motors(){
    serial_conn_.Write("$pwm:0,0,0,0#\r\n");
    std::cerr << "pwm is reset to 0" << std::endl;
  }

private:
    LibSerial::SerialPort serial_conn_;
    int timeout_ms_;
};

#endif // DIFFDRIVE_ARDUINO_ARDUINO_COMMS_HPP