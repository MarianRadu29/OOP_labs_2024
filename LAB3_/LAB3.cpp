#include<iostream>
#include"Canvas.h"
#include"Math.h"
using namespace std;
int main()
{
	Math A;
	cout << A.Add(3.15, 6.84)<<endl;
	cout << A.Add(4, 1, 2, 3, 4,5) << endl;
	//cout << A.Add("Lucrez pentru laboratorul de la ", "OOP.");
	cout << A.Add("10", "99");
	cout << endl << endl << endl;

	Canvas C(50, 50);
	C.DrawRect(10, 10, 20, 20, '0');
	C.FillRect(11, 11, 19, 19, '-');
	C.FillCircle(25, 25, 6, '1');
	C.DrawCircle(40, 10, 3, '2');
	C.DrawLine(0, 2, 50, 2,'!');
	C.DrawRect(0, -1, 50, 50, '#');
	C.SetPoint(5, 5, '*');
	C.FillRect(5, 35, 45, 45, '+');
	C.Print();
	//daca se depaseste width(>) sau height(>),programul crapa,nu stiu de ce
	
	return 0;
}