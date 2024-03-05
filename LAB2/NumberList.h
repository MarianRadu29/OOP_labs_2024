#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <iostream>

class NumberList {
    int numbers[10];
    int count;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector

};
/////////////////////////
void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x) 
{
    if (count > 9) {
        return 0;
    }
    numbers[count++] = x;
}

void NumberList::Sort() {
    //metoda insertiei
    for(int i = 1;i<count;i++)
        {
            int m = numbers[i];
            int j = i-1;
            while(j>=0 && numbers[j]>m)
                {
                    numbers[j+1] = numbers[j];
                    j--;
                }
            if(numbers[j+1]!=m)
                numbers[j+1] = m;
        }
}

void NumberList::Print() 
{
    for (int i=0;i<count;i++)
        std::cout<<numbers[i]<<" ";
}
#endif // NUMBERLIST_H