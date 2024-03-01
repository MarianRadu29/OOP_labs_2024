#include<stdio.h>
#include<cstring>

int main()
{
    char C[100][100];
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
        strcpy(C[count++],p);
        p = strtok(NULL," ");
    }
    int i , j;
    for(i=0;i<count;i++)
        for(j=i+1;j<=count;j++)
            if(strlen(C[i])<strlen(C[j]))
            {
                 char aux[100];
                        strcpy(aux,C[j]);
                        strcpy(C[j],C[i]);
                        strcpy(C[i],aux);   
            }
            else
                if(strcmp(C[j],C[i])>0 && strlen(C[j])==strlen(C[i]))
                    {
                        char aux[100];
                        strcpy(aux,C[j]);
                        strcpy(C[j],C[i]);
                        strcpy(C[i],aux);
                    }
    for(int i = 0;i<=count;i++)
        printf("%s\n",C[i]);
        

    
    return 0;
        
}
