/* 
O programa atribui 20 valores pseudo-aleatórios entre 0 e 31 a uma array, apresenta eles e, em seguida, apresenta o maior deles.

Por Gabriel Couto de Freitas em 2021 
*/
#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens

#define q 20 //Definição do tamanho do array

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	int r[q]; //Array que será utilizada para captar os números pseudo aleatórios
	int c; //Contador que servirá para zerar os valores do array
	
	srand(time(0)); // Função time pega o horário em segundos do computador e atribui à semente do função srand
	
	for ( c = 0;c<q;c++){ //For usado para zerar o array e logo em seguida atribuir um valor pseudo aleatório a ele
		r[c]=0; // Zera cada posição do array
		r[c]=rand()%32; //Atribui um valor pseudo aleatório para cada posição do array
		
		printf("O %dº número é: %d\n",c+1,r[c]); 
		
		if (r[0]<r[c]){ // Realiza o teste para ver se o número em questao é o maior, 
			r[0]=r[c];  // se nao for, atribui esta posição ao primeiro elemento da array e repete o teste.
		}	
	}
	printf("\nO maior número obtido foi: %d\n",r[0]);
	
	return 0;  //Encerra o programa e retorna o valor 0
}
