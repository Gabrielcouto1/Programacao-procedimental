/*
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <math.h>

float calc_imc(float peso, float altura);
void interpreta_imc(float X);

int main()
{
    float p=0.0;    //Peso
    float a=0.0;    //Altura    
    float imc=0.0;  //IMC

    printf("Digite o seu peso: ");
    scanf("%f",&p);

    printf("\nDigite a sua altura: ");
    scanf("%f",&a);

    imc=calc_imc(p,a);
    printf("Peso=%.2f\tAltura=%.2f\tIMC=%.2f\n",p,a,imc);

    interpreta_imc(imc);

    return 0;  //Encerra o programa e retorna o valor 0
}

/*
calc_imc
--------------------
A função calcula o imc com o peso e altura inseridos na funcao main
pelo usuario e retorna este valor.

*/
float calc_imc(float peso, float altura)
{
    return peso/(pow(altura,2));
}
/*
interpreta_imc
--------------------
A função interpreta o imc calculado na funcao main
e diz se o usuario e abaixo do peso, peso normal, acima do peso ou obeso.

*/
void interpreta_imc(float X)
{
    if(X<18.5)
        printf("\nAbaixo do peso.\n\n");
    else if(X<25.0)
        printf("\nIMC normal.\n\n");
    else if(X<30.0)
        printf("\nSobrepeso.\n\n");
    else   
        printf("\nObesidade.\n\n");
}