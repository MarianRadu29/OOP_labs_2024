#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int atoi_me(char s[])
{
    int number=0,i;
    for(i=0; i<strlen(s);i++)
        number = number*10+s[i]-'0';
    return number;
}
void problema_1()
{   
    //ifstream fopen("in.txt");
    FILE* f;
    f = fopen("in.txt", "r");
    int number=0 , n;
    char s[10];
    while(fgets(s, sizeof(s), f))
    {
        n = atoi_me(s);
        number += n;
    }
    printf("%i",number);
}


struct cuvant
{
    char c[100];
    int size;
};
void problema_2()
{
    cuvant C[100];
    char s[256] , *p;
    strcpy(s,"");
    printf("Enter a phrase: ");
    scanf("%[^\n]s",s);//!!
    p = strtok(s," ");
    //printf("%s\n",p);
    int count = 0;
    //cout<<"da"<<endl;
    while(p!=NULL)
    {   
        strcpy(C[count].c,p);
        C[count++].size = strlen(p);
        p = strtok(NULL," ");
    }
    int i , j;
    for(i=0;i<count;i++)
        for(j=i+1;j<=count;j++)
            {
                if(C[i].size<C[j].size)
                {
                    cuvant aux;
                    aux = C[i];
                    C[i] = C[j];
                    C[j] = aux;
                }
                if(C[i].size == C[j].size)
                    {
                        int k=0;
                        while(C[i].c[k] == C[j].c[k] && k<C[i].size)
                            k++;
                        if(C[i].c[k] < C[j].c[k] && k<C[i].size)
                            {
                                cuvant aux;
                                aux = C[i];
                                C[i] = C[j];
                                C[j] = aux;
                            }
                    }
            }
    for(int i = 0;i<=count;i++)
        printf("%s\n",C[i].c);
        
}


bool isPrime(int n)
{   
    if(n<2)
        return false;
        //ce este mai sus reprezinta conditie suplimentara la numar prim fata de ce e pe site
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr ) == 0)
            return false;
    return true;
}
void problema_3()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    if (isPrime(n))
        cout << n << " is prime !";
    else 
        cout << n << " is NOT prime !";

}
int main()
{
    //problema_1();
    problema_2();
    //problema_3();
    return 0;
}