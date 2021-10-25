/*
    Apresenta o maior valor num array multidimensional de int.
    Os valores no array sao pseudo-aleatorios.

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include "maior.h"


int main()
{   
    int n[MAX];

    loadUniArrayOfInt(n);
    maiorUniArrayOfInt(n);

    return 0;  //Encerra o programa e retorna o valor 0
}