#include "Circuit.h"
void Circuit::SortCarsFinish()
{
    for (int i = 0; i < count_finish - 1; i++)
        for (int j = i + 1; j < count_finish; j++)
            if (result[finish[i]] > result[finish[j]])
                std::swap(finish[i], finish[j]);
}
void Circuit::SortCarsNoFinish()
{
    for (int i = 0; i < count_not_finish - 1; i++)
        for (int j = i + 1; j < count_not_finish; j++)
            if (result[notfinish[i]] > result[notfinish[j]])
                std::swap(notfinish[i], notfinish[j]);
}
Circuit::Circuit() : count_car(0), count_finish(0), count_not_finish(0), length(0), condition(Weather::Sunny) {}
Circuit::~Circuit()
{
    delete[] race;
    delete[] result;
    delete[] finish;
    delete[] notfinish;
}
void Circuit::SetLength(int x)
{
    length = x;
}
void Circuit::SetWeather(Weather x)
{
    condition = x;
}
void Circuit::AddCar(Car* x)
{
    Car** newrace = new Car * [++count_car];
    for (int i = 0; i < count_car - 1; i++)
        newrace[i] = race[i];
    newrace[count_car - 1] = x;
    delete[] race;
    race = newrace;

}
void Circuit::Race()
{   
    result = new double[count_car];
    finish = new int[count_car];
    notfinish = new int[count_car];
    for (int i = 0; i < count_car; i++)
    {
        double x = double(race[i]->FuelCapacity() * 100 * ((double)race[i]->Speed(condition)/ race[i]->Speed(Sunny)) / race[i]->FuelConsumption());//calculam ce distanta parcurge masina i cu caracteristicile acesteia
        //((double)race[i]->Speed(condition)/ race[i]->Speed(Sunny)) este o conditie suplimentara pt a calcula distanta,nu poti face acelasi nr de km pe vreme frumoasa sau pe o vreme ploioasa
        if (x >= length)//daca distanta acesteia e mai mare sau egala cu lungimea cursei,inseamna ca termina cursa si returnam timpul parcurs
        {
            result[i] = (double)length / race[i]->Speed(condition);
            finish[count_finish++] = i;
        }
        else//altfel memoram cati km mai avea pana la final
        {
            notfinish[count_not_finish++] = i;
            result[i] = length - x;
        }
    }
    //cout<<count_finish<<' '<<count_not_finish<<endl;
    SortCarsFinish();
    SortCarsNoFinish();
}
void Circuit::ShowFinalRanks()
{
    for (int i = 0; i < count_finish; i++)
        std::cout << "#" << i + 1 << ' ' << race[finish[i]]->Name() << '\t' << std::fixed << std::setprecision(3) << result[finish[i]] * 60 << " minute" << '\n';//result retine nr de ore 
    std::cout << '\n';
}
void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < count_not_finish; i++)
        std::cout << race[notfinish[i]]->Name() << '\t' << std::fixed << std::setprecision(3) << result[notfinish[i]] << "km ramasi pana la linia de finish" << '\n';
    std::cout << '\n';
}