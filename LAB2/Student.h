#include<iostream>
#include<cstring>
class student
{
    char name[50];
    float grade_math;
    float grade_english;
    float grade_history;
    public:
        void SetName( char name[50]);
        void GetName(char s[50]);
        void SetMath(float x);
        float GetMath();
        void SetEnglish(float x);
        float GetEnglish();
        void SetHistory(float x);
        float GetHistory();
        float Average_grade();
};

////////////////////////////////////////////
/*void student::SetName( char name[50])
{
   strcpy(this->name,name);
}
void student::GetName(char s[50])
{
   strcpy(s,this->name);
   //cout<<this->name<<endl;
}
void student::SetMath(float x)
{   if(x>=1.0 && x<=10.0)
        this->grade_math = x;
}
float student::GetMath()
{   
    std::cout<<this->grade_math<<std::endl;
    return this->grade_math;
}
void student::SetEnglish(float x)
{   if(x>=1.0 && x<=10.0)
        this->grade_english = x;
}
float student::GetEnglish()
{
    std::cout<<this->grade_english<<std::endl;
    return this->grade_english;
}
void student::SetHistory(float x)
{   if(x>=1.0 && x<=10.0)
        this->grade_history = x;
}
float student::GetHistory()
{
    std::cout<<grade_history<<std::endl;
    return this->grade_history;
}
float student::Average_grade()
{
    float x = 0 , y=3.0;
    x += this->grade_english;
    x += this->grade_history;
    x += this->grade_math;
    x/=y;
    return x;
}
*/