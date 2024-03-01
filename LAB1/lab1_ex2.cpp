#include<stdio.h>
#include<cstring>

char C[100][100], s[256], aux[100], *p;
int count, i, j;
int main()
{
    printf("Enter a phrase: ");
    scanf("%[^\n]s",s);//!!conditie de oprire la newline
    p = strtok(s," ");
    while(p!=NULL)
    {   
        strcpy(C[count++],p);
        p = strtok(NULL," ");
    }
    for(i=0;i<count;i++)
        for(j=i+1;j<=count;j++)
            if(strlen(C[i])<strlen(C[j]))
            {
                        strcpy(aux,C[j]);
                        strcpy(C[j],C[i]);
                        strcpy(C[i],aux);   
            }
            else
                if(strcmp(C[j],C[i])>0 && strlen(C[j])==strlen(C[i]))
                    {
                        strcpy(aux,C[j]);
                        strcpy(C[j],C[i]);
                        strcpy(C[i],aux);
                    }
    for(int i = 0;i<=count;i++)
        printf("%s\n",C[i]);
    return 0;        
}
