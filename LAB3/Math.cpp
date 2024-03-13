#include "Math.h"
#include<iostream>
#include<cstring>
#include<varargs.h>//	pt familia/functiile va_
using namespace std;
int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return int(x + y);
}
int Math::Add(double x, double y, double z)
{
	return int(x + y + z);
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return int(x * y);
}
int Math::Mul(double x, double y, double z)
{
	return int(x * y * z);
}
int Math::Add(int count, ...)//sums up a list of integers
{	
	va_list a;//pt numarul variabil de parametrii ai functiei
	va_start(a, count);//preluam primul parametru al functiei
	int suma = 0;
	for (int i = 0; i < count; i++)
		suma += va_arg(a, int);//preluam iterat parametrii functiei,daca nu sunt toti int ,suma nu va fii rezultatul dorit
	va_end(a);//inchidem iteratia ->un fel de f.close()
	return suma;
}


char* Math::Add(const char* x, const char* y)//concateneaza cele 2 siruri
{	
	if (x == nullptr || y==nullptr)
		return nullptr;
	//const int m = strlen(x) + strlen(y)+1;
	//const auto s = new char[m];
	//strcpy_s(s, m, x);
	//strcat_s(s, m, y);
	//return s;
	//

	//le facem int pe x si y
	int number1 = 0, i;
	for (i = 0; i < strlen(x); i++)
		number1 = number1 * 10 + x[i] - '0';
	int number2 = 0;
	for (i = 0; i < strlen(y); i++)
		number2 = number2 * 10 + y[i] - '0';

	//facem suma
	number1 += number2;

	//verificam cate cifre are numarul
	int aux = number1, nr = 0;
	while (aux)
	{
		aux /= 10;
		nr++;
	}


	//alocam dinamic un vector de char si convertim int in char
	char* xx = new char[nr];
	xx[nr] = '\0';
	//cout << "Numarul de cifre: " << nr << '\t' << number1 << '\t' << strlen(xx) << endl;
	nr = 0;
	while (number1)
	{
		xx[nr++] = number1 % 10 + '0';
		number1 /= 10;
	}
	//xx[nr] = '\0';
	_strrev(xx);//mai sus s-a convertit oglinditul lui number1
	
	return xx;
	
}


