#include "FunctionGlobals.h"
int byName(student* M, student* N)
{
    return strcmp(M->GetName(), N->GetName());
}
int byMath(student* M, student* N)
{
    float m1, m2;
    m1 = M->GetMath();
    m2 = N->GetMath();
    if (m1 == m2)
        return 0;
    else
        if (m1 > m2)
            return 1;
        else
            return -1;
}
int byEnglish(student* M , student* N)
{
    float m1, m2;
    m1 = M->GetEnglish();
    m2 = N->GetEnglish();
    if (m1 == m2)
        return 0;
    else
        if (m1 > m2)
            return 1;
        else
            return -1;
}
int byHistory(student* M, student* N)
{
    float m1, m2;
    m1 = M->GetHistory();
    m2 = N->GetHistory();
    if (m1 == m2)
        return 0;
    else
        if (m1 > m2)
            return 1;
        else
            return -1;
}
int byAverage(student* M, student* N)
{
    float m1, m2;
    m1 = M->Average_grade();
    m2 = N->Average_grade();
    if (m1 == m2)
        return 0;
    else
        if (m1 > m2)
            return 1;
        else
            return -1;
}
