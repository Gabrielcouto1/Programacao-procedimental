/*
    O algoritmo apresenta o peso, a altura, o IMC e a interpretacao do IMC.
    O usuario ira inserir o peso e a altura no lancamento do programa.
    Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

void calc_imc(float peso, float altura);
int main(int argc,char *argv[])
{
    
    if (argc>1){
        float p=0;
        float a=0;

        p=atof(argv[1]);
        a=atof(argv[2]);
        calc_imc(p,a);
    }
    else 
        fprintf(stderr,"\nNao ha argumentos.\n");

    return 0;  //Encerra o programa e retorna o valor 0
}

/*
calc_imc
--------------------
A função calcula e interpreta o IMC com o peso e altura inseridos
e diz se o usuario e abaixo do peso, peso normal, acima do peso ou obeso.

*/
void calc_imc(float peso, float altura)
{
    float imc=0;
    imc=peso/(altura*altura);
    printf("\nIMC=%.2f\n",imc);
    if(imc<18.5)
        printf("\nAbaixo do peso.\n\n");
    else if(imc<25.0)
        printf("\nIMC normal.\n\n");
    else if(imc<30.0)
        printf("\nSobrepeso.\n\n");
    else   
        printf("\nObesidade.\n\n");
}

