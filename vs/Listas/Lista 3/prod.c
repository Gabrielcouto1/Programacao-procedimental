#include <stdio.h>//Inclusao da biblioteca 
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
	int x=0; //Declaracao do primeiro numero a ser multiplicado
	int y=0; //Declaracao do segundo numero a ser multiplicado
	int c=0; //Declaracao do contador a ser utilizado nos lacos while
	int p=0; //Declaracao do produto da multiplicacao
	
	printf("Insira um valor para o multiplicando X:  ");
	scanf("%d",&x);//Atribuicao de valor ao primeiro numero a ser multiplicado

	printf("\nInsira um valor para o multiplicador Y:  ");
	scanf("%d",&y);//Atribuicao de valor ao segundo numero a ser multiplicado

	if ((x>=0)&&(y>=0)){//Verificacao de teste para ver se os dois numeros inseridos sao positivos
	
			printf("\nx=%d\n",x);//Escrever na tela o valor de x, puramente visual
			printf("y=%d\n",y);//Escrever na tela o valor de x, puramente visual
			
			if (x>y){//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o primeiro numero eh maior em modulo
		
				while (c<y){//Realizacao do laco while com menor de iteracoes para soma sucessiva
					p=p+x;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
					c++;//c=c+1
					printf("\n%d * %d = %d\n",x,y,p);
				}
			printf("%d * %d = %d",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
			}
			else{//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o segundo numero eh maior em modulo
				while (c<x){//Realizacao do laco while com menor de iteracoes para soma sucessiva
					p=p+y;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
					c++;//c=c+1
					printf("\n%d * %d = %d\n",x,y,p);
				}
				printf("%d * %d = %d",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
			}
	}
	else if((x<0)&&(y>=0)) {//Teste realizado a fim de verificar se o primeiro valor eh negativo e o segundo eh positivo
			printf("\nx=%d\n",x);//Escrever na tela o valor de x, puramente visual
			printf("y=%d\n",y);//Escrever na tela o valor de x, puramente visual
 			
 			if ((x*-1)>y){//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o primeiro numero eh maior em modulo
			 	while (c<y){//Realizacao do laco while com menor de iteracoes para soma sucessiva
					p=p+x;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
					c++;//c=c+1
				}
				printf("\n%d * %d = %d\n",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
			}
			else{//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o segundo numero eh maior em modulo
				c=0;
				while (c>x){//Realizacao do laco while com menor de iteracoes para soma sucessiva
					p=p+y;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
					c--;//c=c-1
				}
				printf("\n%d * %d = -%d\n",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
			}
}
	else if((x>=0)&&(y<0)){//Teste realizado a fim de verificar se o primeiro valor eh positivo e o segundo eh negativo
		printf("\nx=%d\n",x);//Escrever na tela o valor de x, puramente visual
		printf("y=%d\n",y);//Escrever na tela o valor de x, puramente visual
		
		if((y*-1)>x){//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o primeiro numero eh maior em modulo
			while (c<x){//Realizacao do laco while com menor de iteracoes para soma sucessiva
				p=p+y;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
				c++;//c=c+1
			}
			printf("\n%d * %d = %d\n",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
		}
		else{//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o segundo numero eh maior em modulo
			while (c>y){//Realizacao do laco while com menor de iteracoes para soma sucessiva
				p=p+x;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
				c--;//c=c-1
			}
			printf("\n%d * %d = -%d\n",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
		}
	}
	else if ((x<0)&&(y<0)){//Teste realizado a fim de verificar se os valores sao negativos
		printf("\nx=%d\n",x);//Escrever na tela o valor de x, puramente visual
		printf("y=%d\n",y);//Escrever na tela o valor de x, puramente visual
		
		if (x<y){//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o primeiro numero eh maior em modulo
			while (c>y){//Realizacao do laco while com menor de iteracoes para soma sucessiva
				p=p+x;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
				c--;//c=c-1
			}
			p=p*-1;
			printf("\n%d * %d = %d\n",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
		}
		else{//Teste para reduzir ao maximo o numero de iteracoes no laco while, quando o segundo numero eh maior em modulo
			while (c>x){//Realizacao do laco while com menor de iteracoes para soma sucessiva
				p=p+y;//Atribuicao de valor a variavel dedicada ao produto da multiplicacao
				c--;//c=c-1
			}
			p=p*-1;
			printf("\n%d * %d = %d\n",x,y,p);//Escrita na tela o valor da primeira variavel, da segunda, e o valor da multiplicacao entre elas
		}
	}
	return 0; //Encerra o programa e retorna o valor 0
}
