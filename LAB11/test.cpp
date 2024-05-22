#include "pch.h"
#include<iostream>


template<typename T,typename V>
bool istrue(std::pair<T, V> p1, std::pair<T,V> p2)
{	

	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}
TEST(TestSortare, TestElementeSortate)//primul parametru,colectia de teste,al doilea parametru este testul specific
{
	std::vector<std::pair<int, std::string>> vector = { {10,"Marian"} , {8,"David"} , {7,"CR7"} , {10,"Matei"} , {1,"Ana"} , {9 ,"Cristina"} , {5,"Albert"} , {6,"Bianca"} , {6,"Mario"} , {7,"PENDU"} , {3,"KAKA"}  , {5,"Pessi"} };
	sort<int,std::string>(vector);
	for (int i = 0; i < vector.size()-1; i++)
	{	
		//doar afisez ce trebuie testat in EXPECT,sa observ in ce caz a picat sortarea
		std::cout <<"\nvector["<<i<<"] = { "<<vector[i].first<<" , \""<<vector[i].second<<"\" }\n";
		std::cout << "vector[" << i+1 << "] = { " << vector[i+1].first << " , \"" << vector[i+1].second << "\" }\n\n";
		
		EXPECT_TRUE(istrue(vector[i], vector[i + 1]));//cu EXPECT codul ruleaza pana la final,ASSERT inchide programul la primul fail	
	}

	//for (std::pair<int, std::string> it : vector)
		//std::cout << it.first << ' ' << it.second << '\n';
	
	/*
	*rezultatul corect
	10 Marian
	10 Matei
	9 Cristina
	8 David
	7 CR7
	7 PENDU
	6 Bianca
	6 Mario
	5 Albert
	5 Pessi
	3 KAKA
	1 Ana
	*/
}
