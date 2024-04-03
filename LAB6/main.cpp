#include"Circuit.h"
int main()
{
    Circuit c;
    c.SetLength(1000);
    c.SetWeather(Weather::Rain);
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());
    c.Race();
    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
    c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
    std::cout << __DATE__ << '\n' << __TIME__ << '\n';
    /*
    Circuit cc;
    cc.SetLength(1000);
    cc.SetWeather(Weather::Sunny);
    cc.AddCar(new Volvo());
    cc.AddCar(new BMW());
    cc.AddCar(new Seat());
    cc.AddCar(new Fiat());
    cc.AddCar(new RangeRover());
    cc.Race();
    cc.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
    cc.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
    */
    return 0;
}
