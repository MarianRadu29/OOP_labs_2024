#include "header.h"
int Sum(int a, int b) { return (a + b); }
int Dif(int a, int b) { return (a - b); }
int Mul(int a, int b) { return (a * b); }
int Div(int a, int b) { return (a / b); }

int main()
{
    char input[38] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[4] = {Sum, Dif, Mul, Div};
    int S=0;
    Content x;
    int idx;
    for (int i = 0; i < strlen(input); i++)
    {   
           // printf("switch: %i \t %i",input[i]-42,i);
        switch (input[i] - 42)
        {
            case INMULTIRE://0
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case SUMA://1
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA://3
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case IMPARTIRE://5
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
        }
       // printf("\t%i\n",S);
        S = S + Operatori[idx]( x.p1 , x.p2);
    }

    //S=337
    printf("S = %i\n", S);

    return 0;
}
