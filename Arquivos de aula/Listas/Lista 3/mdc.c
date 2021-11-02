#include <stdio.h> //Insercao de biblioteca de funcoes print e scan
#include <locale.h> // Insercao de biblioteca de linguagens

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	int a=0;                            //Declaracao da variavel usada para o dividendo
	int b=0;                           //Declaracao da variavel usada para o divisor
	int r=0;                          //Declaracao da variavel usada para o resto
	int a_1=0;                       //Declaracao da variavel auxiliar do dividendo usada no laco while
	int b_1=0;                      //Declaracao da variavel auxiliar do divisor usada no laco while
	
	printf("Insira um valor para o dividendo A:  \n"); 
	scanf("%d",&a);                   //Atribuicao de valor do numero digitado ao dividendo
	
	printf("Insira um valor para o divisor B(deve ser menor que A):  \n");
	scanf("%d",&b);                  //Atribuicao de valor do numero digitado ao divisor (menor que o dividendo)
	
	if (b>a){                       // Verifica a primeira condicao dada no problema, se a<b
		printf("\n0");
		return 0;                   //Encerra o programa e retorna o valor 0
	}
	else if (b==0){                // Verifica a existencia de uma indeterminacao matematica, onde o divisor eh igual a 0
		printf("\nNao é possível realizar divisão por 0.\n");
		return 3;                  // Encerra o programa e retorna o valor 3
	}
	else if ((a>b)&&(b!=0)){       // Verifica se as duas principais condicoes propostas no programa sao satisfeitas e da continuacao ao codigo
		a_1=a;                    //Atribuicao do valor inserido a variavel auxiliar do dividendo
		b_1=b;                   //Atribuicao do valor inserido a variavel auxiliar do divisor
		
		do
			{
				r=a_1%b_1;        //Realiza a divisao de a por b e retorna o valor do resto da divisao 	
				a_1=b_1;		 //Atribui o valor do divisor ao dividendo	
				b_1=r;			//Atribui o valor do resto ao divisor
			}
		while (r!=0);          //Verifica se o resto eh diferente de 0, se for, volta ao loop
		
		printf("\nO MDC entre %d e %d é igual a: %d\n",a,b,a_1); 		//Escreve na tela o valor do MDC
	}
	return 1;			//Encerra o programa e retorna o valor 1
}
