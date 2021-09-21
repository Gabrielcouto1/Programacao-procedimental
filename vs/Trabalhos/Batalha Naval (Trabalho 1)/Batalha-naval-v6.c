#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca de funcoes usando caracteres e manipulacao de string    
#include <time.h> //Inclusao de biblioteca para usar a hora atual do computador

#define PLAY 0  //Definicao de "PLAY" para alterar facilmente o modo de execucao do codigo
#define CORR 1  //Definicao de "CORR" para alterar facilmente o modo de execucao do codigo

const int o=5;      //Tamanho da matriz que apresenta o oceano  
const int qtd_navio=3;  //Quantidade de navios que serao gerados aleatoriamente
const int MD=PLAY;     //Variavel MD que dira se o programa sera jogado(PLAY) ou corrigido(CORR)

int main()
{
    int l=o,c=o;
    char oceano[l][c];
    int i,j,k,h;
    char linha= 'A';
    int navio=0;
    //i=linha j=coluna
    //Agora tem que: colocar pra imprimir o oceano com os navios so se md==corr; scanear onde o usuario deseja atacar; usar switch case para transformar em int
    srand(time(NULL));

    for(i=0;i<=o;i++){      //Impressao do oceano inicial 
        if(i==0){
            printf(" ");
            for(h=0;h<o;h++){
                if(h==o-1)
                    printf("   %d\n",h+1);
                else 
                    printf("   %d",h+1);
            }
        }
        printf("  ");
        for(k=0;k<o;k++){
            printf("+---");
            if(k==o-1){
                printf("+");
            }
        }
        printf("\n");
        
        if(i!=o){
            printf("%c ",linha);
            linha++;
            for(j=0;j<o;j++){
                oceano[i][j]= ' ';
                printf("| %c ",oceano[i][j]);
                if(j==o-1)
                    printf("|");
            }
            printf("\n");
        }
    }

	while(navio<qtd_navio){
        i=rand()%o;
        j=rand()%o;
        if(oceano[i][j]==' '){
            printf("lin=%d   col=%d\n",i,j);
            oceano[i][j]='*';
            navio++;
        }
    }
    
    linha='A';
    for(i=0;i<=o;i++){      //Impressao do oceano com os navios na tela
        if(i==0){
            printf(" ");
            for(h=0;h<o;h++){
                if(h==o-1)
                    printf("   %d\n",h+1);
                else 
                    printf("   %d",h+1);
            }
        }
        printf("  ");
        for(k=0;k<o;k++){
            printf("+---");
            if(k==o-1){
                printf("+");
            }
        }
        printf("\n");
        
        if(i!=o){
            printf("%c ",linha);
            linha++;
            for(j=0;j<o;j++){
                printf("| %c ",oceano[i][j]);
                if(j==o-1)
                    printf("|");
            }
            printf("\n");
        }
    }
    return 0;  //Encerra o programa e retorna o valor 0
}
