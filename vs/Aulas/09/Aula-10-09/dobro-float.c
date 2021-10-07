/* 
Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca para verificação de dígitos

const int max=20;   //Definicao do tamanho fixo do array

int main()
{
	char n[max];    //Array usado para capturar o numero    
    double numb=0;     //Numero armazenado na
    int i;          //Contador utilizado no for
	char err=0;       //Indica se ocorreu algum erro
    char virgula=0;     //Indica se tem ',' ou '.'

    printf("Digite um numero que deseja saber o dobro: ");
    scanf("%s",n);

    for (i=(n[0]=='-')? 1:0;((i<max)&&(n[i]!='\0'));i++){ //if (n[0]=='-'){ i=1; } else { i=0; }

        if (n[i]==','||n[i]=='.'){

            if (virgula==0){
                n[i]='.'; 
                virgula=1;
            }
            else {
                err=1;
                n[i]='.';
            }
        }
        else if (isdigit (n[i])==0){
            err=1;
        }
    }

    if(err!=0){
        printf("%s nao eh um numero.\n",n);
        return 1;
    }

    if (i==max){
        printf("\nDigite um numero com menos digitos.\n");
        return 3;
    }

    numb=atof(n);
    printf("\n O dobro de %.2f eh %.2f\n",numb,numb*2);
    
	return 0;  //Encerra o programa e retorna o valor 0
}