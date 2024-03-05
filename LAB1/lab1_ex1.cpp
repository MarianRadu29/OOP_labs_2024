#include<stdio.h>
#include<cstring>//pt strlen
int atoi_me(char s[])
{
    int number=0 , i;
    for(i=0; i<strlen(s)-1;i++)
            number = number*10+s[i]-'0';        
    return number;
}
int main()
{   
    FILE* f;
    f = fopen("in.txt", "r");
    int number=0 ;
    char s[10];
    while(fgets(s, sizeof(s), f))
        number += atoi_me(s);
    printf("\n%i",number);
    //daca pe ultimul rand al fisierului nu este un newline(ca pe site),programul nu afiseaza rezultatul dorit
    return 0;
}
