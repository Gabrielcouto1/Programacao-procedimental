/*

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

#define MAX 20
struct aluno
{
    char nome[MAX];
    float nota_1;
    float nota_2;
};
typedef struct aluno  Aluno;

int main(int argc, char *argv[])
{
    FILE *F=NULL;
    F=fopen(argv[1],"r");
    char s[500];
    char c=' ';
    int numLinha=0;

    if(argc<3){
        fprintf(stderr,"\nArgumentos insuficientes.\n\n");
        return 3;
    }

    if(F==NULL){
        fprintf(stderr,"\nNao foi possivel abrir o arquivo inserido.\n\n");
        return 5;
    }

    while(fscanf(F,"%[^\n]%c",s,&c)!=EOF){
        if(c=='\n')
            numLinha++;
    }

    Aluno a[numLinha];
    
    int i,j;
    float M=0.0;
    float media=0.0;
  
    M=atof(argv[2]);

    for(i=0;i<numLinha;i++){
        if(feof(F)!=0)
            break;
        fscanf(F,"%[^0-9] %f %f", a[i].nome , &a[i].nota_1 , &a[i].nota_2 );
    }

    for(j=0;i<j;j++){
        media=(a[j].nota_1+a[j].nota_2)/2;
        if(media>=M){
            printf("%s %f %f %f\n",a[j].nome,a[j].nota_1,a[j].nota_2,media);
        }
    }

    fclose(F);
    return 0;  //Encerra o programa e retorna o valor 0
}