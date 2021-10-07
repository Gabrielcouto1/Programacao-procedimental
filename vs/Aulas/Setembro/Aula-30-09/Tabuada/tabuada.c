/*
Apresentar a tabuada do N tal que o multiplicador M:
1<=M<=Q.
A tabuada deve ser apresentada com K produtos por linha.
N, K e Q sao digitados pelo usuario do programa, tal que sao inteiros e >0.
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca para verificação de dígitos

#include "tabuada.h"//Inclusao de biblioteca para tabuada 

int main()
{
    char s[MAX];    //String dos numeros
    int n=0;    //Multiplicando
    int q=0;    //Limite de tabuada
    int k=0;    //Limite de produtos por linha

    printf("\nInsira um numero para mostrar a tabuada:\n");
    if(!getStr(s)){
        printf("\nVoce digitou mais de %d algarismos.\n",MAX-1);
        return 3;
    }

    if(!isIntnum(s)){
        printf("\nNao eh um numero.\n");
        return 5;
    }
    n=atoi(s);
    
    if(n<=0){
        printf("\nVoce digitou um numero menor ou igual a 0.\n");
        return 7;
    }

    printf("\nQuer ver a tabuada de %d indo de 1 ate quando?:\n",n);
    scanf("%d",&q);

    if(q<=0){
        printf("Voce digitou um numero invalido.\n");
        return 7;
    }

    printf("\nQuantas multiplicacoes por linha quer ver?:\n");
    scanf("%d",&k);

    if(k<=0){
        printf("\nVoce digitou um numero de multiplicacoes invalido.\n");
        return 9;
    }
    
    timesTable (n,k,q);

    return 0;  //Encerra o programa e retorna o valor 0
}

int getStr(char s[MAX])
{
    int i;  //Variavel utilizada no for para captura dos elementos da string

    for(i=0;i<MAX;i++){
        scanf("%c",&s[i]);
        if(s[i]=='\n')  //No momento que o usuario digita enter, a captura cessa
            break;
    }
    
    if(i==MAX)  //Se o contador tem o mesmo valor de MAX, indica que o usuario digitou mais algarismos que o permitido
        return 0;   //O programa encerra

    s[i]='\0';   
    return 1;  //Senao, o programa continua normalmente
}

int isIntnum (char s[MAX])
{
    int i=((s[0]=='-')||(s[0]=='+'))? 1:0;  //Se comecar com um sinal, o for comeca na segunda posicao da string

    for(;s[i]!='\0';i++){
        if(isdigit(s[i])==0) //Realiza o teste para ver se a posicao atual eh numero
            return 0;
    }

    return 1;
}

void timesTable (int n, int k, int q){
    int i=1;
    int t=0;
    int m=0;

    for (m=1; m<=q;m++){
        printf("%d * %d = %d\t",n,m,n*m);
        if(m%k==0){
            printf("\n");
        }
    }
    printf("\n");
}