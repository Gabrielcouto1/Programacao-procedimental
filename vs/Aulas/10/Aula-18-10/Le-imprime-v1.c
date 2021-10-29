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
    int n=0;
    FILE *f=NULL;

    f= fopen("le-imprime.txt", "r");

    if (f==NULL){
        fprintf(stderr,"\nNao foi possivel abrir o arquivo inserido.\n\n");
        return 1;
    }

    while(fscanf(f,"%d",&n)!=EOF)
        printf("%d\n",n);

    fclose(f);
    return 0;  //Encerra o programa e retorna o valor 0
}