#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
    Volvo() : Car(70, 6.8, 195) {}
    const char* Name() const;
    unsigned int FuelCapacity() const;
    double FuelConsumption() const;
    unsigned int Speed(Weather x) const;
};
