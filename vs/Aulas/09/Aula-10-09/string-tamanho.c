/* 
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <string.h> //Inclusao de biblioteca de funcoes de string

const int max=20;

int main()
{
    char s[max];

    printf("Digite uma string\n");
    scanf("%20[^\n]",s);

    printf("-->%s\n",s);
	printf("Tamanho da string: %ld\n",strlen(s));

	return 0;  //Encerra o programa e retorna o valor 0
}