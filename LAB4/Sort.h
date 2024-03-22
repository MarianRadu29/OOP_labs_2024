#pragma once
#include <iostream>
#include <cstring>
#include <list>
#include <varargs.h>
#include <ctime>
#include<list>
class Sort
{
private:
    int* array;
    int count;

    int Partition(int, int, bool);
    void quicksort(int, int, bool);
public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> x);
    Sort(int v[], int count);
    Sort(const char* text);
    Sort(int count, ...);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
