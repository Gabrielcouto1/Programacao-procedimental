/* Apresentar o resultado de N lançamentos pseudoaleatórios de uma roleta que possui q números(ambos digitados pelo usuário).
O programa deve apresentar a qtd de vezes que cada número da roleta foi sorteado.
N é um número natural e digitado pelo usuário.
O número do resultado é apresentado com 5 números por linha.
Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens

#define q 50

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	

	int n=0; // Número de lançamentos digitado pelo usuário
	int l=0; // Variável que dirá qual número da roleta caiu
	int c; // Contador usado para zerar o vetor de números da roleta
	int t=1; //Contador auxiliar para escrever 5 números por linha no final
	int r[q]; // Números da roleta

	for(c=0;c<q;c++){ //Zerar todos valores do vetor r
		r[c]=0;
	}

	printf("Insira um número natural N de vezes que a roleta irá rodar:  ");
	scanf("%d",&n);

	srand(time(NULL)); // Pega a seed do horario do computador
	
	printf("\nNúmero de lançamentos da roleta:  %d\n\n",n);
	
	for(n;n>0;n--){ // Verifica quantas vezes cada número foi sorteado
		l=rand()%q;
		r[l]++;
	}
	l=0;
	while (l<q){
		while(l<9){
			if(t%5!=0){
				printf("Núm 0%d:  %d    ",l+1,r[l]);
			}
			else if (t%5==0){
				printf("Núm 0%d:  %d    \n",l+1,r[l]);
			}
			l++;
			t++;
		}
		if(t%5!=0){
			printf("Núm %d:  %d    ",l+1,r[l]);
		}
		else if (t%5==0){
			printf("Núm %d:  %d    \n",l+1,r[l]);
		}
		l++;
		t++;
	}
	
	return 0;  //Encerra o programa e retorna o valor 0
}
