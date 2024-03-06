#include"Student.h"

void student::SetName(char name[50])
{
    strcpy_s(this->name, name);
}
const char* student::GetName(){
    return this->name;
}
void student::SetMath(float x)
{
    if (x >= 1.0 && x <= 10.0)
        this->grade_math = x;
}
float student::GetMath()
{
  
    return this->grade_math;
}
void student::SetEnglish(float x)
{
    if (x >= 1.0 && x <= 10.0)
        this->grade_english = x;
}
float student::GetEnglish()
{
    return this->grade_english;
}
void student::SetHistory(float x)
{
    if (x >= 1.0 && x <= 10.0)
        this->grade_history = x;
}
float student::GetHistory()
{
    return this->grade_history;
}
float student::Average_grade()
{
    float x = 0, y = 3.0;
    x += this->grade_english;
    x += this->grade_history;
    x += this->grade_math;
    x /= y;
    return x;
}