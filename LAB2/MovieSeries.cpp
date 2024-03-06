#include "MovieSeries.h"
#include<iostream>
using namespace std;
void MovieSeries::init()
{
	count = 0;
}
bool MovieSeries::add(Movie *x)
{	
	if (count < 15)
	{
		const char* s = x->GetName();
		this->p[count].set_name(s);
		this->p[count].set_score(x->GetIMDB());
		this->p[count].set_length(x->GetLength_movie());
		this->p[count++].set_year(x->GetRelease_year());
	}
	else
		return 0;
}
void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << this->p[i].GetName() << '\t' << this->p[i].GetRelease_year() << '\t' << this->p[i].GetIMDB() << '\t' << this->p[i].GetLength_movie() << '\t' << this->p[i].GetPassed_year();
		cout << endl;
	}
}
void MovieSeries::sort()
{
	// sortare prin metoda insertiei aplicata pt Passed_year
	for (int i = 1; i < count; i++)
	{
		Movie m = this->p[i];
		int j = i - 1;
		while (j >= 0 && this->p[j].GetPassed_year() < m.GetPassed_year())
		{
			this->p[j + 1] = this->p[j];
			j--;
		}
		if (m.GetPassed_year() != this->p[j + 1].GetPassed_year())
			this->p[j + 1] = m;
	}
}