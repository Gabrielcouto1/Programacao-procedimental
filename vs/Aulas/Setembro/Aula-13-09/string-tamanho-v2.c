/* 
Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <string.h> //Inclusao de biblioteca de funcoes de string

const int max=40;

int main()
{
    char s[max];
    int i;

    printf("Digite uma frase\n");

    for (i=0;i<(max-1);i++){
        scanf("%c",&s[i]);
        if (s[i]=='\n'){
            break;   
        }
    }
    
    if (i==(max-1)){
        
        printf("Numero de caracteres maximo excedido.\n");
        return 3;
    }

    s[i]='\0';
    printf("-->%s\n",s);
	printf("Tamanho da string: %ld\n",strlen(s));

	return 0;  //Encerra o programa e retorna o valor 0
}