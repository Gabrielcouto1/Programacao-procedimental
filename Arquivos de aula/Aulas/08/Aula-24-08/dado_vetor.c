/* Programa para mostrar quantas vezes cada face de um dado caiu, a partir de rolagens aleatórias baseadas no horário do computador.
Gabriel Couto de Freitas 2021 */
#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <locale.h> //Inclusao de biblioteca de linguagens
#include <time.h> //Inclusao de biblioteca para uso da função time()

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	int n=0; // Valor definido pelo usuario para o numero de rolagens do dado
	int l=0; // Variavel para identificar qual lado do dado caiu
	int d[6]; //Vetor usado para determinar cada face do lado
	int c; // Contador usado para zerar o vetor
	
	for(c=0;c<6;c++){ // Zerar todas unidades do vetor
		d[c]=0;
	}
	
	printf("Insira o numero de lancamentos= ");
	scanf("%d",&n);
	
	srand(time(NULL)); // Pega a seed do horario do computador
	
	printf("\nNumero de lancamentos = %d\n",n);
	
	for(n;n>0;n--){ // Verifica quantas vezes cada face caiu 
		l=rand()%6;
		d[l]++;
		}
		
	for(l=0;l<6;l++){ //Escreve na tela quantas vezes cada face caiu
		printf("Número de %d rodados: %d\n",l+1,d[l]);
	}
	
	return 0;  //Encerra o programa e retorna o valor 0
}
