/*
Apresenta na tela do computador o resultado da troca de valores entre duas varaveis x e y.
O programa apresenta os valores de x e y antes e depois da troca.
"troca"= Colocar o valor de x em y e de y em x.
Os valores de x e y sao digitados pelo usuario(bem comportado).

Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C

int main()
{
    int x=0;    //Variavel x digitada pelo usuario
    int y=0;    //Variavel y digitada pelo usuario
    int t=0;    //Variavel que auxilia na troca de x por y

    printf("\nDigite os numeros inteiros x e y, respectivamente: \n");
    scanf("%d %d",&x,&y);

    printf("\nAntes da troca:\nX=%d\nY=%d\n",x,y);
    t=x;
    x=y;
    y=t;
    printf("\nDepois da troca:\nX=%d\nY=%d\n",x,y);
    return 0;  //Encerra o programa e retorna o valor 0
}

