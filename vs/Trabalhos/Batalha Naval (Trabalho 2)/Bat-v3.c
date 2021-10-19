/*
    O programa opera um jogo simples de batalha naval com dois modos, PLAY e CORR. Quando no modo CORR,
todas as naves serao mostradas na tela. O oceano inicial aparece na tela, o usuario deve digitar qual
setor do oceano ele deseja atirar (ex:A1). Se ele digitar algum caractere invalido, isso eh escrito na
tela e o programa encerra. Se ele atirar em algum setor ja atirado ele deve atirar novamente sem perder
torpedo algum. Se ele acertar um submarino, a mensagem de acerto eh escrita na tela e o oceano aparece
novamente com um '*' no lugar que ele acertou. Em seguida mostra o que resta no seu inventario. Caso ele
erre o tiro, aparece uma mensagem que ele afundou o torpedo no mar e um 'W' eh escrito nesse setor do oceano.
O programa encerra se: o usuario acabar com todos destruidores e submarinos (escreve na tela que ele ganhou 
o jogo) ou se o usuario nao tiver mais torpedos e ainda existir naves no oceano(escreve na tela que ele perdeu
o jogo).
    Se antes de iniciar o jogo, o usuario inserir uma quantidade de submarinos, torpedos e destruidores que
impossibilitam o jogo de ser jogado, o programa se encerra e escreve a mensagem de erro na tela.

Codigo escrito em 2021 por:
Gabriel Couto de Freitas - 12021BCC040
Ana Barbara Campos - 12021BCC017 
Fabricio Ishizuka - 12021BCC033

*/
#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca para utilizacao de toupper, afim de reduzir erros do usuario   
#include <string.h>
#include "Bat.h"

//FAZER A SUBMARINESINTOOCEAN, MEXER NAS LINHAS 43-56(FAZER UMA FUNC PRA ISSO)
//CRIAR FUNCAO PARA VERIFICAR SE O ATAQUE DIGITADO EH VALIDO
//CRIAR FUNCAO PARA VERIFICAR ATAQUES, CRIAR FUNCAO PARA VERIFICAR CONDICAO DE FIM DE JOGO

