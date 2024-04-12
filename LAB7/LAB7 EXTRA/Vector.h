#include<iostream>
template<typename T>

bool compara(T t1, T t2)
{
    return t1 < t2;
}

template<class T, int size_Vector = 100>
class Vector
{
    T* array;
    int length;
    int size_array;
public:
    Vector() :length(0), size_array(size_Vector)
    {
        array = new T[size_array];
    }
    ~Vector()
    {
        delete[] array;
        length = 0;
        size_array = 0;
    }
    Vector(const Vector<T>& aux)//constructor de copiere
    {
        size_array = aux.size_array;
        length = aux.length;
        array = new T[size_array];
        for (unsigned i = 0; i < length; i++)
            array[i] = aux.array[i];
    }
    void insert(int index, T element)
    {
        unsigned i;
        if (length == size_array)
        {
            size_array = size_array * 2;
            T* newarray = new T[size_array];
            for (i = 0; i < length; i++)
                newarray[i] = array[i];
            delete[] array;
            array = newarray;
        }

        if (index<0 || index>length)
            return;

        for (i = length; i > index; i--)
            array[i] = array[i - 1];

        array[index] = element;
        length++;
    }

    void remove(int index)
    {
        unsigned i;

        if (index < 0 || index >= length)
            return;

        for (i = index; i < length - 1; i++)
            array[i] = array[i + 1];

        length--;
    }

    void sort(bool (*comparatie)(T, T))
    {
        unsigned i, j;
        for (i = 0; i < length - 1; i++)
            for (j = i + 1; j < length; j++)
                if (comparatie(array[i], array[j]) == 0)
                {
                    T aux = array[i];
                    array[i] = array[j];
                    array[j] = aux;
                }
    }
    void print()
    {
        for (unsigned i = 0; i < length; i++)
            std::cout << array[i] << ' ';
        std::cout << '\n';
    }
    T& operator[](int index) const
    {
        return array[index];
    }
    int GetLength()
    {
        return length;
    }
};
