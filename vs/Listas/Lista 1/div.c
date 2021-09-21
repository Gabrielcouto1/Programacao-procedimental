#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	system("cls");
	
	float x,y,div;
	
	printf("Insira um valor para o dividendo:  ");
	scanf("%f",&x);
	
	printf("\nInsira um valor para o divisor:  ");
	scanf("%f",&y);
	
	if (y==0){
		printf("\nO divisor informado é igual a 0, não é possível dividir por 0.\nInsira outros valores\n\n");
		system("pause");  
		return main();
	}
	else {
		div= x/y;
		printf("\nO quociente da divisão %.2f/%.2f é igual a %.2f\n",x, y, div);
	}		
	return 0;	
}
