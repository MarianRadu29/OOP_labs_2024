#pragma once
#include"Car.h"
#include"Fiat.h"
#include"Volvo.h"
#include"RangeRover.h"
#include"Seat.h"
#include"BMW.h"
#include<iostream>
#include<iomanip>//pt setprecision() ->cate cifre sa afiseze dupa virgula,de ex pt 13.123 si ...setprecision(2)... rezulta 13.12 la afisare
class Circuit
{
    Car* race[50];
    int count_car;
    double result[50];
    int  count_result;
    int finish[50], count_finish;//in finish e timpul in care a parcurs cursa fiecare masina care a ajuns la final
    int notfinish[50], count_not_finish;
    int length;//lungimea cursei
    Weather condition;//conditiile cursei
    void SortCarsFinish();
    void SortCarsNoFinish();
public:
    Circuit();
    void SetLength(int x);
    void SetWeather(Weather x);
    void AddCar(Car* x);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
