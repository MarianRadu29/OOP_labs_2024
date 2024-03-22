#include"Sort.h"
using namespace std;
/*
struct nod
{
    int info;
    nod* urm;
};
struct Listaa
{
    nod* prim;
    nod* curent;
    int nrElemente;
};
void initializare(Listaa& lista)
{
    lista.prim = NULL;
    lista.nrElemente = 0;
}
void inserare(Listaa& l, int val, int poz = 0)
{
    if (poz == 0 || l.nrElemente == 0)
    {
        nod* k = new nod;
        l.nrElemente++;
        k->info = val;
        k->urm = l.prim;
        l.prim = k;
    }
    else
    {
        l.nrElemente++;
        l.curent = l.prim;
        for (int i = 0; i < poz - 1 && l.curent->urm != NULL; i++)
            l.curent = l.curent->urm;
        nod* p = new nod;
        p->info = val;
        p->urm = l.curent->urm;
        l.curent->urm = p;

    }
}
int eliminare(Listaa& l, int poz = 0)
{
    int nr = 0;
    if (poz == 1)
    {
        nr = l.prim->info;
        l.prim = l.prim->urm;
    }
    else
    {
        l.curent = l.prim;
        for (int i = 0; i < poz - 1 && l.curent->urm != NULL; i++)
            l.curent = l.curent->urm;
        nod* p = new nod;
        p = l.curent->urm;
        nr = p->info;
        p = p->urm;
        l.curent->urm = p;
    }
    //l.prim=l.curent;
    l.nrElemente--;

    return nr;
}
void afisare(Listaa l)
{
    nod* p = l.prim;
    int i;
    for (i = 0; i < l.nrElemente; i++)
    {
        cout << p->info << ' ';
        p = p->urm;
    }
    cout << endl;
}




Sort::Sort(Listaa& x) : count(x.nrElemente)
{
    array = new int[x.nrElemente];
    int index = 0;
    nod* a = x.prim;
    for (int i = 0; i < x.nrElemente; i++)//daca fac while(a!=null) programul crapa
    {
        array[index++] = a->info;
        a = a->urm;
    }
}

*/
//am incercat sa fac cu lista simplu inlantuita,daca pun tot codul pe main.cpp merge,cand le despart in headere si .cpp uri programul nu merge

int main()
{
    //daca la functia de sortare nu se pune true ca parametru,sortarea va fii in ordine descrescatoare
    Sort s1(12, 1, 29);//in lista vor fii 12 valori intre 1 si 29 [min,max]
    s1.Print();
    s1.InsertSort(true);//crescator
    s1.Print();
    cout << endl;

    /*Listaa a;//am implementat manual o lista simplu inlantuita
    initializare(a);
    inserare(a, 7);
    inserare(a, 8);
    inserare(a, 1);
    inserare(a, 10);
    inserare(a, 29);
    inserare(a, 18);
    inserare(a, 20);
    Sort s2(a);
    */
    Sort s2({ 7,8,1,10,4,10,29,18,20 });
    s2.Print();
    cout << s2.GetElementsCount() << " este numarul de elemente al listei ce apartine clasei \"Sort\"" << endl;
    s2.QuickSort(false);//descrescator
    s2.Print();
    cout << endl;

    char v[] = "5,4,3,2,1";
    Sort s3(v);
    s3.Print();
    s3.BubbleSort(true);//crescator
    s3.Print();
    cout << endl;

    int x[] = { 11,7,5,14,19,23,29 };
    Sort s4(x, 7);
    s4.Print();
    cout << "Elementul de pe pozitia 4 este " << s4.GetElementFromIndex(4) << endl;
    s4.InsertSort();//descrescator
    s4.Print();
    cout << endl;

    Sort s5(6, 11, 22, 54, 23, 45, 35);
    s5.Print();
    s5.QuickSort(true);//am pus true ca sa l sorteze crescator
    s5.Print();
    cout << endl;
    return 0;
}