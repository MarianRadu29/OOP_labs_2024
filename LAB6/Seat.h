#pragma once
#include"Car.h"
class Seat : public Car
{
public:
    Seat() : Car(60, 6.6, 210) {}
    const char* Name() const;
    unsigned int FuelCapacity() const;
    double FuelConsumption() const;
    unsigned int Speed(Weather x) const;
};