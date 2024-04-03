#pragma once
#include"Car.h"
class RangeRover : public Car
{
public:
    RangeRover() : Car(65, 6.7, 210) {}
    const char* Name() const;
    unsigned int FuelCapacity() const;
    double FuelConsumption() const;
    unsigned int Speed(Weather x) const;
};
