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


char* Math::Add(const char* x, const char* y)
{	
	if (x == nullptr || y==nullptr)
		return nullptr;


	//Daca era de facut concatenarea celor 2 siruri
	 
	//const int m = strlen(x) + strlen(y)+1;
	//const auto s = new char[m];
	//strcpy_s(s, m, x);
	//strcat_s(s, m, y);
	//return s;
	


	if (strlen(x) > strlen(y))
		swap(x, y);	
	char*  = new char[strlen(y) + 1];
	int zz = 0 , xx = strlen(x) - 1 , yy = strlen(y) - 1 , exces = 0;
	while (xx>-1)
	{	
		int a = x[xx--] - '0' + y[yy--] - '0' + exces;
		exces = (a > 9) ? 1 : 0;
		z[zz++] = a % 10 + '0';
	}
	while (yy>-1)
	{
		int a = y[yy--] - '0' + exces;
		exces = (a > 9) ? 1 : 0;
		z[zz++] = a % 10 + '0';
	}
	if (exces)
		z[zz++] = exces + '0';
	z[zz] = '\0';
	_strrev(z);
	return z;
	
}
