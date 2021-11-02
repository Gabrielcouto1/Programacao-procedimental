/* 
O programa recebe e armazena q idades inseridas pelo usuerio. Logo em seguida, apresenta a soma e a media entre as idades.
Se o usuerio inserir uma idade menor ou igual a 0, o programa mostra a soma e media das idades inseridas ate o momento.

Por Gabriel Couto de Freitas em 2021 
*/
#include <stdio.h> //Incluseo de biblioteca de funcoes basicas em C
#include <stdlib.h> //Incluseo de biblioteca de funcoes basicas em C
#include <locale.h> //Incluseo de biblioteca de linguagens

#define q 4 //O usuerio neo necessariamente ire digitar 10 idades. Se for mudado aqui o valor, o programa se adaptare para o novo nem de idades.

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaraeeo de idioma usado, para utilizaeeo de acentos.
	
	int i[q]; //Array de, a principio, tamanho 10, que pode ser alterado fora da funcao main, se necessario
	int c; // Contador que servira para zerar todos elementos do array 
	float s=0; // Soma de todas idades inseridas
		
	printf("Insira %d Idades:\n",q);
	
	for (c=0;c<q;c++){ //O laco ira zerar os elementos do array, atribuir um valor inserido pelo usuario e +:
		i[c]=0;	//Zera os elementos da array	
		scanf("%d",&i[c]); //Atribui um valor inserido pelo usuerio ao array
  	
		if (i[c]<=0){ // Verifica se o usuerio digita um nem<=0, o programa para e mostra a media das idades inseridas ate aqui
			printf("\nVoce digitou um nemero menor ou igual a 0.\n");
			printf("A soma das idades inseridas ate agora e %.2f e a media d e igual a %.2f\n",s,s/c); //Imprime o valor da soma e media ate o momento
			return 3; //Encerra o programa e retorna o valor 3
		}
		
		s+=i[c]; // Soma todos os valores atribuedos no array
	}
	
	printf("\n\nA soma das idades e:%.2f\nA media entre as idades e:%.2f\n",s,s/q); // Apresenta os valores da soma e da media

	return 0;  //Encerra o programa e retorna o valor 0
}
