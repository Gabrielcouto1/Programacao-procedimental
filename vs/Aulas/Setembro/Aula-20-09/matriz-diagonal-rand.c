/*
Carrega uma matriz lxc com valores aleatorios e em seguida apresenta na tela.
o conteúdo de M é de números do conjunto de inteiros [0,7].
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <time.h> //Inclusao de biblioteca para uso da funcao time()

const int l=3;  //Quantidade de linhas da matriz
const int c=3;  //Quantidadede colunas da matriz
const int max=8;    //Numeros gerados no conjunto [0,7]

int main()
{
    int m[l][c];    //Matriz
    int i,j;

    srand(time(NULL));

    printf("\nConteudo da matriz %dx%d: \n",l,c);
    for (i=0;i<l;i++){
        for(j=0;j<c;j++){
            m[i][j]=rand()%max;
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal principal da matriz: \n");
    for (i=0;i<l;i++){
        for(j=0;j<c;j++){
            if(i==j){
                printf("%d",m[i][j]);
            }
            printf("  ");
        }
        printf("\n");
    }

    printf("\nDiagonal secundaria da matriz: \n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            if(j==c-i-1){
                printf("%d ",m[i][j]);
            }
            printf("  ");
        }
        printf("\n");
    }
    printf("\nMatriz transposta %dx%d: \n",c,l);
    for(i=0;i<c;i++){
        for(j=0;j<l;j++){
            printf("%d ",m[j][i]);
        }
        printf("\n");
    }
    return 0;  //Encerra o programa e retorna o valor 0
}