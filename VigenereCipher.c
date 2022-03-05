#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MARIME 13501

void criptare(char sir1[], char sir2[], int n)
{
    int i,j,a;
    for (i=0; i<n; i++)
    {
        if ((sir1[i]<='z')&&(sir1[i]>='a'))
            a=sir1[i]-'a';
        else
            /* Daca este litera mare trebuie sa adaugam si
            diferenta intre literele A si a */
            if ((sir1[i]<='Z')&&(sir1[i]>='A'))
                a=sir1[i]-'A'+26;
        j=0;
        while (j<a)
        {
            /* Avansam cu cate 1 si daca este caracterul
            imediat urmator dupa z, vom ajunge la A si daca
            este caracterul imediat urmator dupa Z, ajungem la a */
            sir2[i]=sir2[i]+1;
            if (sir2[i]=='[') sir2[i]='a';
            else if (sir2[i]=='{') sir2[i]='A';
            j++;
        }
    }
}

void prelungire (char sir1[], int rep, int r,int m)
{
    int i=0,j;
    char sir3[MARIME];
    strcpy(sir3,sir1);
    while (i<rep-1)
    {
        strcat(sir1,sir3);
        i++;
    }
    i=strlen(sir1);
    for (j=0; j<r; j++)
    {
        sir1[i]=sir1[i-m];
        i++;
    }
    sir1[i]='\0';
}

int verificare (char s1[], char s2[], int lung1, int lung2)
{
    int i,all_letters=1,char_letter=1;
    // In all_letters vom retine daca toate caracterele sunt litere
    // In char_letter vom retine daca caracterul curent este litera
    for (i=0; i<lung2; i++)
    {
        if ((s2[i]>='a')&&(s2[i]<='z')) char_letter=1;
        else if ((s2[i]>='A')&&(s2[i]<='Z')) char_letter=1;
        else char_letter=0;
        if (char_letter==0) all_letters=0;
    }
    for (i=0; i<lung1; i++)
    {
        if ((s1[i]>='a')&&(s1[i]<='z')) char_letter=1;
        else if ((s1[i]>='A')&&(s1[i]<='Z')) char_letter=1;
        else char_letter=0;
        if (char_letter==0) all_letters=0;
    }
    return all_letters;
}

int main()
{
    int n,m,repetitie,rest,ver;
    char cheie[MARIME],text[MARIME];
    scanf("%s",cheie);
    cheie[strlen(cheie)]='\0';
    scanf("%s",text);
    text[strlen(text)]='\0';
    n=strlen(text);
    m=strlen(cheie);
    // Verificam daca toate caracterele sunt litere
    ver=verificare(cheie,text,m,n);
    if (ver==1)
    {
        rest=n%m;
        repetitie=n/m;
        prelungire(cheie,repetitie,rest,m);
        // Criptam textul
        criptare(cheie,text,n);
        printf("%s\n",text);
    }
    else
        // Daca nu toate caracterele sunt litere afisam INVALID
        printf("INVALID\n");
    return 0;
}
