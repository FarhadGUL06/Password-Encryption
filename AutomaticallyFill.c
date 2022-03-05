#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MARIME 20000

struct pereche
{
    char *camp, *valoare;
};

void replace (char *sir_final, char *vechi, char *nou,int sarire)
{
    char *pozitie,aux[MARIME];
    int punct=0,actual=strlen(vechi);
    // Salvam pozitia unde a fost gasit campul
    pozitie=strstr(sir_final+sarire,vechi);
    strcpy (aux,sir_final);
    /* Salvam pozitia curenta scazand din adresa
    pozitiei actuale adresa pozitiei de inceput a sirului*/
    punct=pozitie-sir_final;
    sir_final[punct]='\0';
    // Atasam sirului valoarea campului
    strcat(sir_final,nou);
    /* Reatasam sirului rezultat componenta finala din
    dreapta campului care trebuia inlocuit*/
    strcat(sir_final,aux+punct+actual);
}

void inlocuire (char *text, struct pereche *sir, char *text_r, int n)
{
    char *p,cuvant[MARIME],sep[]=",. !?;:",cuvant2[MARIME],*k;
    int j,sarire=0,ok=0,a;
    // Primul cuvant
    p=strtok(text,sep);
    while (p)
    {
        ok=0;
        for (j=0; j<n; j++)
        {
            // Daca cuvantul coincide cu unul din campuri
            if (strcmp(sir[j].camp,p)==0)
            {
                ok=1;
                // Inlocuim campul cu valoarea ceruta
                strcpy(cuvant,p);
                strcpy(cuvant2,sir[j].valoare);
                a=strlen(cuvant);
                replace(text_r,cuvant,cuvant2,sarire);
                // Sarim caracterele pana la urmatorul cuvant
                // Daca primul cuvant a fost un camp
                if (sarire==0)
                {
                    k=strchr(sep,text_r[sarire]);
                    while (k == NULL)
                    {
                        k=strchr(sep,text_r[sarire]);
                        sarire++;
                    }
                }
                else
                {
                    if (a==1)
                    {
                        k=strchr(sep,text_r[sarire]);
                        while (k != NULL)
                        {
                            k=strchr(sep,text_r[sarire]);
                            sarire++;
                        }
                    }
                    k=strchr(sep,text_r[sarire]);
                    while (k == NULL)
                    {
                        k=strchr(sep,text_r[sarire]);
                        sarire++;
                    }
                }
            }
        }
        // Trecem la urmatorul cuvant
        if (ok==0)
        {
            k=strchr(sep,text_r[sarire]);
            // Eliminam caracterele pana la urmatorul cuvant
            while (k == NULL)
            {
                k=strchr(sep,text_r[sarire]);
                sarire++;
            }
        }
        p=strtok(NULL,sep);
    }
}


void citire (char text[],struct pereche *sir, int n)
{
    int i;
    char camp[MARIME],valoare[MARIME],c;
    for (i=0; i<n; i++)
    {
        scanf("%s",camp);
        camp[strlen(camp)]='\0';
        sir[i].camp=malloc(strlen(camp)+1);
        // Copiem campul in vectorul de perechi
        strcpy(sir[i].camp,camp);
        scanf("%s",valoare);
        valoare[strlen(valoare)]='\0';
        sir[i].valoare=malloc(strlen(valoare)+1);
        // Copiem valoarea in vectorul de perechi
        strcpy(sir[i].valoare,valoare);
    }
    // Citim textul ce trebuie prelucrat
    scanf("%c",&c);
    fgets(text,MARIME,stdin);
}

int main()
{
    int n,i,lungime;
    scanf("%d",&n);
    char *text_rezultat = (char*) malloc(MARIME);
    char *text = (char*) malloc(MARIME);
    // Am alocat dinamic sirul de pointeri
    struct pereche *sir=malloc(n*sizeof(struct pereche));
    // Apelam functia de citire
    citire(text,sir,n);
    lungime=strlen(text);
    text=(char *)realloc(text,lungime+1);
    // Copiem textul pentru a-l avea intreg.
    strcpy(text_rezultat,text);
    lungime=strlen(text_rezultat);
    // Apelam functia de inlocuire
    inlocuire(text,sir,text_rezultat,n);
    lungime=strlen(text_rezultat);
    text_rezultat=(char *)realloc(text_rezultat,lungime+1);
    // Daca sirul necesita concatenarea, vom elimina ce am adaugat
    lungime=strlen(text_rezultat);
    // Afisam sirul rezultat
    printf("%s",text_rezultat);
    // Eliberam memoria
    for(i=0; i<n; i++)
    {
        free(sir[i].camp);
        free(sir[i].valoare);
    }
    free(text_rezultat);
    free(text);
    free(sir);
    return 0;
}

