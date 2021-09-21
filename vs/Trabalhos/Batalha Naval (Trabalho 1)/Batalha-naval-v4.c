#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca de funcoes usando caracteres e manipulacao de string    
#include <time.h> //Inclusao de biblioteca para usar a hora atual do computador

const int o=5;      //Tamanho da matriz que apresenta o oceano  
const int num_navio=3;  //Quantidade de navios que serao gerados aleatoriamente

int main()
{
    int i;                  //Variavel para contar as colunas   
    int j;                  //Variavel para contar as linhas
    int coluna_ataque=0;    //Variavel que coleta a coluna que o usuario deseja atacar  
    char linha_ataque='0';  //Variavel que colea a linha que o usuario deseja atacar
    char c='A';             //Variavel utilizada para coletar 
    char n_l[num_navio];    //Array que armazena a posição dos navios sorteados nas linhas
    int n_c[num_navio];     //Array que armazena a posição dos navios sorteados nas colunas 
    int r=0;                //Variavel auxiliar que servirá para armazenar temporariamente o numero aleatorio gerado
    int qtd_num_rand=0;     //Variavel auxiliar utilizada nos laços de repetição para verificar quantos numeros nao repetidos foram gerados
    int rep=0;              //Variavel auxiliar utilizada para verificar se o numero gerado é repetido ou nao

    srand(time(NULL));

    printf("      1   2   3   4   5\n");
    for (i=0;i<=o;i++){              //Coloca o oceano inicial na tela
        printf("    +---+---+---+---+---+\n");
        if(i<o)
            printf("%c   ",c);
        c++;
        for (j=0;j<o&&i<o;j++){
            printf("|   ");
        }
            if(i<o)
            printf("|\n");
    }
    
    c='A';
    for (i=0;i<num_navio;i++){      //Sorteia 3 numeros para a coluna dos navios 
        r=(rand()%5)+1;
        
        for(j=0;j<num_navio;j++){
            if(r==n_c[j]){
                rep=1;
                continue;
            }
        }
        if(rep){
            rep=0;
            i--;
        }
        else{
            n_c[qtd_num_rand]=r;
            qtd_num_rand++;
        }
    }

    qtd_num_rand=0;                 //Retorna o valor 0 inicial para a variavel auxiliar para sorteio de numeros aleatorios

    for(i=0;i<num_navio;i++){       //Sorteia 3 numeros para a linha dos navios
        r=(rand()%5)+1;

        for(j=0;j<num_navio;j++){
            if(r==n_l[j]){
                rep=1;
                continue;
            }
        }
        if(rep){
            rep=0;
            i--;
        }
        else{
            n_l[qtd_num_rand]=r;
            qtd_num_rand++;
        }
    }
   
    for(i=0;i<num_navio;i++){       //Transforma os numeros sorteados em caractere (A-E)
        switch (n_l[i]){
            case 1:
                n_l[i]='A';
                break;
            case 2:
                n_l[i]='B';
                break;
            case 3:
                n_l[i]='C';
                break;
            case 4:
                n_l[i]='D';
                break;
            case 5:
                n_l[i]='E';
                break; 
        }
    }
    
    for(i=0;i<num_navio;i++){       //Imprime na tela a localização de cada navio
        printf("(%c,%d)  ",n_l[i],n_c[i]);
    }
    return 8; 

    printf("\nInsira a linha que deseja atacar(de A-E): "); //Captura a linha que o usuario deseja atacar
        scanf(" %c",&linha_ataque);
        linha_ataque= toupper(linha_ataque);

            if(linha_ataque>'E'||linha_ataque<'A'){
                printf("Voce digitou uma linha inexistente.\n");
                return 3;
            }

    printf("\nInsira a coluna que deseja atacar(de 1-5): "); //Captura a coluna que o usuario deseja atacar
            scanf("%d",&coluna_ataque);
    
            if(coluna_ataque>5||coluna_ataque<1){
                printf("Voce digitou uma coluna inexistente.\n");
                return 5;
            }

    printf("      1   2   3   4   5\n");
    for (i=0;i<=o;i++){
        printf("    +---+---+---+---+---+\n");
        if(i<o)
            printf("%c   ",c);
        c++;
        for (j=0;j<o&&i<o;j++){
            if(j==coluna_ataque-1&&c==linha_ataque+1){
                printf("| W ");
            }
            else{
                 printf("|   ");
            }

        }
            if(i<o)
            printf("|\n");
    }
    
	return 0;  //Encerra o programa e retorna o valor 0
}