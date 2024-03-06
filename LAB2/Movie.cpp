#include "Movie.h"
void Movie::set_name(const char s[256])
{
	strcpy_s(this->name, s);
}
const char* Movie::GetName()
{
	return this->name;
}
void Movie::set_year(int year)
{
	this->release_year = year;
}
int Movie::GetRelease_year()
{
	return this->release_year;
}
void Movie::set_score(double x)
{
	this->IMDB = x;
}
double Movie::GetIMDB()
{
	return this->IMDB;
}
void Movie::set_length(int x)
{
	this->length_movie = x;
}
int Movie::GetLength_movie()
{
	return this->length_movie;
}
int Movie::GetPassed_year()
{
	return 2024 - this->GetRelease_year();
}
