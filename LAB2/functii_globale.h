#include"Student.h"
#include<iostream>

int byName(student *M , student*N);
int byMath(student *M , student*N);
int byEnglish(student *M , student*N);
int byHistory(student *M , student*N);
int byAverage(student *M , student*N);

//////////////////////////////////////

/*int byName(student *M , student*N)
{   
    char s[50] , c[50];
    M->GetName(s);
    N->GetName(c);
    return strcmp(s,c);

}
int byMath(student *M , student*N)
{
    float m1 , m2;
    m1 = M->GetMath();
    m2 = N->GetMath();
    if(m1==m2)
        return 0;
    else
        if(m1>m2)
            return 1;
        else
            return -1;
}
int byEnglish(student *M , student*N)
{
    float m1 , m2;
    m1 = M->GetEnglish();
    m2 = N->GetEnglish();
    if(m1==m2)
        return 0;
    else
        if(m1>m2)
            return 1;
        else
            return -1;
}
int byHistory(student *M , student*N)
{
    float m1 , m2;
    m1 = M->GetHistory();
    m2 = N->GetHistory();
    if(m1==m2)
        return 0;
    else
        if(m1>m2)
            return 1;
        else
            return -1;
}
int byAverage(student *M , student*N)
{
    float m1 , m2;
    m1 = M->Average_grade();
    m2 = N->Average_grade();
    if(m1==m2)
        return 0;
    else
        if(m1>m2)
            return 1;
        else
            return -1;
}
*/
