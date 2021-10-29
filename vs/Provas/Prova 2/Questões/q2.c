/*
    O programa apresenta na tela a concatenacao de dois strings 
    digitados pelo usuario do programa. 
    O tamanho maximo de caracere da string resultante eh 50.
    
    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h>
#include <string.h>

const int MAX=50;

int main()
{
    char str1[MAX]; //Armazena a string 1 digitada pelo usuario
    char str2[MAX]; //Armazena a string 2 digitada pelo usuario
    char str_res[MAX];  //Armazena a string resultante que eh a concatenacao das duas strings
    int i;      //Contador utilizado no for
    int c=0;    //Contador auxiliar
    int t1=0;   //Variavel que armazena o tamanho da string 1 digitada pelo usuario
    int t2=0;   //Variavel que armazena o tamanho da string 2 digitada pelo usuario
    int n1=0;   //Variavel que armazena onde a string 1 se encerra
    int n2=0;   //Variavel que armazena onde a string 2 se encerra

    for (i=0;i<MAX;i++){    //Inicia todas as strings com um espaco vazio
        str1[i]='\0';
        str2[i]='\0';
        str_res[i]='\0';
    }

    printf("String 1:");
    for(i=0;i<MAX;i++){     //Armazena o que o usuario digitou na string 1
        scanf("%c",&str1[i]);
        if(str1[i]=='\n'){
            n1=i;           //Informa onde o usuario digita o enter
            break;
        }
    }
    
    printf("String 2:");
    for(i=0;i<MAX;i++){     //Armazena o que o usuario digitou na string 1
        scanf("%c",&str2[i]);
        if(str2[i]=='\n'){
            n2=i;           //Informa onde o usuario digita o enter
            break;
        } 
    }

    t1=strlen(str1);    //Coleta o tamanho da string 1
    t2=strlen(str2);    //Coleta o tamanho da string 1

    if((t1+t2)>50){     //Se for maior que 50 caracteres, encerra o programa
        printf("\nQuantidade de algarismos a string resultante maior que 50.\n\n");
        return 3;
    }

    for(i=0;i<MAX;i++)    //Armazena o que foi digitado na string 1 na string resultante
        if(i!=n1)
            str_res[i]=str1[i];

    for(i=n1;i<MAX;i++)   //Armazena o que foi digitado na string 1 na string resultante, depois do que ja estava armazenado
        if(i!=n2){
            str_res[i]=str2[c]; //Continua de onde parou na str_res e a str2 começa na primeira posicao
            c++;
        }

    printf("\n\nString concatenada:\n%s",str_res);   //Escreve na tela a string concatenada resultante

    return 0;   //O programa se encerra e retorna 0
}
