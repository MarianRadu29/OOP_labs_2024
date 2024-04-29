#include<iostream>
using namespace std;


template <class K, class V>
class Map
{
    struct Pair
    {
        K key;
        V value;
        unsigned int index;
    }*tablou;
    unsigned int size , length;

public:
    Map() :size(1) , length(0) 
    {
        tablou = new Pair[size];
    }
    ~Map()
    {
        delete[] tablou;
        tablou = nullptr;
        size = 0;
        length = 0;
    }
    void Print()
    {
        for (int i = 0; i < length; i++)
            cout << tablou[i].key << ' ' << tablou[i].value << '\n';
    }
    V& operator [](const K& key)
    {
        for (int i = 0; i < length; i++)
            if (tablou[i].key == key) 
                return tablou[i].value;
    
        if (length == size) 
        {
            size *= 2;
            Pair* aux = new Pair[size];
            for (unsigned i = 0; i < length; i++)
                aux[i] = tablou[i];

            delete[] tablou;
            tablou = aux;
        }
        
        tablou[length].key = key;
        tablou[length].index = length;
        length++;

        return tablou[length - 1].value;
    }

    
    Pair* begin()
    {
        return &tablou[0];
    }
    Pair* end()
    {
        return &tablou[length];
    }
    void Set(const K& k, const V& v)
    {
        (*this)[k] = v;
    }
    bool Get(const K& key, const V& value)
    {
        for(unsigned i=0;i<length;i++)
            if (tablou[i].key == key)
            {
                tablou[i].value = value;
                return true;
            }
        return false;
    }
    constexpr unsigned Count() const
    {
        return length;
    }

    void Clear()
    {
        delete[] tablou;
        size = 1;
        length = 0;
        tablou = new Pair[size];
    }
    bool Delete(const K& key)
    {
        for (unsigned i = 0; i < length; i++)
        {
            if (tablou[i].key == key)
            {   
                for (unsigned j = i; j < length - 1; j++)
                {
                    tablou[j] = tablou[j + 1];
                    tablou[j].index = j;
                }
                length--;
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K, V>& map)
    {
        if (length > map.length)
            return false;
        
        for (unsigned i = 0; i < length; i++)
        {
            bool sw = 0;
            for (unsigned j = 0; j < length && sw==0; j++)
            {
                if (tablou[i].key == map.tablou[j].key)
                    sw = 1;
            }
            if (sw == 0)//daca cheie i din this->tablou nu se gaseste in map->tablou atunci se returneaza false
                return false;
        }
        return true;
    }
 
};
int main()
    {
        Map<int, const char*> m;
        m[10] = "C++";
        m[20] = "test";
        m[30] = "Poo";
        for (auto [key, value, index] : m)
        {
            printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
        }

        m[20] = "result";
        /*m.Set(40, "java");
        cout << boolalpha << m.Get(20,"result") << ' ' << m.Get(20, "resulT") << '\n';
        m.Delete(40);
        */

        for (auto [key, value, index] : m)
        {
            printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
        }
       /*
        Map<int, const char*> n;
        n[10] = "1";
        n[20] = "2";
        n[30] = "3";
        n[40] = "4";
        cout << boolalpha << m.Includes(n)<<'\n';
        
        m.Clear();
        cout<<m.Count();
        */
        return 0;
}


//am mai incercat cu un class iterator,cam esuata incercarea =((
/*
class Map
{
    static K* keys;
    static V* values;
    static unsigned length;
    unsigned int size;

public:
    Map():size(1)  
    {   
        length = 0;
       keys = new K[size];
       values = new V[size];
    }
    ~Map()
    {
        delete[] keys;
        delete[] values;
        keys = nullptr;
        values = nullptr;
        size = 0;
        length = 0;
    }
    void Print()
    {
        for (int i = 0; i < length; i++)
            cout << keys[i] << ' ' << values[i] << '\n';
    }
    V& operator [](const K& key)
    {   
        unsigned i;
        for ( i = 0; i < length; i++)
            if (keys[i] == key) 
                return values[i];
    
        if (length == size) 
        {
            size *= 2;
            K* new_keys = new K[size];
            V* new_values = new V[size];
            for ( i = 0; i < length; i++)
                {
                    new_keys[i] = keys[i];
                    new_values[i] = values[i]; 
                }
            delete[] keys;
            delete[] values;
            values = new_values;
            keys = new_keys;
        }
        
        keys[length] = key;
        length++;

        return values[length-1];
    }

    class iterator
    {
        public:
            K key;
            V value;
            unsigned index;
            iterator(K k,V v , unsigned i):key(k) , value(v) , index(i) {}
            iterator(const iterator& copy):key(copy.key),value(copy.value),index(copy.index) {}
            iterator& operator++()
            {
                index++;
                key = keys[index];
                value = values[index];
                return *this;
            }
            
            bool operator!=(const iterator& aux)
            {
                if(index!=aux.index)
                    return true;
                return false;
            }
    };
    
    iterator begin()
    {   
        return iterator(keys[0],values[0],0);
    }
    iterator end()
    {
        return iterator(keys[length],values[length],length);
    }
     

};*/