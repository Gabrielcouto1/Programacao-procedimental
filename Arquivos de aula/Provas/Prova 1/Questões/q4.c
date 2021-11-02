/* 
O programa captura valores digitados pelo usuário e apresenta a média entre eles.
O programa só irá parar quando o usuário digitar o valor 0.

Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C

#include <locale.h> //Inclusão de biblioteca de linguagens

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	int n=1;						//Variável que irá capturar o número digitado pelo usuário.
	int c=0;						//Variável auxiliar que servirá para contar a quantidade de números digitados pelo usuário
	float s=0;						//Variável que irá armazenar a soma de todos números digitados pelo usuário
	float med=0;					//Variável que irá armazenar a média de todos números digitados pelo usuário
	
	printf("Insira números que você deseja calcular a média entre. Quando quiser encerrar, digite o número 0.\n");
	
	while (n!=0){					//Laço de repetição para verificar se o número inserido é diferente de 0
		scanf("%d",&n);				//Cada vez que não for 0, ele captura um novo número
		
		if (n!=0){					//Verifica se, depois da inserção do número ele é diferente de 0	
			s=s+n;					//Se não for 0, atribui o número à somatória que irá ser usada no cálculo da média
			c++;					//Contador que representa a quantidade de números diferentes de 0 inseridos
		}
	}
	
	if(c==0){						//Verifica se o primeiro número inserido é igual a 0
	printf("\nVocê não digitou nenhum número além do 0.\n");
	return 3;						//Encerra o programa e apresenta o valor 3, já que é impossível dividir por 0 
	}
	
	med=s/c;						//Calcula a média dos números inseridos, que é a somatória dividido pela quantidade de números
	printf("A média dos números digitados é igual a: %.2f\n",med);	//Apresenta a média com 2 casas decimais

	return 0;  //Encerra o programa e retorna o valor 0
}
