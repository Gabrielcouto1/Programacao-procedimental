/* 
Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <time.h> //Inclusao de biblioteca para uso da funcao time()
#include <ctype.h>

#define t 20

int main()
{
    char string[t];
    int n=0;
    int i;

    printf("Digite um numero\n");
    scanf("%s",string);

    for (i=0;((i<t)&&(string[i]!='\0'));i++){
        if  ((isdigit(string[i]))==0){            //((string[i]<'0')||(string[i]>'9')){
            printf("%s: nao eh um numero\n",string);
            system("pause");
            return 3;
        } 
    }

    n=atoi(string);
    printf("\nO dobro de %d eh %d.\n",n,n*2);

    system("pause");    //Pausa o programa e pede para digitar uma tecla para continuar
	return 0;  //Encerra o programa e retorna o valor 0
}