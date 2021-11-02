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
    int n=0;
    FILE *fr=NULL;
    FILE *ferr= NULL;

    if ((fr=fopen(argv[1],"r"))==NULL){
        ferr=fopen(argv[2],"w");
        fprintf(ferr,"Nao foi possivel abrir o arquivo inserido.");
        fclose(ferr);
        return 1;
    }

    while(fscanf(fr,"%d",&n)!=EOF)
        printf("%d\n",n);

    fclose(fr);
    return 0;  //Encerra o programa e retorna o valor 0
}