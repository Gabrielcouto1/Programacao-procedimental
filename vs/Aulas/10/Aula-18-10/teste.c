/*

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

int main()
{
    char s[4000];

    fscanf(stdin,"%[^\n]s",s);
    fprintf(stdout,"%s",s);

    return 0;  //Encerra o programa e retorna o valor 0
}