/*
    Realiza a copia de um arquivo E em um arquivo S
    O nome dos arquivos sao passados por redirecionamento

    E e S sao arquivos de texto
    Usuario bem comportado

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
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
    char c;

    while(fscanf(stdin,"%c",&c)!=EOF)
        fprintf(stdout,"%c",c);
    
    return 0;  //Encerra o programa e retorna o valor 0
}