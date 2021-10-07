/*
O programa recebe o valor do peso e da altura que serao inseridos pelo usuario.
Em seguida chama a funcao calcImc e escreve na tela o valor do IMC calculado 
nesta funcao.
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C

void calcImc(float p, float a, float *imc);

int main()
{
    float p=0.0;    //Variavel do peso
    float a=0.0;    //Variavel da altura
    float imc=0.0;  //Variavel do IMC

    printf("\nDigite o peso e a altura: \n");
    scanf("%f %f",&p,&a);

    calcImc(p,a,&imc);//Chama a funcao void calcImc com um ponteiro para atribuir valor ao imc

    printf("\nPeso= %.2f\nAltura= %.2f\nIMC=%.2f\n\n",p,a,imc);

    return 0;  //Encerra o programa e retorna o valor 0
}
/*
calcImc
----------------------------
A funcao atribui o valor do imc a variavel imc na funcao main.
O imc eh calculado dividindo o peso pela altura ao quadrado,
ambos previamente informados pelo usuario.
*/
void calcImc (float p, float a, float *imc) 
{
    *imc=p/(a*a);   //Calculo do IMC
}