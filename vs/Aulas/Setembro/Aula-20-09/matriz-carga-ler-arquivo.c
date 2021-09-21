/*
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <time.h> //Inclusao de biblioteca para uso da funcao time()

const int l=10; //Qtd de linhas da matriz
const int c=10; //Qtd de colunas da matriz

int main()
{
    int m[l][c];    //Matriz    
    int v=0;    //Variavel inserida pelo usuario ou lida no arquivo destino 
    int i,j;

    for (i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d",&v);
            m[i][j]=v;  
        }
    }

    for (i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    return 0;  //Encerra o programa e retorna o valor 0
}