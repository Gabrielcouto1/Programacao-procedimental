/*
Apresenta a matriz D LxC, onde D[i][j] eh  dobro de M[i][j].
M eh uma matriz LxC, de numeros inteiros digitados pelo usuario.
O usuario eh bem comportado.

Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C

#include "matriz-dobro.h"
int main()
{
    int m[L][C];    //Matriz original
    int d[L][C];    //Matriz com o dobro da original
    
    printf("\nCarrega valores da matriz %dx%d\n",L,C);
    loadMatrix(m);  //Chama a funcao que carrega os valores na matriz m original

    printf("\nConteudo da matriz original %dx%d:\n",L,C);
    showMatrix(m);  //Mostra a matriz original 

    doubleMatrix(m,d);  //Calcula o dobro da matriz original e armazena na matriz d

    printf("\nConteudo da matriz dobro %dx%d:\n",L,C);
    showMatrix(d);  //Mostra o dobro da matriz original

    return 0;  //Encerra o programa e retorna o valor 0
}

void doubleMatrix(int m[L][C], int d[L][C]){
    int i,j;

    for (i=0;i<L;i++)
        for(j=0;j<C;j++)
            d[i][j]=2*m[i][j];
}

void loadMatrix (int mtx[L][C]){
    int i,j;
    int v=0;    //Valor digitado pelo usuario ou coletado em algum arquivo

    for(i=0;i<L;i++)
        for(j=0;j<C;j++){
            scanf("%d",&v);
            mtx[i][j]=v;
        }
}

void showMatrix (int mtx[L][C]){
    int i,j;
    
    for(i=0;i<L;i++){
        for(j=0;j<C;j++)
            printf("%2d ",mtx[i][j]);
        printf("\n");
    }

}