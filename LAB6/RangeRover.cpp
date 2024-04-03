#include "RangeRover.h"
const char* RangeRover::Name() const {
    return "Range Rover Velar S D200";
}
unsigned int RangeRover::FuelCapacity() const
{
    return fuel_capacity;
}
double RangeRover::FuelConsumption() const
{
    return fuel_consumption;
}
unsigned int RangeRover::Speed(Weather x) const
{
    switch (x)
    {
    case Weather::Sunny:
        return max_speed;
    case Weather::Rain:
        return (85 * max_speed) / 100;
    case Weather::Snow:
        return (69 * max_speed) / 100;
    default:
        return max_speed;
    }
}
