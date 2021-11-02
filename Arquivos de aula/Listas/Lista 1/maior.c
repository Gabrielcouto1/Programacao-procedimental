#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	float x, y;
	
	printf("\nInsira um valor para X:  ");
	scanf("%f",&x);
	
	printf("\nInsira um valor para Y:  ");
	scanf("%f",&y);
	
	if (x>y)
		printf("\nO valor armazenado em x é:  %.2f\n",x);
		
	else if (x<y)
			printf("\nO valor armazenado em y é:  %.2f\n",y);
			
		else if(x==y)
			printf("\nO valor de x=%.2f é igual ao valor de y=%.2f\n",x,y);
	
	
	return 0;
}
