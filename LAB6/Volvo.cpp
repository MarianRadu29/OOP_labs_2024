#include "Volvo.h"
const char* Volvo::Name() const {
    return "Volvo XC60 2012";
}
unsigned int Volvo::FuelCapacity() const
{
    return fuel_capacity;
}
double Volvo::FuelConsumption() const
{
    return fuel_consumption;
}
unsigned int Volvo::Speed(Weather x) const
{
    switch (x)
    {
    case Weather::Sunny:
        return max_speed;
    case Weather::Rain:
        return (85 * max_speed) / 100;
    case Weather::Snow:
        return (65 * max_speed) / 100;
    default:
        return max_speed;
    }
}