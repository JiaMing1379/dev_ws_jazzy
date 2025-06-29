#ifndef DIFFDRIVE_ARDUINO_WHEEL_HPP
#define DIFFDRIVE_ARDUINO_WHEEL_HPP

#include <string>
#include <cmath>


class Wheel
{
    public:

    std::string name = "";
    int enc = 0;
    double cmd = 0;
    double pos = 0;
    double vel = 0;
    double rads_per_count = 0;
    double diameter = 0; // in mm
    Wheel() = default;

    Wheel(const std::string &wheel_name, int counts_per_rev, double wheel_diameter)
    {
      setup(wheel_name, counts_per_rev, wheel_diameter);
    }

    
    void setup(const std::string &wheel_name, int counts_per_rev, double wheel_diameter)
    {
      name = wheel_name;
      diameter = wheel_diameter; // in mm
      rads_per_count = (2 * M_PI) / counts_per_rev; // radians per count
    }

    double calc_enc_angle()
    {
      return enc * rads_per_count;
    }



};


#endif // DIFFDRIVE_ARDUINO_WHEEL_HPP
