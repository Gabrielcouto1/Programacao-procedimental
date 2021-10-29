/*

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

    for(i=0;argv[i]!=NULL;i++) //ou for(i=0;i<argc;i++) 
        printf("%s\n",argv[i]);

    return 0;  //Encerra o programa e retorna o valor 0
}