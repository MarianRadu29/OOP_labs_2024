#include "Globals.h"
int movie_compare_name(Movie x, Movie y)
{
	return strcmp(x.GetName() , y.GetName());
}
int movie_compare_year(Movie x, Movie y)
{
	if (x.GetRelease_year() == y.GetRelease_year())
		return 0;
	else
		if (x.GetRelease_year() < y.GetRelease_year())
			return -1;
		else
			return 0;
}
int movie_compare_score(Movie x, Movie y)
{
	if (x.GetIMDB() == y.GetIMDB())
		return 0;
	else
		if (x.GetIMDB() < y.GetIMDB())
			return -1;
		else
			return 0;
}
int movie_compare_length(Movie x, Movie y)
{
	if (x.GetLength_movie() == y.GetLength_movie())
		return 0;
	else
		if (x.GetLength_movie() < y.GetLength_movie())
		return -1;
		else
			return 0;
}
int movie_compare_passed_years(Movie x, Movie y) 
{
	if (x.GetPassed_year() == y.GetPassed_year())
		return 0;
	else
		if(x.GetPassed_year() < y.GetPassed_year())
			return -1;
		else
			return 0;
}
