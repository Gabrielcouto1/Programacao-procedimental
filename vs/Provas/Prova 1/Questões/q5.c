/* 
O programa armazena em um array Q números aleatórios baseados no horário atual do computador.
Em seguida apresenta os números na ordem em que foram obtidos.
Apresenta os números na ordem contrária em que foram obtidos.
Apresenta a soma de todos números ímpares obtidos no sorteio.

Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens

#define q 10

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	int n[q];				//Array com tamanho 10, definido previamente, que irá armazenar os valores aleatórios
	int c;					//Contador auxiliar utilizado nos laços de repetição	
	int s=0;				//Variável que irá armazenar os valores ímpares gerados
	
	srand(time(NULL));		//Estabelecendo a semente para a função rand() com o valor em segundos da hora do computador
	
	for (c=0;c<q;c++){		//Laço de repetição que será usado para as seguintes operações:
		n[c]=0;				//Zera todos elementos do array
		
		n[c]=rand()%24;		//Atribui um valor aleatório para cada elemento da array
		
		printf("O %dº número sorteado é:  %d\n",c+1,n[c]);		//Escreve na tela cada valor do array, na ordem que foi sorteado
		
		if(n[c]%2!=0){ 			//Verifica se cada valor da array é ímpar
			s=s+n[c];			//Se for ímpar armazena na variável da soma dos números ímpares
		}
	}
	
	printf("\n\n");
	
	for (c=q;c>0;c--){			//Laço que foi usado para apresentar a ordem contrária dos números sorteados
		printf("O %dº número sorteado é:  %d\n",c,n[c-1]);
	}
	
	printf("\n\nA soma dos números ímpares sorteados é: %d\n",s);			//Apresenta a soma dos números ímpares sorteados
	
	
	return 0;  //Encerra o programa e retorna o valor 0
}
