#include<stdio.h>
#include<cstring>

struct cuvant
{
    char c[100];
    int size;
};
int main()
{
    cuvant C[100];
    char s[256] , *p;
    strcpy(s,"");
    printf("Enter a phrase: ");
    scanf("%[^\n]s",s);//se citesc caractere pana la newline!!
    p = strtok(s," ");
    //printf("%s\n",p);
    int count = 0;
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
    
    return 0;
        
}