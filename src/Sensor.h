#ifndef SENSOR_H
#define SENSOR_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Sensor
{
  private:
    char *sensor_name;
    byte sensor_pin;
    int sensor_min = 1500;
    int sensor_max = 800;

  public:
    Sensor(const char *name, byte pin);
    Sensor(const char *name, byte pin, int sensor_min, int sensor_max);

    char *getName();
    float getHumidity();
};

#endif