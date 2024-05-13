#include<iostream>
#include<stdexcept>

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class T_Compare :public Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) override
    {
        T* num1 = (T*)e1;
        T* num2 = (T*)e2;

        if (*num1 < *num2)
            return -1;
        else
            if (*num1 > *num2)
                return 1;
            else
                return 0;
    }
};

template<class T>
int comparare(T p1, T p2)
{
    if (p1 == p2)
        return 0;
    else
        if (p1 > p2)
            return 1;
        else
            return -1;
}

template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator()
    {
        List = nullptr;
        Current = -1;
    }
    ArrayIterator(T** list, int current) :List(list), Current(current) {}
    ArrayIterator& operator ++ ()
    {
        Current++;
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        Current--;
        return *this;
    }
    bool operator= (ArrayIterator<T>& other)
    {
        List = other.List;
        Current = other.Current;
    }
    bool operator!=(ArrayIterator<T> other)
    {
        if (Current != other.Current)
            return true;
        return false;
    }
    T* GetElement()
    {
        return List[Current];
    }
    T& operator*()
    {
        return *List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() : List(nullptr), Capacity(0), Size(0) {} // Lista nu e alocata, Capacity si Size = 0
    ~Array()//destructorul
    {
        delete[] List;
        Capacity = 0;
        Size = 0;
    }
    Array(int capacity) :Capacity(capacity), Size(0)// Lista e alocata cu 'capacity' elemente
    {
        List = new T * [capacity];
    }
    Array(const Array<T>& otherArray) :Capacity(otherArray.Capacity), Size(otherArray.Size) // constructor de copiere
    {
        List = new T * [Capacity];
        for (unsigned i = 0; i < Capacity; i++)
        {
            List[i] = otherArray.List[i];
        }
    }
    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        if (index<0 || index>Size)//sau Capacity,depinde
            throw "Eroare(operator[]): Index-ul este out of range";
        return *List[index];
    }
    Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {//am scos "const" -ul de la tipul metodei,nu mergea (array +=x1) +=x2;
        if (Size == Capacity)//am adaugat o exceptie in plus
            throw "Eroare(operator+=): Array-ul este plin,nu se mai pot adauga elemente";
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index<0 || index>Size)
            throw "Eroare(Insert(int,const T &)): Index-ul este out of range";

        if (Size == Capacity)//daca array ul este plin ,nu mai putem adauga elemente ,orice index am primi
            throw "Eroare(Insert(int,const T &)): Array-ul este plin,nu se mai pot adauga elemente";

        for (unsigned i = Size; i > index; i--)
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {

        if (index<0 || index>Size)
            throw "Eroare(Insert(int,const Array<T>)): Index-ul este out of range";
        if (Size + otherArray.Size > Capacity)
            throw "Eroare(Insert(int,const Array<T>)): Nu se poate face inserarea unui nou Array in Array-ul curent(depasire Capacity)";

        for (unsigned i = Size + otherArray.Size - 1; i > index + otherArray.Size - 1; i--)//ex din this.list = {1,2,3,-,-,-,-},index=1  otherarray={4,5,6} this.list va fi {1,-,-,-,2,3}
            List[i] = List[i - otherArray.Size];

        for (unsigned i = 0; i < otherArray.Size; i++)
            List[i + index] = otherArray.List[i];

        Size += otherArray.Size;
        return *this;

    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index<0 || index>Size)
            throw "Eroare(Delete(int)): Index-ul este out of range";
        for (unsigned i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;
    }
    bool operator=(const Array<T>& otherArray)//presupun ca trebuie sa verific daca elementele coincid in ambele obiecte
    {
        if (Size != otherArray.Size)/*|| Capacity!=otherArray.Capacity*/  //testul de la capacity e optional
            return false;

        for (unsigned i = 0; i < Size; i++)
            if (List[i] != otherArray.List[i])
                return false;

        return true;

    }
    //sau pot sa asignez obiectului meu obiectul dat ca parametru(asemanator cu constructorul de copiere) si sa returnez true
    /*bool operator=(const Array<T> &otherArray)
    {
        delete[] List;
        List = new T*[otherArray.Capacity];
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        for(unsigned i=0;i<Size;i++)
            List[i] = otherArray.List[i];

        return true;
    }
    */
    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        for (unsigned i = 0; i < Size - 1; i++)
            for (unsigned j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    std::swap(List[i], List[j]);
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        unsigned i, j;
        for (i = 0; i < Size - 1; i++)
            for (j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                    std::swap(List[i], List[j]);
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        unsigned i, j;
        for (i = 0; i < Size - 1; i++)
            for (j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    std::swap(List[i], List[j]);
    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        bool sw = true;
        for (unsigned i = 0; i < Size - 1 && sw == true; i++)
            if (*List[i] > *List[i + 1])
                sw = false;
        if (sw == false)
        {
            throw "Eroare(BinarySearch(const T&)): Lista nu este ordonata crescator";
            //return -1;
        }
        int left = 0;
        int right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (*List[mid] == elem)
                return mid;
            else
                if (*List[mid] < elem)
                    left = mid + 1;
                else
                    right = mid - 1;

        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        bool sw = true;
        for (unsigned i = 0; i < Size - 1 && sw == true; i++)
            if (*List[i] > *List[i + 1])
                sw = false;
        if (sw == false)
        {
            throw "Eroare(BinarySearch(const T&, int(*compare)(const T&, const T&))): Lista nu este ordonata crescator";
            //return -1;
        }
        int left = 0;
        int right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (compare(*List[mid], elem) == 0)
                return mid;
            else
                if (compare(*List[mid], elem) == -1)
                    left = mid + 1;
                else
                    right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        bool sw = true;
        for (unsigned i = 0; i < Size - 1 && sw == true; i++)
            if (*List[i] > *List[i + 1])
                sw = false;
        if (sw == false)
        {
            throw "Eroare(BinarySearch(const T&, Compare*))): Lista nu este ordonata crescator";
            //return -1;
        }
        int left = 0;
        int right = Size - 1;
        T aux = elem;
        T* ptr_elem = &aux;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (comparator->CompareElements(List[mid], ptr_elem) == 0)
                return mid;
            else
                if (comparator->CompareElements(List[mid], ptr_elem) == -1)
                    left = mid + 1;
                else
                    right = mid - 1;

        }
        return -1;
    }
    int Find(const T& elem) // cauta un element in Array
    {
        for (unsigned i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (unsigned i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        T aux = elem;
        T* ptr_elem = &aux;
        for (unsigned i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], ptr_elem) == 0)
                return i;
        return -1;
    }
    int GetSize() const { return Size; }
    int GetCapacity() const { return Capacity; }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }
    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size);
    }
    /////////////////////////////////////////
    //pentru foreach
    ArrayIterator<T>& begin()
    {
        ArrayIterator<T>* a = new ArrayIterator<T>(List, 0);
        return *a;
    }
    ArrayIterator<T>& end()
    {
        ArrayIterator<T>* a = new ArrayIterator<T>(List, Size);
        return *a;
    }

    void Print()
    {
        for (unsigned i = 0; i < Size; i++)
            std::cout << *List[i] << ' ';
        std::cout << '\n';
    }
};

