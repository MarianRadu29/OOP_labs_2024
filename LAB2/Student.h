#pragma once

#include<iostream>
#include<cstring>
using namespace std;
class student
{
    char name[50];
    float grade_math;
    float grade_english;
    float grade_history;
public:
    void SetName(char name[50]);
    const char* GetName();
    void SetMath(float x);
    float GetMath();
    void SetEnglish(float x);
    float GetEnglish();
    void SetHistory(float x);
    float GetHistory();
    float Average_grade();
};
