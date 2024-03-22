#include "Sort.h"
Sort::Sort(int count, int min, int max) : count(count)
{
    srand(time(nullptr));//ca sa nu fie mereu acelasi sir generat
    array = new int[count];
    for (int i = 0; i < count; i++)
        array[i] = min + (rand() % (max - min + 1));

}

Sort::Sort(std::initializer_list<int> x): count(x.size())
{
    array = new int[count];
    int index = 0;
    for (auto i : x)//parcurgem lista x
        array[index++] = i;
}

Sort::Sort(int v[], int count) : count(count)
{
    array = new int[count];
    for (int i = 0; i < count; i++)
        array[i] = v[i];
}

Sort::Sort(const char* string)
{
    int i, k = 0, nr = 0;
    for (i = 0; i < strlen(string); i++)
        if (string[i] == ',')
            count++;
    count++;
    array = new int[count];
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == ',')
        {
            array[k++] = nr;
            nr = 0;
            i++;
        }

        nr = nr * 10 + string[i] - '0';
    }
    array[k] = nr;//k = count-1
}

Sort::Sort(int count, ...) : count(count)
{
    va_list a;
    va_start(a, count);
    array = new int[count];
    for (int i = 0; i < count; i++)
        array[i] = va_arg(a, int);
    va_end(a);
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < count; i++)
    {
        int j = i - 1, element = array[i];
        while (j >= 0 && ((array[j] > element) == ascendent))
            array[j + 1] = array[j--];
        if (array[j + 1] != element)
            array[j + 1] = element;

    }
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if ((array[j] > array[j + 1]) == ascendent)
                std::swap(array[j], array[j + 1]);
}

int Sort::Partition(int l, int r, bool ascendent)
{
    int pivot, pivot_index = rand() % (r - l + 1) + l, i = l - 1, j;
    std::swap(array[pivot_index], array[r]);
    pivot = array[r];
    for (j = l; j < r; j++)
        if ((array[j] <= pivot) == ascendent)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    std::swap(array[i + 1], array[r]);
    return i + 1;
}

void Sort::quicksort(int l, int r, bool ascendent)
{
    if (l < r) {
        int pivot = Partition(l, r, ascendent);
        quicksort(l, pivot - 1, ascendent);
        quicksort(pivot + 1, r, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    quicksort(0, count - 1, ascendent);
}

void Sort::Print()
{
    for (int i = 0; i < count; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int Sort::GetElementsCount() { return count; }

int Sort::GetElementFromIndex(int index) { return array[index]; }
