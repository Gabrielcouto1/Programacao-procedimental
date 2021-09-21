#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
    int x=0,y=0,i=0,soma=0;
    
    printf("Insira números naturais x e y, para estabelecer o intervalo (x,y):  \n");
    scanf("%d %d",&x,&y);
    
    i=x;
    if (x>y){
        for (i=y+1;i<x;i++){
            if (i%2!=0){
                soma=soma+i;
            }   
            else{
                soma=soma;
            }
            
        }
    }
    else if (y>x){
        for (i=x+1;i<y;i++){
            if(i%2!=0){
                soma=soma+i;
            }
        }
    }
    else if(x==y){
            if(x%2!=0){
            soma=x;
        }
    }
    
    
    if (x>y){
    	printf("\nA soma dos números ímpares contidos no intervalo (%d,%d) é igual a %d\n",y,x,soma);
	}
	else if (x<y){
		printf("\nA soma dos números ímpares contidos no intervalo (%d,%d) é igual a %d\n",x,y,soma);
	}
    else if (x==y){
    	if (soma!=0){
    		printf("\nOs números digitados são iguais e é ímpar, com o valor %d\n",soma);
		}
		else {
			printf("\nOs números digitados são iguais e não ímpar.");
		}
	}
    
    return 0;   
}

