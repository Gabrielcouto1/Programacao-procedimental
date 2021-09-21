#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca de funcoes usando caracteres e manipulacao de string    
#include <time.h> //Inclusao de biblioteca para usar a hora atual do computador

const int o=5;      //Tamanho da matriz que apresenta o oceano  
const int num_navio=3;  //Quantidade de navios que serao gerados aleatoriamente

int main()
{
    int i,j,c;

    
    for(i=0;i<=o;i++){
        for(j=0;j<o;j++){
            printf("+---");
            if(j==o-1){
                printf("+");
            }
        }
         printf("\n");
        if(i!=o){
        for(c=0;c<o;c++){
            printf("|   ");
            if(c==o-1){
                printf("|");
            }
        } 
        printf("\n");
        }
    }



	return 0;  //Encerra o programa e retorna o valor 0
}
