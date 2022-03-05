#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *codificare1 (char caracter)
{
    char aux;
    char *rezultat=(char *)malloc(7*sizeof(char));
    int char_to_ascii=caracter,i=1,lenght,frecventa,pozitie;
    // Alocam static vectorul de frecventa
    static int frecv[200];
    // Crestem frecventa caracterului
    frecv[char_to_ascii]++;
    // Scadem frecventa cu 1 pentru ca numaratoarea incepe de la 0
    frecventa=frecv[char_to_ascii]-1;
    i=0;
    /* Daca frecventa e mai mare ca 9 trebuie impartita
    in mai multe spatii din vector */
    do
    {
        rezultat[i]=frecventa%10+'0';
        i++;
        frecventa=frecventa/10;
        if(frecventa==0) break;
    }
    while (frecventa>0);
    // Acum in vector avem rasturnatul frecventei
    lenght=i;
    pozitie=lenght-1;
    // Inversam frecventa pentru a avea in vector frecventa reala
    for (i=0; i<lenght; i++)
    {
        aux=rezultat[pozitie];
        rezultat[pozitie]=rezultat[i];
        rezultat[i]=aux;
        pozitie--;
        if(pozitie==(lenght/2)-1) break;
    }
    /* Mutam fiecare element cu 1 in fata pentru a adauga
    caracterul in pozitia 0 */
    for (i=lenght; i>0; i--)
    {
        rezultat[i]=rezultat[i-1];
    }
    rezultat[0]=caracter;
    rezultat[lenght+1]='\0';
    // Returnam rezultatul
    return rezultat;
}

char *codificare2 (char caracter)
{
    char caracter_in=caracter,caracter_out;
    char *rezultat=(char *)malloc(3*sizeof(char));
    int nr=caracter_in,rev,bit=0,copie_rev;
    int mask=32;
    // Aplicam inversarea bitilor 3 si 6
    rev = nr ^ ((1<<3)|(1<<6));
    // Copiem rezultatul
    copie_rev=rev;
    // Calculam numarul de biti de 1
    while (copie_rev)
    {
        bit+=copie_rev & 1;
        copie_rev=copie_rev>>1;
    }
    // Aplicam operatia de sau logic cu masca data
    rev = rev | mask;
    rev &= ~(1<<0);
    // Convertim caracterul obtinut in char
    caracter_out=rev;
    rezultat[0]=caracter_out;
    rezultat[1]=bit+'0';
    rezultat[2]=0;
    return rezultat;
}

char *codificare3 (char caracter)
{
    char *rezultat=(char *)malloc(2*sizeof(char));
    // Daca este litera mica o transformam in litera mare
    if ((caracter>='a')&&(caracter<='z')) caracter=caracter-32;
    rezultat[0]=caracter;
    rezultat[1]='\0';
    return rezultat;
}

char *generare (int seed, int n)
{
    int i;
    char *parola=(char *)malloc(n+1);
    // Generam parola
    for (i=0; i<n; i++)
        parola[i] = rand() % 94+32;
    // Returnam adresa vectorului dinamic
    return parola;
}

void codif(int codificari[], int n)
{
    int i;
    // Generam codificarile care trebuie efectuate (0, 1 sau 2)
    for (i=0; i<n; i++)
    {
        codificari[i] = rand() % 3;
    }
}

void transform (int codificari[],int n,char *parola )
{
    int i=0,apelare;
    // Declaram pointerul de functii
    char *(*point_functii[3])(char);
    char *rezultat_codif,caracter;
    // Initializam pointerul de functii cu numele functiilor de codificare
    point_functii[0]=codificare1;
    point_functii[1]=codificare2;
    point_functii[2]=codificare3;
    while(i<n)
    {
        // Caracterul care trebuie codificat
        caracter=parola[i];
        // Tipul de codificare ceruta
        apelare=codificari[i];
        // Apelarea functiei de codificare
        rezultat_codif = point_functii[apelare](caracter);
        printf("%s",rezultat_codif);
        free(rezultat_codif);
        i++;
    }
    printf("\n");
}

int main()
{
    int seed,n;
    // Citim seed-ul si numarul de caractere
    scanf("%d%d",&seed,&n);
    int *codificari=(int *)malloc(n*sizeof(int)+4);
    char *parola;
    // Folosim seed-ul introdus
    srand(seed);
    // Salvam adresa unde se va genera parola
    parola=generare(seed,n);
    // Apelam functia pentru a salva codificarile necesare
    codif(codificari,n);
    // Apelam functia de transformare
    transform(codificari,n,parola);
    // Eliberam memoriile alocate pe parcusul programului
    free(parola);
    free(codificari);
    return 0;
}
