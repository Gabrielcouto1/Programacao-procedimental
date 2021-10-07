/*
Apresenta na tela do computador o resultado da troca de valores entre duas varaveis x e y.
O programa apresenta os valores de x e y antes e depois da troca.
"troca"= Colocar o valor de x em y e de y em x.
Os valores de x e y sao digitados pelo usuario(bem comportado).

Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C

void trocaInt(int *x, int *y);
int main()
{
    int x=0;    //Variavel x digitada pelo usuario
    int y=0;    //Variavel y digitada pelo usuario

    printf("\nDigite os numeros inteiros x e y, respectivamente: \n");
    scanf("%d %d",&x,&y);

    printf("\nAntes da troca:\nX=%d\nY=%d\n",x,y);
    trocaInt(&x, &y);//Chama a funcao que realiza a troca   
    printf("\nDepois da troca:\nX=%d\nY=%d\n",x,y);
    return 0;  //Encerra o programa e retorna o valor 0
}

/*
trocaInt
--------------------------
A funcao troca o valor de x por y e de y por x.
*/
void trocaInt(int *x, int *y)
{
    int t=0;    //Variavel auxiliar que ajuda na troca

    t=*x;   //t recebe o conteudo do endereco de x
    *x=*y;  //o conteudo do endereco de x recebe o conteudo do endereco de y
    *y=t;   //y recebe o conteudo do endereco de t
}