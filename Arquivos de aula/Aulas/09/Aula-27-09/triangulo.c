/*
Apresenta se os angulos informados pelo usuario do programa formou um triangulo.
Por Gabriel Couto de Freitas em 2021
*/
#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C

int isTriangle(float x,float y,float z);
int main()
{
    float a1=0.0;//Valores dos 3 angulos digitados
    float a2=0.0;//Valores dos 3 angulos digitados
    float a3=0.0;//Valores dos 3 angulos digitados

    if(isTriangle(a1,a2,a3)){//Se a funcao retorna 1, eh um triangulo
        printf("\nIts a triangle.\n");
        return 1;
    }
    else{//Se a funcao retorna 0, nao eh um triangulo
        printf("\nIts not a triangle.\n");
        return 0;
    } 
}
/*
    isTriangle
    ------------------------
    A funcao le os angulos x y z. Se a soma for 180 ela retorna 1, 
    se for diferente de 180 ela retorna 0.

*/
int isTriangle(float x,float y,float z)
{
    printf("\nInsert the angles:\n");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    if ((x+y+z)==180.0)
        return 1;
    else
        return 0;
}
