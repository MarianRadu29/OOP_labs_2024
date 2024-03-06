#include<cstring>
#pragma once
class Movie
{
		char name[256];
		int release_year;
		double IMDB;
		int length_movie;//in minute
		//int passed_year;//cati ani au trecut de la lansarea filmului
	public:
		void set_name(const char s[256]);
		const char* GetName();
		void set_year(int year);
		int GetRelease_year();
		void set_score(double x);
		double GetIMDB();
		void set_length(int x);
		int GetLength_movie();
		int GetPassed_year();
};

