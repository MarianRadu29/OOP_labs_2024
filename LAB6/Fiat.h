#pragma once
#include"Car.h"
class Fiat : public Car
{
public:
    Fiat() : Car(55, 4.5, 195) {}
    const char* Name() const;
    unsigned int FuelCapacity() const;
    double FuelConsumption() const;
    unsigned int Speed(Weather x) const;
};