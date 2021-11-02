/* 
Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <time.h> //Inclusao de biblioteca para uso da funcao time()
#include <ctype.h> //Inclusao de biblioteca para verificação de dígitos

const int max=20;   //Definicao do tamanho fixo do array

int main()
{
	char n[max];    //Array usado para capturar o numero    
    int numb=0;     //
    int i,c;          //Contador utilizado no for
	
    printf("Digite um numero: ");
    scanf("%s",n);

    c=(n[0]=='-')? 1:0;  //if (n[0]=='-'){ i=1; } else { i=0; }
    
    for (i=c;((i<max)&&(n[i]!='\0'));i++){
        if (isdigit (n[i])==0){
            printf("\n%s nao e um numero.\n",n);
            return 3;
        }
    }
    if (i==max){
        printf("\nDigite um numero com menos digitos.\n");
        return 5;
    }

    numb=atoi(n);
    printf("\n O dobro de %d eh %d\n",numb,numb*2);
    
	return 0;  //Encerra o programa e retorna o valor 0
}