#include"NumberList.h"
#include"FunctionGlobals.h"
int main()
{
    
    cout << endl << "******************************************" << endl;
    cout << "NumberList" << endl;
    NumberList lista;
    lista.Init();
    lista.Add(5);
    lista.Add(6);
    lista.Add(3);
    lista.Add(26);
    std::cout << "NumberList: ";
    lista.Print();
    std::cout << endl;
    lista.Sort();
    cout << "Sorted NumbersList: ";
    lista.Print();

    cout << endl << "******************************************" << endl;
    cout << "Student" << endl;
    student M, N;
    char s[] = "Sebastian", c[] = "Marian";
    M.SetName(s);
    N.SetName(c);
    strcpy_s(s ,M.GetName());
    cout << s << endl;
    strcpy_s(c, N.GetName());
    cout << c << endl;
    M.SetEnglish(5.0);
    M.SetHistory(7.0);
    M.SetMath(10.0);
    N.SetEnglish(5.0);
    N.SetHistory(10.0);
    N.SetMath(10.0);
    cout << s << ".Average: " << M.Average_grade() << endl;
    cout << c << ".Average: " << N.Average_grade() << endl;
    cout << "byName:" << byName(&M, &N) << endl;
    cout << "byMath:" << byMath(&M, &N) << endl;
    cout << "byEnglish:" << byEnglish(&M, &N) << endl;
    cout << "byHistory:" << byHistory(&M, &N) << endl;
    cout << "byAverage:" << byAverage(&M, &N) << endl;
    cout << "******************************************" << endl;
    return 0;
}