#include<iostream>
using namespace std;
bool isPrime(int n)
{   
    if(n<2)
        return false;
        //ce este mai sus reprezinta conditie suplimentara la numar prim fata de ce e pe site
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr ) == 0)
            return false;
    return true;
}
void problema_3()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    if (isPrime(n))
        cout << n << " is prime !";
    else 
        cout << n << " is NOT prime !";

}