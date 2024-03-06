#pragma once
#include"Movie.h"
class MovieSeries
{
	Movie p[16];
	int count;
public:
	void init();
	bool add(Movie *x);
	void print();
	void sort();
};
