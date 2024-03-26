#include "Number.h"
#include<iostream>
#include<cmath>
int atoi_me(char* s)
{
	int number = 0 , i;
	for(i=0;s[i]!='\0';i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			number = number * 10 + (s[i] - '0');
	}
	return number;
}
int Number::base10() const
{
	int aux = 0;
	int n = strlen(value) - 1;
	for (int i = 0; i <= n; i++)
		if (value[i] >= 'A')
			aux = aux + (value[i] - 'A' + 10) * pow(base, n - i);
		else
			aux = aux + (value[i] - '0') * pow(base, n - i);
	return aux;
}
Number::Number(const char* value, int base) : value((char*)value), base(base) {}
Number::Number(int number): base(10)
{
	int count = 0 , aux = number;
	while (aux > 0)
	{
		aux /= base;
		count++;
	}
	value = new char[count];
	int index = count-1;
	while (number)
	{
		int r = number % base;
		char c = '0' + r;
		value[index--] = c;
		number /= base;
	}
	value[count] = '\0';
}
Number::Number(const Number& x)
{
	this->base = x.base;
	this->value = x.value;
}
Number::Number(Number&& x)
{
	this->base = x.base, x.base = 0;
	this->value = x.value, x.value = nullptr;
}
Number::~Number()
{	
	this->base = 0;
	this->value = nullptr;
}

void Number::SwitchBase(int newBase)
{	
	if (newBase == base || newBase<2 || newBase>16)
		return;
	
	//trasnformam numarul in baza 10
	int aux = base10();
	//in aux avem numarul in baza 10 si il vom converti la noua baza
	base = newBase;	
	int aux1 = aux;
	int count=0;
	while (aux1 > 0)
	{
		aux1 /= base;
		count++;
	}

	char* newvalue = new char[count];
	newvalue[count] = '\0';
	int index = count-1;
	while (aux>0)
	{	
		int x = aux % base;
		char c;
		if (x < 10)
			c = x + '0';
		else
			c = x - 10 + 'A';
		newvalue[index--] = c;
		aux /= base;
	}

	value = newvalue;
	//std::cout << &value << '\t' << &newvalue << '\n';
}
void Number::Print()
{
	std::cout << "Value = " << value << '\t' << "base = " << base << '\n';
}
int Number::GetBase()
{
	return base;
}
int  Number::GetDigitsCount()
{
	return strlen(value);
}
char Number::operator[](int index)
{
	return value[index];
}

bool Number::operator>(Number& x)
{
	int xx = (*this).base10();
	int yy = x.base10();
	if (xx > yy)
		return true;
	else
		return false;
			
}
bool Number::operator>=(Number& x)
{
	int xx = (*this).base10();
	int yy = x.base10();
	if (xx >= yy)
		return true;
	else
		return false;

}
bool Number::operator<(Number& x)
{
	int xx = (*this).base10();
	int yy = x.base10();
	if (xx < yy)
		return true;
	else
		return false;

}
bool Number::operator<=(Number& x)
{
	int xx = (*this).base10();
	int yy = x.base10();
	if (xx <= yy)
		return true;
	else
		return false;

}
bool Number::operator==(Number& x)
{
	int xx = (*this).base10();
	int yy = x.base10();
	if (xx == yy)
		return true;
	else
		return false;

}
bool Number::operator!=(Number& x)
{
	int xx = (*this).base10();
	int yy = x.base10();
	if (xx != yy)
		return true;
	else
		return false;

}

void Number::operator=(const char* x)
{
	base = 10;
	this->value = (char*)x;
}
Number& Number::operator=(Number x)
{
	(*this).value = x.value;
	(*this).base = x.base;
	return (*this);
}
void Number::operator=(int x)
{	
	base = 2;
	int count = 0, aux = x;
	while (aux > 0)
	{
		aux /= base;
		count++;
	}
	value = new char[count];
	int index = count - 1;
	while (x)
	{
		int r = x % base;
		char c = '0' + r;
		value[index--] = c;
		x /= base;
	}
	value[count] = '\0';
}
Number& Number::operator+=(Number x)
{
	(*this) = (*this) + x;
	return (*this);
}
Number& Number::operator-=(Number x)
{
	(*this) = (*this) - x;
	return (*this);
}


Number& Number::operator--()//predecrementarea
{	
	char* newvalue = new char[strlen(value)];
	newvalue = value + 1;
	value = newvalue;
	return (*this);
}
Number Number::operator--(int val)//postdecrementare
{	
	int n = strlen(value)-1;
	char* s = new char[n];
	for (int i = 0; i < n; i++)
		s[i] = value[i];
	s[n] = '\0';
	value = s;
	return (*this);
}

Number operator+(const Number  &x, const Number &y)
{
	int maxx = std::max(x.base, y.base);
	int xx , yy ;
	xx = x.base10();
	yy = y.base10();
	xx += yy;
	Number rezultat(xx);
	rezultat.SwitchBase(maxx);
	return rezultat;
}
Number operator-(const Number& x, const Number& y)
{
	int maxx = std::max(x.base, y.base);
	int xx, yy;
	xx = x.base10();
	yy = y.base10();
	xx -= yy;
	Number rezultat(xx);
	rezultat.SwitchBase(maxx);
	return rezultat;
}
////////////////////////////////////////////////////////////////
/*

Number Number::operator+(Number& x)
{
	int maxx = std::max(x.GetBase(), (*this).GetBase());
	int xx = 0, yy = 0;
	xx = x.base10();
	yy = (*this).base10();
	xx += yy;
	Number rezultat(xx);
	rezultat.SwitchBase(maxx);
	return rezultat;
}

Number Number::operator-(Number& x)
{
	int maxx = std::max(x.GetBase(), (*this).GetBase());
	int xx = 0, yy = 0;
	yy = x.base10();
	xx = (*this).base10();
	xx -= yy;
	Number rezultat(xx);
	rezultat.SwitchBase(maxx);
	return rezultat;
}
*//////////////////////////////////////////
