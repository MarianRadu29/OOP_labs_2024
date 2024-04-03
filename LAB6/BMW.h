#pragma once
#include"Car.h"
class BMW :public Car
{
public:
    BMW() : Car(60, 5.6, 235) {}
    const char* Name() const;
    unsigned int FuelCapacity() const;
    double FuelConsumption() const;
    unsigned int Speed(Weather x) const;
};

