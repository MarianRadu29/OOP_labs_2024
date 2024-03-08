#include "NumberList.h"
void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if (count > 9) 
    {
        return 0;
    }
    numbers[count++] = x;
}

void NumberList::Sort() {
    //metoda insertiei
    for (int i = 1; i < count; i++)
    {
        int m = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > m)
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        if (numbers[j + 1] != m)
            numbers[j + 1] = m;
    }
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
        cout << numbers[i] << " ";
}
