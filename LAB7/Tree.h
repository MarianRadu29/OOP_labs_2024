#pragma once
#include<iostream>
#include<cstring>
//functia de comparare pt sortare noduri copii directii
template<typename T>
int compara(T firstValue, T secondValue)
{
    if (firstValue < secondValue)
        return -1;
    else
        if (firstValue > secondValue)
            return 1;
        else
            return 0;
}
template<>
int compara<char*>(char* s1, char* s2)
{
    return strcmp(s1, s2);
}

template<typename T>
struct Node//definitia unui nod din arbore
{
    T value;//informatia retinuta de arbore
    Node<T>** children;//alocam de parcurs
    unsigned int nrChildren;//retinem nr copii,sa nu ne ducam unde nu trebuie in memorie
};

template<class T>
class Tree
{
    Node<T>* root;//radacina
    unsigned int MaxChildrenPerNode;//cati copii alocam cand alocam un nod nou
    unsigned DFS_count(Node<T>* nod)
    {
        unsigned nr = 0;
        if (nod == nullptr)
            return nr;
        for (unsigned i = 0; i < nod->nrChildren; i++)
            nr += 1 + DFS_count(nod->children[i]);
        return nr;
    }
    void _delete(Node<T>* nod)
    {
        if (nod->nrChildren == 0)
        {
            delete[] nod->children;
            nod->children = nullptr;
            delete nod;
            nod = nullptr;
        }
        else
            for (unsigned i = 0; i < nod->nrChildren; i++)
                _delete(nod->children[i]);
    }
    Node<T>* cautare_nod(Node<T>* parinte, T value, int (*comparatie)(T, T))//trebuie returnat nodul tata al celui cautat!!
    {
        if (comparatie(parinte->value, value) == 0 || parinte == nullptr)
            return parinte;

        for (unsigned i = 0; i < parinte->nrChildren; i++)
        {
            if (comparatie(parinte->children[i]->value, value) == 0)
            {   //std::std::cout<<endl<<parinte->value<<endl;
                return parinte;
            }
            Node<T>* papa = cautare_nod(parinte->children[i], value, comparatie);
            if (papa != nullptr)
                return papa;
        }
        return nullptr;
    }
public:
    Tree(unsigned int nrChildren)
    {
        MaxChildrenPerNode = nrChildren;//cati fii am maxim pe un nod
        root = nullptr;
    }

