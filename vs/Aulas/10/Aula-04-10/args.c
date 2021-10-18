/*
    Apresenta os argumentos passados para o programa em tempo de lançamento.
    Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int i;

    if(argc>1){ 
        printf("Argumentos:\n-----------------\n");
        for(i=1;i<argc;i++)
            printf("%s\n",argv[i]);
    }
    else
        fprintf(stderr,"\nNao ha argumentos.\n");

    return 0;  //Encerra o programa e retorna o valor 0
}