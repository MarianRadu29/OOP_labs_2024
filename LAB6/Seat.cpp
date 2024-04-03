#include "Seat.h"
const char* Seat::Name() const {
    return "Seat Tarraco 2020 2.0 TDI (200CP)";
}
unsigned int Seat::FuelCapacity() const
{
    return fuel_capacity;
}
double Seat::FuelConsumption() const
{
    return fuel_consumption;
}
unsigned int Seat::Speed(Weather x) const
{
    switch (x)
    {
    case Weather::Sunny:
        return max_speed;
    case Weather::Rain:
        return (75 * max_speed) / 100;
    case Weather::Snow:
        return (55 * max_speed) / 100;
    default:
        return max_speed;
    }
}