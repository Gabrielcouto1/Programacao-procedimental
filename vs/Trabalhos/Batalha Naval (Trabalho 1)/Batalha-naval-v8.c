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
    int i_1[s],j_1[s];  //Armazenam a posicao dos submarinos
    int i_2[d],j_2[d];  //Armazenam a posicao dos destruidores
    int dir_dest=0; //Determina se o destruidor tera duas casas horizontais ou verticais
    int qtd_sub=s;  //Qtd de submarinos restantes
    int qtd_dest=d; //Qtd de destruidores restantes
    int qtd_tor=t;  //Qtd de torpedos restantes
    int coluna_ataque=0;    //Coluna que o usuario deseja atacar  
    char linha_ataque=' ';  //Linha que o usuario deseja atacar
    int linha_ataque_1=0;   //Linha que o usuario deseja atacar 
    int acerto=0;   //Determina se o usuario acertou o disparo
    //ATACAR DESTRUIDOR
    for (i=0;i<o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<o;j++){
            oceano[i][j]=' ';
        }
    }

    if(MD==PLAY){ //Impressao do oceano inicial caso modo de jogo for PLAY
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
        linha='A';
    }

	while(sub<s){ //Determina a posicao dos submarinos
        i_1[sub]=rand()%o;
        j_1[sub]=rand()%o;
        if(oceano[i_1[sub]][j_1[sub]]==' '){
            if(MD==CORR)
                oceano[i_1[sub]][j_1[sub]]='S';    
            sub++;
        }
    }

    while (dest<d){//Determina a posicao dos destruidores
        i_2[dest]=rand()%o;
        j_2[dest]=rand()%o;
        dir_dest=rand()%2;
        if(dir_dest==0){    //O destruidor tem 2 casas verticais 
            if(oceano[i_2[dest]][j_2[dest]]==' '&&oceano[i_2[dest]+1][j_2[dest]]==' '){
            if(MD==CORR){
                oceano[i_2[dest]][j_2[dest]]='D';
                oceano[i_2[dest]+1][j_2[dest]]='D';
            }
            dest++;
            }
        }
        else{               //O destruidor tem 2 casas horizontais
            if(oceano[i_2[dest]][j_2[dest]]==' '&&oceano[i_2[dest]][j_2[dest]+1]==' '){
            if(MD==CORR){
            oceano[i_2[dest]][j_2[dest]]='D';
            oceano[i_2[dest]][j_2[dest]+1]='D';
            }
            dest++;
            }
        }
    }

    if (MD==CORR){  //Impressao do oceano com os submarinos na tela
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
        linha='A';
        printf("Submarinos:   %d\nDestruidores: %d\nTorpedos:     %d\n\n",qtd_sub,qtd_dest,qtd_tor);
    }
    do{  //O usuario atira e o programa retorna o oceano atualizado 
        printf("Insira a coluna que deseja atacar: ");
        scanf("%d",&coluna_ataque);
        coluna_ataque--;

        if(coluna_ataque<0||coluna_ataque>o-1){ //Verifica se digitou uma coluna valida
            printf("Voce digitou uma coluna inexistente.\n");
            return 1;
        }
        
        printf("Insira a linha que deseja atacar: ");
        scanf(" %c",&linha_ataque);
        linha_ataque=toupper(linha_ataque);

        if(linha_ataque<65||linha_ataque>o+64){//Verifica se digitou uma linha valida
            printf("Voce digitou uma linha inexistente.\n");
            return 1;
        }
        
        else{  //Transforma o caractere em um numero inteiro
            linha='@';
            for(i=0;i<o;i++){
                linha++;
                if(linha_ataque==linha){
                    linha_ataque_1=i;
                    i=o-1;
                    linha='A';
                }
            }
        }
        //Verifica se o tiro ja foi dado nesta casa
        if((oceano[linha_ataque_1][coluna_ataque]=='W')||(oceano[linha_ataque_1][coluna_ataque]=='*'))
            printf("\nVoce ja atacou esta casa do oceano. Tente novamente.\n\n");
        
        else{
            sub=0;//Condicao iniciao para o proximo while
            qtd_tor--;
            while(sub<s){   //Verifica se acertou um submarino
                if((i_1[sub]==linha_ataque_1)&&(j_1[sub]==coluna_ataque)){
                    printf("\n\n\n\nVoce afundou uma nave!\n");
                    oceano[linha_ataque_1][coluna_ataque]='*';
                    acerto++;
                    qtd_sub--;
                }
                sub++;
            }
            if(acerto==0){
                oceano[linha_ataque_1][coluna_ataque]='W';
                printf("\n\n\n\nSeu torpedo se perdeu na agua!\n");
            }
            acerto=0;

            for(i=0;i<=o;i++){//Imprime o oceano na tela com as informaçoes dos tiros dados      
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
                }
                printf("\n");
            }
            printf("Destruidores: %d\nSubmarinos:   %d\nTorpedos:     %d\n\n",qtd_sub,qtd_dest,qtd_tor);
            linha='A';
        }
    } while((qtd_tor!=0)&&((qtd_dest!=0)||(qtd_sub!=0))); //Estabelece as condicoes de fim de jogo
    
    if(qtd_tor==0){//Verifica qual foi a condicao para o jogo ter acabado
        if((qtd_sub==0)&&(qtd_dest==0)){
            printf("\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");
            return 1;   //Fim de jogo por finalizacao dos navios
        }
        else {
            printf("Voce perdeu o jogo :(\nAcabaram todos os seus torpedos.\n");
            return 2;   //Fim de jogo por falta de torpedos
        }
    }
    else if((qtd_sub==0)&&(qtd_dest==0)){
        printf("\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");
        return 1;   //Fim de jogo por finalizacao dos navios
    }

    return 0;  //Encerra o programa e retorna o valor 0
}