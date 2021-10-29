/*

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

const int MAX=30;

int main(int argc, char *argv[])
{
    char s[MAX];
    char bn;
    FILE *f=NULL;
    if(argc<2||argc>2){
        fprintf(stderr,"Quantidade de argumentos errada.\n\n");
        return 2;
    }
    else if ((f=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"Nao foi possivel abrir o arquivo inserido.\n\n");
        return 1;
    }

    while(fscanf(f,"%[^\n]",s)!=EOF){
        fscanf(f,"%c",&bn);
        printf("%s\n",s);
    }
    fclose(f);
    return 0;  //Encerra o programa e retorna o valor 0
}