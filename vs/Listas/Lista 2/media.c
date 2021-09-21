#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
    float n1=0,n2=0,n3=0,med=0;
    
	printf("Insira as 3 notas n1, n2 e n3 para realizar o cálculo da média final:\n");
	scanf("%f %f %f",&n1,&n2,&n3);
	
	med=((n1*2)+(n2*3)+(n3*5))/10;
	
	if(n1>100||n2>100||n3>100||n1<0||n2<0||n3<0){
		printf("\nAlguma nota inserida não está entre 0 e 100. Insira-as novamente\n");
		main();
	}
	
	if (med>=90 && med<=100){ 
		printf("\nSua nota foi %.2f. Otimo resultado!\n",med);
	}
	
	else if(med>=70&&med<90){
		printf("\nSua nota foi %.2f. Bom resultado!\n",med);
	}
	
	else if(med>=50&&med<70){
		printf("\nSua nota foi %.2f. Resultado regular.\n",med);
	}
	
	else if(med>=0&&med<50){
		printf("\nSua nota foi %.2f. Resultado ruim.\n",med);
	}
	
    return 0;   
}

