/*
Carrega uma matriz lxc com valores aleatorios e em seguida apresenta na tela.
o conteúdo de M é de números do conjunto de inteiros [0,7].
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <time.h> //Inclusao de biblioteca para uso da funcao time()

const int l=3;//Quantidade de linhas da matriz
const int c=3;//Quantidade de colunas da matriz
const int max=8;//Numeros gerados no conjunto [0,7]
int main()
{
    int m[l][c];    //Matriz
    int v=0;
    int i,j;

    srand(time(NULL));

    printf("Conteudo da matriz %dx%d: \n",l,c);
    for (i=0;i<l;i++){
        for(j=0;j<c;j++){
            m[i][j]=rand()%max;
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    
    return 0;  //Encerra o programa e retorna o valor 0
}

void