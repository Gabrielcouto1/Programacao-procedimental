/* 

Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens

#define tamanho 20
int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
    char string[tamanho];

	printf("Digite algo: \n");
    scanf("%[^\n]",string);
	
	printf("%s",string);
	return 0;  //Encerra o programa e retorna o valor 0
}
