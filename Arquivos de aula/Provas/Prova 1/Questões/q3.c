/*  
O programa captura o valor de N e M, maiores que 0 e inseridos pelo usuário. 
O programa realiza N operações de multiplicação por M e apresenta a somatória.

Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> 						//Inclusão de biblioteca de funcoes basicas em C
#include <locale.h> 					//Inclusão de biblioteca de linguagens

int main()
{
	setlocale(LC_ALL, "Portuguese"); 	// Declaração de idioma usado, para utilização de acentos.
	
	int n=0;							//Variável que armazenará o primeiro valor inserido pelo usuário
	int m=0;							//Variável que armazenará o primeiro valor inserido pelo usuário
	int c=0;							//Contador utilizado no laço de repetição
	int x=0;							//Variável auxiliar para armazenar o valor temporário no laço while
	int t=0;							//Variável que armazenará o valor da somatória das multiplicações no laço while
	
	printf("\nInsira o valor para N: ");
	scanf("%d",&n); 					//Captura o valor de N
	
	printf("\nInsira o valor para M: ");
	scanf("%d",&m); 					//Captura o valor de M
	
	while (c<n){						//Laço while que realiza as operações enquanto o contador for menor que N
		x=x+m;							
		t=t+x;
		c++;
		}
		
	printf("\nc= %d   t=%d\n",c,t);		//Escreve na tela os valores do contador e da somatória

	return 0;  							//Encerra o programa e retorna o valor 0
}