int main()
{
    std::cout << "---------------------------------------------------------\n";
    Array<int> array(5);
    int x1 = 1;
    int x2 = 2;
    int x3 = 3;

    (array += x2) += x3;
    array.Insert(0, x1);
    std::cout << "array: ";
    array.Print();
    std::cout << "---------------------------------------------------------\n";
    Array<int> array1(5);
    int y1 = 1;
    int y2 = 2;
    int y3 = 3;
    ((array1 += y1) += y2) += y3;
    try //am folosit la toate exceptiile logic_error deoarece majoritatea aveau exceptii out_of_range sau invalid_argument(vectorul/lista nu este sortata)
    {
        array.Insert(0, array1);
    }
    catch (const char* mesaj)//daca la "array" schimbam valoarea la apelul constructorului cu una >=6 nu se arunca exceptie
    {
        std::cout << '\n' << mesaj << "\n\n";
    }
    std::cout << "array: ";
    array.Print();
    std::cout << "---------------------------------------------------------\n";
    std::cout << "array[0] = " << array[0] << '\n';
    std::cout << "---------------------------------------------------------\n";

    array.Delete(2);
    std::cout << "array: ";
    array.Print();
    std::cout << "---------------------------------------------------------\n";

    Array<int> ARRAY(10);
    ((((ARRAY += 10) += 2) += 7) += 9) += 5;
    // std::cout << ARRAY.GetSize() << '\n';

    ARRAY.Sort(new T_Compare<int>);
    std::cout << "ARRAY: ";
    ARRAY.Print();
    std::cout << "---------------------------------------------------------\n";

    //la binary search trebuie sa fie sortat array ul;
    std::cout << "Pozitia in care se afla 2 in ARRAY este " << ARRAY.BinarySearch(2, new T_Compare<int>) << '\n';
    std::cout << "Pozitia in care se afla 5 in ARRAY este " << ARRAY.Find(5, new T_Compare<int>) << '\n';
    std::cout << "ARRAY: ";
    ARRAY.Print();
    std::cout << "---------------------------------------------------------\n";
    ArrayIterator<int> it = ARRAY.GetBeginIterator();
    // std::cout << *it.GetElement();
    std::cout << "ARRAY(parcurgere iterator): ";
    for (; it != ARRAY.GetEndIterator(); ++it)
        std::cout << *it.GetElement() << ' ';
    std::cout << "\n---------------------------------------------------------\n";
    //foreach
    for (auto& it : ARRAY)
        std::cout << it++ << ' ';
    std::cout << '\n';
    for (auto it : ARRAY)
        std::cout << it << ' ';
    std::cout << "\n---------------------------------------------------------\n";


    return 0;
}