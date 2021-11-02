/*
    O programa abre e le um arquivo de nome inserido pelo usuario
    a tempo de lancamento. Em seguida le linha por linha e armazena
    o nome e as notas do aluno. Em seguida calcula a media. Se a media
    do alunofor maior ou igual ao M inserido pelo usuario a tempo de lancamento,
    ele escreve os dados do aluno na tela.
    
    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h>  
#include <ctype.h>  

const int MAX=20;

int main(int argc, char* argv[])
{
    int M=0;    //Variavel que armazena a media digitada pelo usuario
    char linha[256];    //Variavel que armazena a linha do arquivo de texto
    char nome[MAX]; //Armazena o nome 
    float nota1=0;  //Armazena a primeira nota
    float nota2=0;  //Armazena a segunda nota
    float media=0;  //Armazena a media das notas
    FILE *F=NULL;

    F=fopen(argv[1],"r");

    if(argc<3){     //Se faltar argumenos ele encerra o programa
        fprintf(stderr,"\nArgumentos insuficientes.\n\n");
        return 3;
    }

    if(F==NULL){    //Se o nome do arquivo nao existir encerra o programa
        fprintf(stderr,"\nNao foi possivel abrir o arquivo inserido.\n\n");
        return 5;
    }

    M=atof(argv[2]);

    while (fgets(linha, sizeof(linha), F)) {    
        
        sscanf(linha, "%[^0-9.] %f %f", nome, &nota1, &nota2);// Scanea na linha o nome e as notas do aluno
        media=(nota1+nota2)/2;  
        if(media>=M){   //Se a media do aluno for maior ou igual a media inserida ele escreve na tela
            printf("%s ", nome);
            printf("%.1f ", nota1);
            printf("%.1f ", nota2);
            printf("Media=%.2f\n\n",media);
        }
    }

    fclose(F);  //Fecha o arquivo

    return 0;   //Encerra o programa com valor 0
}