int main(int argc, char *argv[])
{
    int t=0;
    int MD=0;
    int err=0;
    err=argsOk(argc,argv);

    if(err!=0){
        errorMSG(err);
        return 0;
    }

    if(strcmp(argv[1],"-t")==0){
        t=atoi(argv[2]);
        if(strcmp(argv[4],"PLAY")==0)
            MD=PLAY;
        else 
            MD=CORR;
    }
    else if(strcmp(argv[3],"-t")==0){
        t=atoi(argv[4]);
        if(strcmp(argv[2],"PLAY")==0)
            MD=PLAY;
        else 
            MD=CORR;
    }
       
    char rep[o][o];
    char oceano[o][o];  //Matriz oceano de ordem "o" preestabelecida
    int i;    //Contadores usados para imprimir a matriz na tela
    char linha= 'A'; //Variavel usada para imprimir a letra das linhas na tela
    int sub=0;  //Contador usado para determinar a posicao dos submarinos
    int i_1[s],j_1[s];                //Armazenam a posicao dos submarinos
    int q_d=d; //Qtd de destruidores restantes
    int q_s=s;  //Qtd de submarinos restantes
    int q_t=t;  //Qtd de torpedos restantes
    int coluna_ataque=0;    //Coluna que o usuario deseja atacar  
    char linha_ataque=' ';  //Linha que o usuario deseja atacar
    int linha_ataque_1=0;   //Linha que o usuario deseja atacar 
    int acerto=0;   //Determina se o usuario acertou o disparo

    initOcean(oceano);
    initOcean(rep);
    while(sub<s){ //Determina a posicao dos submarinos pseudo-aleatoriamente
        i_1[sub]=rand()%o;
        j_1[sub]=rand()%o;
        if((rep[i_1[sub]][j_1[sub]]==' ')){//Verifica se a casa sorteada eh apta a receber um submarino
            if(MD==CORR)//Escreve na tela a posicao do submarino se o modo de correcao eh ativado
                oceano[i_1[sub]][j_1[sub]]='S';

            //Estabelece que as casas adjacentes com a sorteada nao podem ser ocupadas por outro submarino
            rep[i_1[sub]][j_1[sub]]=1;
            rep[i_1[sub]-1][j_1[sub]-1]=1;
            rep[i_1[sub]-1][j_1[sub]]=1;
            rep[i_1[sub]-1][j_1[sub]+1]=1;
            rep[i_1[sub]][j_1[sub]-1]=1;
            rep[i_1[sub]][j_1[sub]+1]=1;
            rep[i_1[sub]+1][j_1[sub]-1]=1;
            rep[i_1[sub]+1][j_1[sub]]=1;
            rep[i_1[sub]+1][j_1[sub]+1]=1;
            sub++;
        }    
    }
    showOcean(oceano);
    showInventory(q_d,q_s,q_t);

    do{  //O usuario atira e o programa retorna o oceano atualizado
        printf("Insira o setor que deseja atacar(ex: A1): ");
        scanf(" %c",&linha_ataque);
        linha_ataque=toupper(linha_ataque);

        if(linha_ataque<65||linha_ataque>o+64){//Verifica se digitou uma linha valida
            printf("Voce digitou uma linha inexistente.\n");
            return 1;
        }
        
        else{  //Transforma o caractere digitado em um numero inteiro
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
        scanf("%d",&coluna_ataque);
        coluna_ataque--;

        if(coluna_ataque<0||coluna_ataque>o-1){ //Verifica se digitou uma coluna valida
            printf("Voce digitou uma coluna inexistente.\n");
            return 1;
        }
        
        //Verifica se o tiro ja foi dado nesta casa
        if((oceano[linha_ataque_1][coluna_ataque]=='W')||(oceano[linha_ataque_1][coluna_ataque]=='*'))
            printf("\nVoce ja atacou esta casa do oceano. Tente novamente.\n\n");
        
        
        else{   //Verifica se acertou uma nave
            sub=0; //Condicao iniciao para o proximo while
            q_t--;
            while(sub<s){   //Verifica se acertou um submarino
                if((i_1[sub]==linha_ataque_1)&&(j_1[sub]==coluna_ataque)){
                    oceano[linha_ataque_1][coluna_ataque]='*';
                    acerto++;//Caso tenha acertado um submarino
                }
                sub++;
            }
            
            switch(acerto){//Verifica se acertou um destruidor ou um submarino ou se errou
                case 0:
                    printf("---------------------------------------------------------------\n\n");
                    printf("\n\n\n\nSeu torpedo se perdeu na agua!\n\n");
                    oceano[linha_ataque_1][coluna_ataque]='W';
                    acerto=0;
                    break;
                case 1://Caso tenha acertado um submarino
                    printf("---------------------------------------------------------------\n\n");
                    printf("\n\n\n\nVoce afundou uma nave!\n\n");
                    q_s--;
                    acerto=0;
                    break;
            }
        }
        showOcean(oceano);
        showInventory(q_d,q_s,q_t);
    } while((q_t>0)&&((q_d>0)||(q_s>0))); //Estabelece as condicoes de fim de jogo
    
    if(q_t==0){//Verifica qual foi a condicao para o jogo ter acabado
        if((q_s==0)&&(q_d==0))
            printf("\n\nVoce ganhou o jogo :)!!!!\n\nAcabaram todos os navios no oceano.\n");
        else 
            printf("\n\nVoce perdeu o jogo :(\n\nAcabaram todos os seus torpedos.\n");
    }
    
    else if((q_s==0)&&(q_d==0))//Verifica qual foi a condicao para o jogo ter acabado
        printf("\n\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");

    return 0;  //Encerra o programa e retorna o valor 0
}
int argsOk(int argc, char *argv[])
{
    char isint=' ';
    if(argc>5)
        return 3;
    else if(argc<5)
        return 5;
    else if((strcmp(argv[1],"-t")!=0)&&(strcmp(argv[1],"-m")!=0))
        return 7;
    else if((strcmp(argv[3],"-t")!=0)&&(strcmp(argv[3],"-m")!=0))
        return 7;
    else if((strcmp(argv[1],"-t")==0)&&(strcmp(argv[3],"-m")==0)){
        isint=*argv[2];
        if(isdigit(isint)==0)
            return 9;
        else if((strcmp(argv[4],"PLAY")!=0)&&(strcmp(argv[4],"CORR")!=0))
            return 11;   
    }
    else if((strcmp(argv[3],"-t")==0)&&(strcmp(argv[1],"-m")==0)){
        isint=*argv[4];
        if(isdigit(isint)==0)
            return 9;
        else if((strcmp(argv[2],"PLAY")!=0)&&(strcmp(argv[2],"CORR")!=0))
            return 11;
    }
    else 
        return 0;
}
void errorMSG(int x)
{
    switch (x){
        case 3:
            fprintf(stderr,"\nVoce digitou mais argumentos que 5.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6 \n");
            break;
        case 5:
            fprintf(stderr,"\nVoce digitou menos argumentos que 5.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6 \n");
            break;
        case 7:
            fprintf(stderr,"\nVoce nao digitou a identificacao dos argumentos (-t ou -m).\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6 \n");
            break;
        case 9:
            fprintf(stderr,"\nO argumento que indica a quantidade de torpedos nao foi um numero inteiro.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6 \n");
            break;
        case 11:
            fprintf(stderr,"\nO argumento que inserido que indica o modo de jogo nao foi PLAY ou CORR.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6 \n");
            break;
        case 0:
            break;
    }
       
}
void initOcean(char ocean[o][o])
{
    int i,j;
    for (i=0;i<=o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<=o;j++){
            ocean[i][j]=' ';
        }
    }
}
void showOcean(char ocean[o][o])
{
    int i,j,k,h;
    char linha='A';

    for(i=0;i<=o;i++){//Imprime o oceano final na tela, contendo as informacoes de tiros e navios afundados
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
                    printf("| %c ",ocean[i][j]);
                    if(j==o-1)
                        printf("|");
                }
            }
            printf("\n");
        }
}
void showInventory(int d, int s, int t)
{
    printf("Destruidores: %d\nSubmarinos:   %d\nTorpedos:     %d\n\n",d,s,t);
}
void submarinesSpacing(int rep[o][o], int i_1[s], int j_1[s], int sub)
{
    int s=sub;
    int i=i_1;
    int j=j_1;
    
    rep[i[s]][j[s]]=1;
    rep[i[s]-1][j[s]-1]=1;
    rep[i[s]-1][j[s]]=1;
    rep[i[s]-1][j[s]+1]=1;
    rep[i[s]][j[s]-1]=1;
    rep[i[s]][j[s]+1]=1;
    rep[i[s]+1][j[s]-1]=1;
    rep[i[s]+1][j[s]]=1;
    rep[i[s]+1][j[s]+1]=1;
}
void submarinesIntoOcean (char ocean[o][o])
{
    int i,j,i_1,j_1;
    int sub=0;
    int rep[o][o];

    for(i=0;i<o;i++)
        for(j=0;j<o;j++)
            rep[i][j]=0;
    
    if((rep[i_1[sub]][j_1[sub]]==0)){
        if(MD==CORR)
            ocean[i_1[sub]][j_1[sub]]='S';

        submarinesSpacing(rep,i_1,j_1,sub);
        sub++;
    }

}