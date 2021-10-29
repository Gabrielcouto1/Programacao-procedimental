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

    FILE *fe=NULL;
    FILE *fs=NULL;
    if(argc<3){
        fprintf(stderr,"\nVoce inseriu menos que 2 args.\n\n");
        return 1;
    }
    else if(argc>3){
        fprintf(stderr,"\nVoce inseriu mais que 2 args.\n\n");
        return 2;
    }
    if((fe=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"\nO arquivo %s nao pode ser aberto.\n\n",argv[1]);
        return 3;
    }
    if((fs=fopen(argv[2],"w"))==NULL){
        fprintf(stderr,"\nO arquivo %s nao pode ser aberto.\n\n",argv[2]);
        return 4;
    }
    for(i=0;(c=fgetc(fe))!=EOF;i++)
        fputc(c,fs);

    fclose(fe);
    fclose(fs);
    return 0;  //Encerra o programa e retorna o valor 0
}