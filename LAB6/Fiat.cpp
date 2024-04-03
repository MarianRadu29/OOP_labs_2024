#include "Fiat.h"
const char* Fiat::Name() const {
    return "Fiat Bravo 2013 1.6";
}
unsigned int Fiat::FuelCapacity() const
{
    return fuel_capacity;
}
double Fiat::FuelConsumption() const
{
    return fuel_consumption;
}
unsigned int Fiat::Speed(Weather x) const
{
    switch (x)
    {
    case Weather::Sunny:
        return max_speed;
    case Weather::Rain:
        return (70 * max_speed) / 100;
    case Weather::Snow:
        return (55 * max_speed) / 100;
    default:
        return max_speed;
    }
}