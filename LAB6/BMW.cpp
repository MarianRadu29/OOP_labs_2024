#include "BMW.h"
const char* BMW::Name() const {
    return "BMW Seria 5 520d Sedan";
}
unsigned int BMW::FuelCapacity() const
{
    return fuel_capacity;
}
double BMW::FuelConsumption() const
{
    return fuel_consumption;
}
unsigned int BMW::Speed(Weather x) const
{
    switch (x)
    {
    case Weather::Sunny:
        return max_speed;
    case Weather::Rain:
        return (80 * max_speed) / 100;
    case Weather::Snow:
        return (58 * max_speed) / 100;
    default:
        return max_speed;
    }
}