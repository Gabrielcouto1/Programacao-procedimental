/* 
Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens

#define t 30 //Tamanho do array

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	unsigned char s[t]; //String para armazenar o nome	
	
	scanf ("%[^\n]",s); // Captura tudo com espaços brancos
	
	printf("Nome digitado = %s\n",s);

	return 0;  //Encerra o programa e retorna o valor 0
}
