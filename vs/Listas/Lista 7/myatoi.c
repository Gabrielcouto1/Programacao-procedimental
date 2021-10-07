/*
O programa coleta um numero inteiro inserido pelo usuario e em seguida escreve o dobro dele.
A funcao myAtoI ira transformar cada algarismo que foi digitado em ascii e transformara em inteiro.

Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C

const int MAX=20;   //Tamanho da string que armazenara o numero inserido

int myAtoI(char s[MAX]);

int main()
{
    char s[MAX];    //Array que armazenara o numero que o usuario vai iserir   
    int n=0;        //Variavel que ira armazenar o numero inteiro

    printf("\nInsira um numero inteiro:\n");
    scanf("%19s",s);

    n=myAtoI(s);//Chama a funcao que vai transformar o o que foi digitado em numero inteiro
    printf("\nO dobro de %d eh %d.\n\n",n,n*2);

    return 0;  //Encerra o programa e retorna o valor 0
}
/*
myAtoI
--------------------------------
A funcao pega o o valor atribuido a string e transforma em numero inteiro.
O usuario eh bem comportado e nao ira digitar nada alem de numeros fora
a primeira casa, se o numero for negativo.
*/
int myAtoI (char s[MAX])
{
    int i=0;    //Contador utilizado no for
    int c=0;    //Contador auxiliar para
    int n=0;    //Variavel que armazena o numero inteiro
    int sinal=1;    //Variavel que indica o sinal do numero, se eh negativo (-1) ou positivo(1)

    if(s[0]=='-'){  //Verifica se o primeiro digito inserido foi o sinal de negativo
        sinal=-1;   //Se for, a variavel sinal sera -1
        c=1;    //O contador do for começa em 1 se o sinal for negativo
    }

    else    
        c=0;    //o Contador do for começa em 0 se nao tiver sinal na primeira casa

    for(i=c;s[i]!='\0';i++){
        n=n*10+s[i]-'0';    //Manipulacao de valores decimais da tabela ascii para transformar em numero inteiro
    }

    return (sinal*n);   //Retorna o valor do sinal vezes o numero inteiro
}