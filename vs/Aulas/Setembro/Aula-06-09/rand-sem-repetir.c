/* 

Por Gabriel Couto de Freitas em 2021 */

#include <stdio.h> //Inclusão de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusão de biblioteca de funcoes basicas em C
#include <time.h> //Inclusão de biblioteca para uso da função time()
#include <locale.h> //Inclusão de biblioteca de linguagens

#define t 10
#define max 21

int main()
{
	setlocale(LC_ALL, "Portuguese"); // Declaração de idioma usado, para utilização de acentos.
	
    int s[t];     // String para armazenar os numeros aleatorios
    int r=0;      // Numero aleatorio
    int qrn=0;    // Quantidade de numeros na string
    int rep=0;    // Indica se r já existe na string
    int i, j;     // contadores do for
    
    for (i=0;i<t;i++){
        s[i]=-1;
    }

	srand(time(NULL));
	
	for (i=0;i<t;i++){
        r=rand()%max;

        for (j=0;j<t;j++){
            if (r==s[j]){
                rep=1;
                continue;
            }    
        }
        if (rep){
            rep=0;
            i--;
        }
        else {
            s[qrn]=r;
            qrn++;
        }
    }
    for (i=0;i<t;i++){
        printf("Posicao %d= %d\n",i+1,s[i]);
    }

    printf("\n");
	return 0;  //Encerra o programa e retorna o valor 0
}