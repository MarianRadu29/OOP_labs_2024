#include<stdio.h>
#include<cstring>//pt strlen
int atoi_me(char s[])
{
    int number=0 , i;
    for(i=0; i<strlen(s)-1;i++)
        {
            number = number*10+s[i]-'0';
            //printf("%i\n",number);
        }
    return number;
}
int main()
{   
    FILE* f;
    f = fopen("in.txt", "r");
    int number=0 ;
    char s[10];
    while(fgets(s, sizeof(s), f))
    {   
        //printf("%s\t%i\n",s,strlen(s));   strlen(s) preia numarul de caractere + 1 
        //printf("%i\n",atoi_me(s));
        number += atoi_me(s);
    }
    printf("\n%i",number);
    return 0;
}