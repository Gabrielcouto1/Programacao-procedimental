#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C

const int o=5;
int main()
{
	int i,j;
    char c;
    c='A';

    printf("      1   2   3   4   5");
    for (i=0;i<o;i++){
        printf("\n    ");
        for (j=0;j<o;j++){
            printf("+---");
            if (j==o-1)
                printf("+");
        }
        printf("\n");

        printf("%c   ",c);
        c++;

        for(j=0;j<o;j++){
            printf("|   ");
            if (j==o-1)
                printf("|");
        }
    }
    printf("\n    +---+---+---+---+---+");
    
	return 0;  //Encerra o programa e retorna o valor 0
}