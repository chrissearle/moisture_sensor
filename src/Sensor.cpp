#include "Sensor.h"

Sensor::Sensor(const char *name, byte pin)
{
    sensor_name = strdup(name);
    sensor_pin = pin;
}

Sensor::Sensor(const char *name, byte pin, int min, int max)
{
    sensor_name = strdup(name);
    sensor_pin = pin;
    sensor_min = min;
    sensor_max = max;
}

char *Sensor::getName()
{
    return sensor_name;
}

float Sensor::getHumidity()
{
    int value = analogRead(sensor_pin);
    value = map(value, sensor_min, sensor_max, 0, 100);
    return value;
}
