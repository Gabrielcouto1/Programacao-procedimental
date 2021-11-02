/* Apresentar o resultado de N lançamentos pseudoaleatórios de uma roleta que possui q números(ambos digitados pelo usuário).
O programa deve apresentar a qtd de vezes que cada número da roleta foi sorteado.
N é um número natural e digitado pelo usuário.
O número do resultado é apresentado com 5 números por linha.
Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens



int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.

	int n=0; // Número de lançamentos digitado pelo usuário
	int l=0; // Variável que dirá qual número da roleta caiu
	int c; // Contador usado para zerar o vetor de números da roleta
	int t=1; //Contador auxiliar para escrever 5 números por linha no final
	int q=0; // Quantidade de números na roleta
	
	printf("Insira a quantidade de números presentes na roleta:  ");
	scanf("%d",&q);
	
	int r[q]; // Números da roleta

	for(c=0;c<q;c++){ //Zerar todos valores do vetor r
		r[c]=0;
	}
	printf("\nInsira um número natural N de vezes que a roleta irá rodar:  ");
	scanf("%d",&n);

	srand(time(NULL)); // Pega a seed do horario do computador
	
	printf("\nNúmero de lançamentos da roleta:  %d\n\n",n);
	
	for(n;n>0;n--){ // Verifica quantas vezes cada número foi sorteado
		l=rand()%q;
		r[l]++;
	}
	
	l=0;
	while (l<q){ // Condições a serem seguidas e testadas para imprimir a quantidade certa de resultados por linha na tela
		if (q>=10){
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
