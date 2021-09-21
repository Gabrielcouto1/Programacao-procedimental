#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca de funcoes usando caracteres e manipulacao de string    

#define PLAY 0  //Definicao de "PLAY" para alterar facilmente o modo de execucao do codigo
#define CORR 1  //Definicao de "CORR" para alterar facilmente o modo de execucao do codigo

const int o=5;  //Tamanho da matriz que apresenta o oceano  
const int s=3;  //Quantidade de submarinos que serao gerados aleatoriamente
const int d=0;  //Quantidade de destruidores que serao gerados aleatoriamente
const int t=6;  //Quantidade de torpedos que o usuario podera disparar

const int MD=CORR;     //Variavel MD que dira se o programa sera jogado(PLAY) ou corrigido(CORR)

int main()
{
    char oceano[o][o];  //Matriz oceano de ordem "o" preestabelecida
    int i,j,k,h;    //Contadores usados para imprimir a matriz na tela
    char linha= 'A'; //Variavel usada para imprimir a letra das linhas na tela
    int sub=0;  //Contador usado para determinar a posicao dos submarinos
    int dest=0; //Contador usado para determinar a posicao dos destruidores
    int dir_dest=0; //Determina se o destruidor tera duas casas horizontais ou verticais
    int coluna_ataque=0; //Armazena a coluna que o usuario quer atacar
    char linha_ataque=' ';//Armazena a linha que o usuario quer atacar

    for (i=0;i<o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<o;j++){
            oceano[i][j]=' ';
        }
    }

    if(MD==PLAY){   //Impressao do oceano inicial caso modo de jogo for PLAY
        for(i=0;i<=o;i++){      
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
    }

	while(sub<s){ //Determina a posicao dos submarinos
        i=rand()%o;
        j=rand()%o;
        if(oceano[i][j]==' '){
            oceano[i][j]='S';
            sub++;
        }
    }

    while (dest<d){//Determina a posicao dos destruidores
        i=rand()%o;
        j=rand()%o;
        dir_dest=rand()%2;
        if(dir_dest==0){    //O destruidor tem 2 casas verticais 
            if(oceano[i][j]==' '&&oceano[i+1][j]==' '){
            oceano[i][j]='D';
            oceano[i+1][j]='D';
            dest++;
            }
        }
        else{               //O destruidor tem 2 casas horizontais
            if(oceano[i][j]==' '&&oceano[i][j+1]==' '){
            oceano[i][j]='D';
            oceano[i][j+1]='D';
            dest++;
            }
        }
        
    }

    if (MD==CORR){  //Impressao do oceano com os submarinos na tela
        linha='A';
        for(i=0;i<=o;i++){      
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
    }
     
    return 0;  //Encerra o programa e retorna o valor 0
}