    void add_node(Node<T>* parent, T value)//functia primeste un pointer la un parinte
    {
        if (parent == nullptr)//inseamna ca arborele este null si trebuie alocat
        {
            root = new Node<T>;
            root->value = value;
            root->nrChildren = 0;
            root->children = new Node<T>*[MaxChildrenPerNode] {};//daca punem acoladele vectorul de noduri o sa ia tot valoarea "nullptr"
        }
        else
        {
            parent->children[parent->nrChildren] = new Node<T>;
            parent->children[parent->nrChildren]->value = value;
            parent->children[parent->nrChildren]->nrChildren = 0;
            parent->children[parent->nrChildren]->children = new Node<T>*[MaxChildrenPerNode] {};
            parent->nrChildren++;
        }
    }
    void add_node(Node<T>* parent, Node<T>* nod)//chiar daca nod ==nullptr o sa fie creat un nod cu valoarea 0;
    {
        if (parent == nullptr)//inseamna ca arborele este null si trebuie alocat
        {
            root = new Node<T>;
            if (nod != nullptr)
                root->value = nod->value;
            else
                root->value = 0;
            root->nrChildren = 0;
            root->children = new Node<T>*[MaxChildrenPerNode] {};//daca punem acoladele vectorul de noduri o sa ia tot valoarea "nullptr"
        }
        else
        {
            parent->children[parent->nrChildren] = new Node<T>;
            if (nod != nullptr)
                parent->children[parent->nrChildren] = nod;
            else
            {
                parent->children[parent->nrChildren]->value = 0;
                parent->children[parent->nrChildren]->nrChildren = 0;
                parent->children[parent->nrChildren]->children = new Node<T>*[MaxChildrenPerNode] {};
            }
            parent->nrChildren++;
        }
    }
    void printNodes(Node<T>* parinte)
    {
        for (unsigned int i = 0; i < parinte->nrChildren; i++)
            std::cout << parinte->children[i]->value << ' ';
    }
    void sort(Node<T>* parinte, int (*comparatie)(T, T))/*pointerul la functie!!! , returneaza int si ia ca parametrii T si T*/
    {
        unsigned int i, j;
        for (i = 0; i < parinte->nrChildren - 1; i++)
            for (j = i + 1; j < parinte->nrChildren; j++)
                if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)//am interschimbat nodurile, nu valorile
                {
                    Node<T>* aux;
                    aux = parinte->children[i];
                    parinte->children[i] = parinte->children[j];
                    parinte->children[j] = aux;
                }
    }
    Node<T>* get_node(Node<T>* parinte, unsigned index)
    {
        if (parinte == nullptr || index >= root->nrChildren)
            return root;
        else
            return root->children[index];
    }
    void DFS(Node<T>* nod)
    {
        if (nod == nullptr)
            return;
        std::cout << nod->value << ' ';
        for (unsigned i = 0; i < nod->nrChildren; i++)
            DFS(nod->children[i]);
    }
    void delete_node(T value)
    {
        if (root == nullptr)
            return;
        if (root->value == value)
        {
            _delete(root);
            root = nullptr;
        }
        else
        {
            Node<T>* aux = cautare_nod(root, value, compara);//in aux am nodul tata care are fiu cu eticheta value,altfel are nullptr
            if (aux == nullptr)//nu am gasit nod cu valoarea egala cu value
                return;

            for (unsigned i = 0; i < aux->nrChildren; i++)
            {   //std::cout<<aux->children[i]->value<<endl; 
                if (aux->children[i]->value == value)
                {
                    Node<T>* aux1 = aux->children[i];
                    for (unsigned j = i; j < aux->nrChildren - 1; j++)
                        aux->children[j] = aux->children[j + 1];
                    aux->children[aux->nrChildren] = aux1;
                    _delete(aux->children[aux->nrChildren]);
                    aux->children[root->nrChildren] = nullptr;
                    aux->nrChildren--;
                    break;
                }
            }
        }
    }
    Node<T>* find(T value, int (*comparatie)(T, T))
    {
        Node<T>* papa = cautare_nod(root, value, comparatie);
        if (papa == nullptr)
            return papa;
        for (unsigned i = 0; i < papa->nrChildren; i++)
            if (comparatie(papa->children[i]->value, value) == 0)
                return papa->children[i];
    }
    void insert(int index, Node<T>* nod)
    {
        if (root->nrChildren <= MaxChildrenPerNode)
        {
            if (index < 0)
                index = 0;
            if (index >= root->nrChildren)
                index = root->nrChildren;
            unsigned i;
            for (i = root->nrChildren; i > index; i--)
                root->children[i] = root->children[i - 1];
            root->children[i] = nod;
            root->nrChildren++;
        }
    }
    void insert(int index, T value)
    {

        if (root->nrChildren <= MaxChildrenPerNode)
        {
            if (index < 0)
                index = 0;
            if (index >= root->nrChildren)
                index = root->nrChildren;
            unsigned i;
            for (i = root->nrChildren; i > index; i--)
                root->children[i] = root->children[i - 1];
            Node<T>* aux = new Node<T>;
            aux->children = new Node<T>*[MaxChildrenPerNode];
            aux->nrChildren = 0;
            aux->value = value;
            root->children[i] = aux;
            root->nrChildren++;
        }
    }
    unsigned count(Node<T>* nod)
    {
        if (nod == nullptr)
            return DFS_count(root);
        else
            return DFS_count(nod);
    }
    Node<T>* GetRoot()
    {
        return root;
    }

};
/*
template<>
class Tree<char*>
{
    Node<char*>* root;//radacina
    unsigned int MaxChildrenPerNode;//cati copii alocam cand alocam un nod nou
    unsigned DFS_count(Node<char*>* nod)
    {
        unsigned nr = 0;
        if (nod == nullptr)
            return nr;
        for (unsigned i = 0; i < nod->nrChildren; i++)
            nr += 1 + DFS_count(nod->children[i]);
        return nr;
    }
    void _delete(Node<char*>* nod)
    {
        if (nod->nrChildren == 0)
        {
            delete[] nod->value;
            delete[] nod->children;
            nod->children = nullptr;
            delete nod;
            nod = nullptr;
        }
        else
            for (unsigned i = 0; i < nod->nrChildren; i++)
                _delete(nod->children[i]);
    }
    Node<char*>* cautare_nod(Node<char*>* parinte, char* value, int (*comparatie)(char*, char*))//trebuie returnat nodul tata al celui cautat!!
    {
        if (comparatie(parinte->value, value) == 0 || parinte == nullptr)
            return parinte;

        for (unsigned i = 0; i < parinte->nrChildren; i++)
        {
            if (strcmp(parinte->children[i]->value, value) == 0)//functia de comparatie nu merge
            {   //std::cout<<endl<<parinte->value<<endl;
                return parinte;
            }
            Node<char*>* papa = cautare_nod(parinte->children[i], value, comparatie);
            if (papa != nullptr)
                return papa;
        }
        return nullptr;
    }
public:
    Tree(unsigned int nrChildren)
    {
        MaxChildrenPerNode = nrChildren;//cati fii am maxim pe un nod
        root = nullptr;
    }
    void add_node(Node<char*>* parent, const char* value)//functia primeste un pointer la un parinte
    {
        if (parent == nullptr)//inseamna ca arborele este null si trebuie alocat
        {
            root = new Node<char*>;
            root->value = new char[strlen(value)];
            strcpy(root->value, value);
            root->nrChildren = 0;
            root->children = new Node<char*>*[MaxChildrenPerNode] {};//daca punem acoladele vectorul de noduri o sa ia tot valoarea "nullptr"
        }
        else
        {
            parent->children[parent->nrChildren] = new Node<char*>;
            parent->children[parent->nrChildren]->value = new char[strlen(value)];
            strcpy(parent->children[parent->nrChildren]->value, value);
            parent->children[parent->nrChildren]->nrChildren = 0;
            parent->children[parent->nrChildren]->children = new Node<char*>*[MaxChildrenPerNode] {};
            parent->nrChildren++;
        }
    }
    void add_node(Node<char*>* parent, Node<char*>* nod)//chiar daca nod ==nullptr o sa fie creat un nod cu valoarea 0;
    {
        if (parent == nullptr)//inseamna ca arborele este null si trebuie alocat
        {
            root = new Node<char*>;
            if (nod != nullptr)
                strcpy(root->value, nod->value);
            else
                root->value = 0;
            root->nrChildren = 0;
            root->children = new Node<char*>*[MaxChildrenPerNode] {};//daca punem acoladele vectorul de noduri o sa ia tot valoarea "nullptr"
        }
        else
        {
            parent->children[parent->nrChildren] = new Node<char*>;
            if (nod != nullptr)
                parent->children[parent->nrChildren] = nod;
            else
            {
                parent->children[parent->nrChildren]->value = new char[1];
                parent->children[parent->nrChildren]->value[0] = ' ';
                parent->children[parent->nrChildren]->nrChildren = 0;
                parent->children[parent->nrChildren]->children = new Node<char*>*[MaxChildrenPerNode] {};
            }
            parent->nrChildren++;
        }
    }
    void printNodes(Node<char*>* parinte)
    {
        unsigned int i;
        for (i = 0; i < parinte->nrChildren; i++)
            std::cout << parinte->children[i]->value << ' ';
    }
    void sort(Node<char*>* parinte, int (*comparatie)(char*, char*))
    {
        unsigned int i, j;
        for (i = 0; i < parinte->nrChildren - 1; i++)
            for (j = i + 1; j < parinte->nrChildren; j++)
            {
                if (strcmp(parinte->children[i]->value, parinte->children[j]->value) > 0)
                {
                    char* aux;
                    aux = parinte->children[i]->value;
                    parinte->children[i]->value = parinte->children[j]->value;
                    parinte->children[j]->value = aux;
                }
            }
    }
    Node<char*>* get_node(Node<char*>* parinte, unsigned index)
    {
        if (parinte == nullptr || index >= root->nrChildren)
            return root;
        else
            return root->children[index];
    }
    void DFS(Node<char*>* nod)
    {
        if (nod == nullptr)
            return;
        std::cout << nod->value << ' ';
        for (unsigned i = 0; i < nod->nrChildren; i++)
            DFS(nod->children[i]);
    }
    void delete_node(char* value)
    {
        if (root == nullptr)
            return;
        if (strcmp(root->value, value) == 0)
        {
            _delete(root);
            root = nullptr;
        }
        else
        {
            Node<char*>* aux = cautare_nod(root, value, compara);//in aux am nodul tata care are fiu cu eticheta value,altfel are nullptr
            if (aux == nullptr)//nu am gasit nod cu valoarea egala cu value
                return;
            for (unsigned i = 0; i < aux->nrChildren; i++)
            {   //std::cout<<aux->children[i]->value<<endl;
                if (strcmp(aux->children[i]->value, value) == 0)
                {
                    Node<char*>* aux1 = aux->children[i];
                    for (unsigned j = i; j < aux->nrChildren - 1; j++)
                        aux->children[j] = aux->children[j + 1];
                    aux->children[aux->nrChildren] = aux1;
                    _delete(aux->children[aux->nrChildren]);
                    aux->children[root->nrChildren] = nullptr;
                    aux->nrChildren--;
                    break;
                }
            }
        }
    }
    Node<char*>* find(char* value, int (*comparatie)(char*, char*))
    {
        Node<char*>* papa = cautare_nod(root, value, comparatie);
        if (papa == nullptr)
            return papa;
        for (unsigned i = 0; i < papa->nrChildren; i++)
            if (comparatie(papa->children[i]->value, value) == 0)
                return papa->children[i];
    }
    void insert(int index, Node<char*>* nod)
    {
        if (root->nrChildren <= MaxChildrenPerNode)
        {
            if (index < 0)
                index = 0;
            if (index >= root->nrChildren)
                index = root->nrChildren;
            unsigned i;
            for (i = root->nrChildren; i > index; i--)
                root->children[i] = root->children[i - 1];
            root->children[i] = nod;
            root->nrChildren++;
        }
    }
    void insert(int index, char* value)
    {

        if (root->nrChildren <= MaxChildrenPerNode)
        {
            if (index < 0)
                index = 0;
            if (index >= root->nrChildren)
                index = root->nrChildren;
            unsigned i;
            for (i = root->nrChildren; i > index; i--)
                root->children[i] = root->children[i - 1];
            Node<char*>* aux = new Node<char*>;
            aux->children = new Node<char*>*[MaxChildrenPerNode];
            aux->nrChildren = 0;
            strcpy(aux->value, value);
            root->children[i] = aux;
            root->nrChildren++;
        }
    }
    unsigned count(Node<char*>* nod)
    {
        if (nod == nullptr)
            return DFS_count(root);
        else
            return DFS_count(nod);
    }
    Node<char*>* GetRoot()
    {
        return root;
    }
};
*/