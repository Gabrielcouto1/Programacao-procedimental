/* 
O programa captura um numero inteiro digitado pelo usuario e em seguida mostra o seu dobro.
O usuario pode ser mal comportado. Caso seja, o programa verifica se ele digitou a quantidade
correta de algarismos e se tudo que foi digitado eh um numero inteiro. 
Se o programa encontrar algum erro de digitacao, o usuario sera informado,
se nao encontrar, o dobro do numero digitado eh escrito na tela.

Por Gabriel Couto de Freitas em 2021    
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <time.h> //Inclusao de biblioteca para uso da funcao time()
#include <ctype.h> //Inclusao de biblioteca para verificação de dígitos
#include <string.h> //Inclusao de biblioteca de funcoes de string
#include <math.h> //Inclusao de biblioteca de funcoes matematicas

const int MAX=20;   //Tamanho maximo do array

int getStr(char s[MAX]);
int isIntnum(char s[MAX]);

int main()
{
    char s[MAX];    //Array de numeros a serem digitados pelo usuario
    int n=0;  //Variavel que sera usada para transformar o array 's' em numero inteiro
    int r=0;    //Variavel auxiliar que armazena o valor que as funcoes retornam
    int i;  //Contador que sera usado para zerar as posicoes do array 's'

    for(i=0;i<MAX;i++){//Zera todos elementos do array antes de capturar os digitos do usuario
        s[i]=0;
    }
    printf("\nDigite um numero inteiro que queira calcular o dobro:\n\n");
    r=getStr (s);//Chama a funcao que ira capturar os digitos do usuario

    if(r==0){   //O usuario digitou mais algarismos que o maximo estabelecido
        printf("\nVoce digitou um numero com mais algarismos que %d.\n\n",MAX);
        return 0;   //Encerra o programa e retorna o valor 0
    }
    else if(r==1){//O usuario digitou um numero correto de algarismos: o programa continua
        r=0;
        r=isIntnum(s);//Chama a funcao que ira verificar se o usuario digitou apenas numeros inteiros

        if(r==0){//O usuario nao digitou um numero inteiro
            printf("\nVoce nao digitou um numero inteiro.\n\n");
            return 0;
        }
        else if(r==1){//O usuario digitou um numero inteiro: o programa continua
            n=atoi(s);
            printf("\nO dobro de %d eh: %d\n\n",n,n*2);
            return 1;
        }
    }
}
/*
getStr
----------------------------------------------------------------
A funcao getStr captura um numero que sera inserido pelo usuario
e em seguida verifica se o usuario digitou mais algarismos que 
o MAX preestabelecido. Se o maximo for excedido, retorna o valor 0.
Se o maximo nao for excedido, retorna o valor 1 e a funcao main continua.
*/
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
    else    
        return 1;  //Senao, o programa continua normalmente
}
/*
isIntnum
-----------------------------------------------------------
A funcao isIntnum serve para testar se o usuario digitou 
um numero inteiro. Ela verifica se ele digitou um sinal
(- ou +), e em seguida testa todas as posicoes do array.
Se algum caractere nao for um numero inteiro, a funcao 
retorna o valor 0. Se todos forem numeros inteiros, retorna 
o valor 1 e a funcao main continua.
*/
int isIntnum (char s[MAX])
{
    int i=0; //Variavel usadas no contador
    int err=0;  //Variavel utilizada para saber se existe um digito que nao eh um numero inteiro

    if((s[0]=='-'||s[0]=='+'))//Verifica se o primeiro elemento eh um sinal '-' ou '+'
        i=1;
    else 
        i=0;
    
    for(i=i;i<MAX;i++){//Verifica se o que foi digitado eh um numero inteiro
        if(isdigit(s[i])==0){
            if((s[i]!=0)&&(s[i])!='\n'){
                err++;
                break;
                }
            else 
                continue;
        }
    }
    if(err==0){     //Caso nao tenha erros, a funcao main ira continuar normalmente
        return 1;
    }
    else if(err)    //Caso tenha erros, a funcao main ira encerrar
        return 0;
}