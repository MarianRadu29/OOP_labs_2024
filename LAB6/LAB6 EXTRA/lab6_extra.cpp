#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
class JsonValue {
public:
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out,int x) const = 0;
};
JsonValue::~JsonValue() = default;
class NullValue: public JsonValue
{   
    const char* valueNull = nullptr;
    public:
        ~NullValue(){delete valueNull; valueNull = nullptr;}
        void print(std::ostream& out,int x) const {  out<<"null"; }

};
class NumberValue: public JsonValue
{   
    long long int valueNumber;
    public:
        NumberValue(long long int x): valueNumber(x) {}
        ~NumberValue() = default;
        void print(std::ostream& out,int x) const { out<<valueNumber; }
};
class BoolValue: public JsonValue
{   
    bool valueBool;
    public:
        BoolValue(bool x): valueBool(x) {}
        ~BoolValue() = default;
        void print(std::ostream& out,int x) const { out<<std::boolalpha<<valueBool;}

};
class StringValue: public JsonValue
{   
    char valueString[256];
    public:
        StringValue(const char* x)
        {
            if(strlen(x)<256)
                strcpy(valueString,x);
        }
        ~StringValue() = default;
        void print(std::ostream& out,int x) const { out<<'\"'<<valueString<<'\"'; }
};
class ArrayValue:public JsonValue
{
    JsonValue* values[16];
    unsigned int size;
    public: 
        ArrayValue(): size(0) {}
        void add(JsonValue* x)
        {
            if(size==16)
                return;
            values[size++] = x;
        }
        ~ArrayValue() = default;
        void print(std::ostream& out,int x) const
        {
            out<<"[\n";
            for(int i =0;i<size-1;i++)
                {   for(int j = 0;j<x;j++)
                            out<<'\t';
                    values[i]->print(std::cout,x+1);
                    out<<", \n";
                }
            for(int j = 0;j<x;j++)
                out<<'\t';
            values[size-1]->print(std::cout,x+1);
            out<<'\n';
            for(int j = 0;j<x-1;j++)
                out<<'\t';
            out<<']';
        }
};
class ObjectValue:public JsonValue
{
    JsonValue* V[16];
    char* name[16];
    unsigned int size;
    public:
        ObjectValue(): size(0) {}
        ~ObjectValue() = default;
        void add(const char* name , JsonValue* x)
        {   
            if(size==16)
                return;
            this->name[size] = new char[strlen(name)];
            strcpy(this->name[size],name);
            V[size++] = x;
        }

        void print(std::ostream& out,int x) const
        {       
            int i ;
            out<<'{'<<'\n';
            for(i = 0;i<size-1;i++)
                {   
                    for(int j = 0;j<x;j++)
                        out<<'\t';
                    out<<'\"'<<name[i]<<"\": ";
                    V[i]->print(std::cout,x+1);
                    out<<", \n";
                }
            for(int j = 0;j<x;j++)
                out<<'\t';
            out<<"\""<<name[i]<<"\": ";
            V[i]->print(std::cout,x+1);
            out<<"\n";
            for(int j = 0;j<x-1;j++)
                out<<'\t';
            out<<'}';
        }
        operator unsigned() {  return size; }   
        
};
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    std::cout << "Top node has " << (unsigned) *object << " subnodes\n";

    object->print(std::cout,1);//am modificat functia de print ca sa mi afiseze corespunzator JSON-ul
}

