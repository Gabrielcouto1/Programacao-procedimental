/*
Apresenta o dobro do numero digitado pelo usuario
O numero eh capturado por scanf()+%s.
Nao pode usar atof().
O usuario eh bem comportado

Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <math.h> //Inclusao de biblioteca de funcoes matematicas

#include "myAtoF.h"

int main()
{
    char s[MAX];
    float num;
    
    printf("\nDigite um numero:\n");
    scanf("%s",s);

    printf("\nDobro de %f = %f\n",myAtoF(s),myAtoF(s)*2);

    return 0;  //Encerra o programa e retorna o valor 0
}

float myAtoF (char str[MAX])
{
    float n=0.0;    //numero relacionado a str
    int sinal=1;    //Sinal do numero
    int d=0;        //Quantidade de casas decimais
    int dp=0;       //Indica se tem casas decimais
    int i=0;

    if(str[0]=='-'){
        sinal=-1;
        i=1;
    }
    else if (str[0]=='+')
        i=1;

    for(;(i<MAX)&&(str[i]!='\0');i++){
        if(str[i]=='.')
            dp=1;
        else {
            n=n*10+(str[i]-'0');
            if(dp==1)
                d++;
        }
    }

    return (n/(pow(10,d))*sinal);
}