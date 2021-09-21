#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> 

const int o=5;

int main()
{
	int coluna,linha;
    int coluna_ataque=0;
    char linha_ataque='0';
    char c='A';

    printf("      1   2   3   4   5\n");
    for (coluna=0;coluna<=o;coluna++){
        printf("    +---+---+---+---+---+\n");
        if(coluna<o)
            printf("%c   ",c);
        c++;
        for (linha=0;linha<o&&coluna<o;linha++){
            printf("|   ");
        }
            if(coluna<o)
            printf("|\n");
    }
    c='A';

    printf("\nInsira a coluna que deseja atacar: ");
    scanf("%d",&coluna_ataque);

    printf("\nInsira a linha que deseja atacar: ");
    scanf(" %c",&linha_ataque);
    linha_ataque= toupper(linha_ataque);

    printf("      1   2   3   4   5\n");
    for (coluna=0;coluna<=o;coluna++){
        printf("    +---+---+---+---+---+\n");
        if(coluna<o)
            printf("%c   ",c);
        c++;
        for (linha=0;linha<o&&coluna<o;linha++){
            if(linha==coluna_ataque-1&&c==linha_ataque+1){
                printf("| W ");
            }
            else{
                 printf("|   ");
            }

        }
            if(coluna<o)
            printf("|\n");
    }
    
	return 0;  //Encerra o programa e retorna o valor 0
}