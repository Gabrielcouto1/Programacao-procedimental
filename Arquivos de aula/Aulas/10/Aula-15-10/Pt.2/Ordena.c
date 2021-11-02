/*
    Ordena os valores num array multidimensional de int.
    Os valores no array sao pseudo-aleatorios.

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>
#include "Ordena.h"

const int tam=10;
int main()
{   
    

    int n[tam];
    int pos=0;

    loadUniArrayOfInt(n);

    printf("\nAntes:\n");
    showUniArrayOfInt(n);

    SortArray(n);

    printf("\nDepois\n");
    showUniArrayOfInt(n);

    return 0;  //Encerra o programa e retorna o valor 0
}