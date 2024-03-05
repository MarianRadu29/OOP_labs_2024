#include"NumberList.h"
#include"functii_globale.h"//contine si headerul "Student.h"
int main()
{   
                                                                            //daca pun metodele clasei doar in .cpp nu merge ,eroare: "undefined reference to NumberList::<nume_functie>"
    std::cout<<std::endl<<"******************************************"<<std::endl;
    std::cout << "NumberList"<<std::endl;
    NumberList lista;
    lista.Init();
    lista.Add(5);
    lista.Add(6);
    lista.Add(3);
    lista.Add(26);
    std::cout << "Numbers: ";
    lista.Print();
    std::cout << std::endl;
    lista.Sort();
    std::cout << "Sorted numbers: ";
    lista.Print();

    std::cout<<std::endl<<"******************************************"<<std::endl;

    student M , N;
    char s[]="Sebastian" , c[]="Marian";
    M.SetName(s);
    N.SetName(c);
    M.GetName(s);
    std::cout<<s<<std::endl;
    N.GetName(c);
    std::cout<<c<<std::endl;
    M.SetEnglish(5.0);
    M.SetHistory(7.0);
    M.SetMath(10.0);
    N.SetEnglish(5.0);
    N.SetHistory(10.0);
    N.SetMath(10.0);
    std::cout<<s<<".Average: "<<M.Average_grade()<<std::endl;
    std::cout<<c<<".Average: "<<N.Average_grade()<<std::endl;
    std::cout<<"byName:"<<byName(&M,&N)<<std::endl;
    std::cout<<"byMath:"<<byMath(&M,&N)<<std::endl;
    std::cout<<"byEnglish:"<<byEnglish(&M,&N)<<std::endl;
    std::cout<<"byHistory:"<<byHistory(&M,&N)<<std::endl;
    std::cout<<"byAverage:"<<byAverage(&M,&N)<<std::endl;
    std::cout<<"******************************************"<<std::endl;
    return 0;
}