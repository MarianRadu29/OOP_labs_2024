#pragma once
class Number
{
	// add data members
	char* value;
	int base;
	int base10() const;
	int atoi_me(char* s);
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& x);
	Number(Number&& x);
	Number(int number);
	~Number();

	

	char operator[](int index);


	//	> >= == != < <=
	bool operator>(Number& x);
	bool operator>=(Number& x);
	bool operator<(Number& x);
	bool operator<=(Number& x);
	bool operator==(Number& x);
	bool operator!=(Number& x);
	

	//Number operator+(Number& x);
	//Number operator-( Number& x);
	friend Number operator+(const Number &x, const Number &y);
	friend Number operator-(const Number &x,const Number &y);
	Number& operator+=(Number x);
	Number& operator-=(Number x);
	
	
	Number& operator=(Number x);
	void operator=(int x);
	void operator=(const char* x);

	Number& operator--();
	Number operator--(int val);


	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
