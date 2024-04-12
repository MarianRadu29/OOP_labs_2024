#include<iostream>
#include"Vector.h"
int main() {
    Vector<int> v;

    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);
    v.insert(0, 30);
    std::cout << "Print v: ";
    v.print();
    std::cout << '\n';

    Vector<int> w = v;
    
    for (unsigned i = 0; i < v.GetLength(); i++)
        printf("v[%d] = %p \t w[%d] = %p\n",i,&v[i],i,&w[i]);
    std::cout << '\n';
    
    v.remove(0);
    v.sort(compara);
    printf("w[0] = %d\n\n", w[0]);

    std::cout << "Print v: ";
    v.print();
}
