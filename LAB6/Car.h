#pragma once
#include "Weather.h"
class Car
{
protected://publice pt clasele derivate,private in afara
    unsigned int fuel_capacity;
    double fuel_consumption;
    unsigned int max_speed;
    Car(unsigned int a, double b, unsigned int c) : fuel_capacity(a), fuel_consumption(b), max_speed(c) {}
public:
    virtual const char* Name() const = 0;
    virtual unsigned int FuelCapacity() const = 0;
    virtual double FuelConsumption() const = 0;
    virtual unsigned int Speed(Weather x) const = 0;
};