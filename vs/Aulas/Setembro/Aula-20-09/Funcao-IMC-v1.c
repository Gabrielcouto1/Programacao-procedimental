/*
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C

int main()
{
    float p=0.0;    //Peso
    float a=0.0;    //Altura    
    float imc=0.0;  //IMC

    printf("Digite o seu peso: ");
    scanf("%f",&p);

    printf("\nDigite a sua altura: ");
    scanf("%f",&a);

    imc=p/(a*a);
    printf("Peso=%.2f\tAltura=%.2f\tIMC=%.2f\n",p,a,imc);

    return 0;  //Encerra o programa e retorna o valor 0
}