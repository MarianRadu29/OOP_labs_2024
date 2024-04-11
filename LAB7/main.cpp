#include<iostream>
#include<cstring>
#include"Tree.h"
using namespace std;
float operator"" _Kelvin(unsigned long long a) {
    float value = a - 273.15f;
    return value;
}
float operator"" _Fahrenheit(unsigned long long a) {
    float value = (a - 32) / 1.8f;
    return value;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << " " << b ;


    cout<<"\n\n\n";

    
    Tree<int> copac2(100);
    copac2.add_node(nullptr, 5);//radacina
    copac2.add_node(copac2.GetRoot(), 7);
    copac2.add_node(copac2.GetRoot(), 8);
    Tree<int> copac3(100);
    copac3.add_node(nullptr, 3);//radacina
    copac3.add_node(copac3.GetRoot(), 4);
    copac3.add_node(copac3.GetRoot(), copac2.GetRoot());
    copac3.add_node(copac3.GetRoot(), 6);
    Tree<int> copac(100);
    copac.add_node(nullptr, 1);//radacina
    copac.add_node(copac.GetRoot(), 2);
    copac.add_node(copac.GetRoot(), copac3.GetRoot());
    copac.DFS(copac.GetRoot());
    cout << '\n';
    copac.delete_node(5);
    copac.insert(10, 10);
    Node<int>* nod = new Node<int>;
    nod->nrChildren = 0;
    nod->value = 15;
    copac.insert(2, nod);
    copac.DFS(copac.GetRoot());
    cout << endl << "count: " << copac.count(nullptr);

    cout << "\n\n\n";

    //nu cred ca mai este nevoie de rescrierea clasei pt <char*>,cu rescriere programul are mici erorii
    Tree<char*> Copac2(100);
    Copac2.add_node(nullptr, (char*)"Marian");
    Copac2.add_node(Copac2.GetRoot(), (char*)"mama");
    Copac2.add_node(Copac2.GetRoot(), (char*)"tata");
    Copac2.add_node(Copac2.GetRoot(), (char*)"frate");
    Copac2.add_node(Copac2.GetRoot(), (char*)"sora");
    Copac2.sort(Copac2.GetRoot(), compara);//puteam pune <char*> langa compara
    Copac2.DFS(Copac2.GetRoot());
    cout << endl;
    Copac2.delete_node((char*)"mama");
    Copac2.DFS(Copac2.GetRoot());
    return 0;
}