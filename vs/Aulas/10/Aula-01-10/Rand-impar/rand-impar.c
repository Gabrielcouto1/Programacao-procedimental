/*
Apresenta um numero impar X<N.
X eh um numero inteiro pseudo aleatorio. N eh um numero inteiro 
digitado pelo usuario, que eh bem comportado.

Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main()
{
    int n=0;
    int p=0;

    printf("\nDigite o numero N desejado:\n");
    scanf("%d",&n);

    srand(time(NULL));
    for( ; ; ){
        p=rand()%n;
        if(p%2)
            break;
    }
    printf("\n%d\n",p);

    return 0;  //Encerra o programa e retorna o valor 0
}