/*
    Apresenta o maior valor num array multidimensional de int.
    Os valores no array sao pseudo-aleatorios.

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "maior.h"

int main()
{   
    int n[MAX];

    loadUniArrayOfInt(n);
    showUniArrayOfInt(n);
    printf("\n\nO maior numero do array acima eh :%d\n\n",n[maiorUniArrayOfInt(n)]);

    return 0;  //Encerra o programa e retorna o valor 0
}

int maiorUniArrayOfInt(const int n[])
{
    int p;
    int i;
    
    for(i=p=0;i<MAX;i++)
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

void showUniArrayOfInt(const int n[])
{
    int i;
    printf("\nConteudo da array n com valores pseudo-aleatorios:\n");
    for (i=0;i<MAX;i++)
        printf("%d ",n[i]);
    printf("\n\n");
}