/*
    Ordena os valores num array multidimensional de int.
    Os valores no array sao pseudo-aleatorios.

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "Ordena.h"

int main()
{   
    int n[MAX];
    int pos=0;

    loadUniArrayOfInt(n);

    printf("\nAntes:\n");
    showUniArrayOfInt(n);

    SortArray(n);

    printf("\nDepois\n");
    showUniArrayOfInt(n);

    return 0;  //Encerra o programa e retorna o valor 0
}

int maiorUniArrayOfInt(const int n[],int ma)
{
    int p;
    int i;
    
    for(i=p=0;i<=ma;i++)
        if(n[i]>n[p])
            p=i;

    return p;
}

void loadUniArrayOfInt(int n[])
{
    int i;

    srand(time(NULL));
    for (i=0;i<MAX;i++)
        n[i]=rand()%PRIME;
    
}

void showUniArrayOfInt(int n[])
{
    int i;
    for (i=0;i<MAX;i++)
        printf("%d ",n[i]);
    printf("\n\n");
}

void SortArray(int n[])
{
    int p=0;
    int t=0;
    int i;

    for(i=MAX-1;i>=0;i--){
        t=n[i];
        p=maiorUniArrayOfInt(n,i);
        n[i]=n[p];
        n[p]=t;
    }
}