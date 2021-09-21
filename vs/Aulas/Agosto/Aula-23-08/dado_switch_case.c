#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int n=0;
	int l=0;
	int d1=0;
	int d2=0;
	int d3=0;
	int d4=0;
	int d5=0;
	int d6=0;
	int t=0;
	unsigned int s=0;
	
	printf("Insira o numero de lancamentos= ");
	scanf("%d",&n);
	
	t=time(0);
	srand(t); // ou srand(time(0));
	
	printf("\nNumero de lancamentos = %d",n);
	while(n>0){
		l=rand()%6;
		switch(l){
			case 0:
				d1++;
				break;
				
			case 1:
				d2++;
				break;
				
			case 2:
				d3++;
				break;
				
			case 3:
				d4++;
				break;
				
			case 4:
				d5++;
				break;
				
			case 5:
				d6++;
				break;
		}
		
		n--;	
	}
	
	printf("\nNumero de 1 rodados= %d",d1);
	printf("\nNumero de 2 rodados= %d",d2);
	printf("\nNumero de 3 rodados= %d",d3);
	printf("\nNumero de 4 rodados= %d",d4);
	printf("\nNumero de 5 rodados= %d",d5);
	printf("\nNumero de 6 rodados= %d",d6);
	
	return 0;
}
