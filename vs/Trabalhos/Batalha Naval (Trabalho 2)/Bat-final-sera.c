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
    A quantidade de torpedos e o modo de jogo sao inseridos em tempo do lancamento do programa, ou seja
o usuario deve inicial do jeito: ./a.out -t n -m MD   ou ./a.out -m MD -t n  onde n eh um numero inteiro
e MD eh PLAY ou CORR.

Codigo escrito em 2021 por:
Gabriel Couto de Freitas - 12021BCC040 - https://github.com/gabrielcouto1
Ana Barbara Campos - 12021BCC017 
Fabricio Ishizuka - 12021BCC033

*/
#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca para utilizacao de toupper, afim de reduzir erros do usuario   
#include <string.h>//Inclusao de biblioteca de strings em C

const int o = 5;    //Tamanho da matriz oceano
const int s = 3;    //Quantidade de submarinos
const int d = 0;    //Quantidade de destruidores

#define PLAY 0  //Definicao de "PLAY" para alterar facilmente o modo de execucao do codigo
#define CORR 1  //Definicao de "CORR" para alterar facilmente o modo de execucao do codigo

//Declaracao das funcoes
int argsOk(int argc, char *argv[]);
void errorMSG(int x);
void initOcean(char ocean[o][o]);
void showInventory(int d, int s, int t);
void showOcean(const char ocean[o][o]);
void submarinesIntoOcean (char ocean[o][o]);
void showSubmarines(char rep[o][o], char ocean[o][o]);
int argMD(char *argv[]);
int argT(char *argv[]);
void shootTorp(char *linha, int *coluna,int *linha_1);
int errShoot(int coluna, int linha);
int hitShoot(int coluna, int linha, char rep[o][o], char ocean[o][o]);
void didHit(int tiro, int *q_t, int *q_s);
void endGame(int q_d, int q_s, int q_t);

int main(int argc, char *argv[])
{
    int err=argsOk(argc,argv);  //Verifica se tem algum erro nos argumentos 
    int t=argT(argv);   //Armazena a quantidade de torpedos inserida no argumento
    int MD=argMD(argv); //Armazena o modo de jogo inserido no argumento
    char rep[o][o]; //Matriz do oceano que auxilia no posicionamento de naves e modo de correcao
    char oceano[o][o];  //Matriz oceano de ordem "o" preestabelecida
    int q_d=d; //Qtd de destruidores restantes
    int q_s=s;  //Qtd de submarinos restantes
    int q_t=t;  //Qtd de torpedos restantes
    int coluna_ataque=0;    //Coluna que o usuario deseja atacar  
    char linha_ataque=' ';  //Linha que o usuario deseja atacar
    int linha_ataque_1=0;   //Linha que o usuario deseja atacar 
    int tiro=0; //Variavel que diz se o tiro acertou ou nao

    if(err!=0){ //Se tiver algum erro na inicializacao do programa
        errorMSG(err);//Escreve na tela qual erro foi obtido
        return err;//Encerra o programa
    }
    initOcean(oceano);  //Inicializa o oceano com ' ' 
    submarinesIntoOcean(rep);   //Determina a posicao dos submarinos no oceano
    if(MD==CORR)    //Escreve na tela a posicao dos submarinos se o modo for CORR
        showSubmarines(rep,oceano); 
    showOcean(oceano);  //Escreve o oceano na tela
    showInventory(q_d,q_s,q_t);//Escreve o inventario na tela

    do{  //O usuario atira e o programa retorna o oceano atualizado
        shootTorp(&linha_ataque,&coluna_ataque,&linha_ataque_1);//Recebe o setor que o usuario atirou
        if(errShoot(coluna_ataque,linha_ataque_1)!=0){  //Se o usuario digitou algum setor invalido
            printf("Voce digitou um setor do oceano inexistente.\n");
            return 1;//Encerra o programa
        }
        tiro=hitShoot(coluna_ataque,linha_ataque_1,rep,oceano);//Estabelece condicao de tiro, se acertou ou errou
        didHit(tiro,&q_t,&q_s);//Verifica se acertou, errou ou se ja tinha atirado nesta casa
        showOcean(oceano);//Mostra o oceano atualizado na tela
        showInventory(q_d,q_s,q_t);//Mostra o inventario atualizado na tela
    } while((q_t>0)&&((q_d>0)||(q_s>0))); //Estabelece as condicoes de fim de jogo
    
    endGame(q_d,q_s,q_t);//Escreve na tela a condicao de fim de jogo
    
    return 0;  //Encerra o programa e retorna o valor 0
}
/*
argsOk
-------------------------------------------------------------------------------------------
A funcao checa se os argumentos inseridos sao validos e retorna um valor.*/
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
/*
errorMSG
-------------------------------------------------------------------------------------------
A funcao checa o valor retornado na funcao argsOk e se tiver algum erro
ela mostra na tela e encerra o programa.
*/
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
/*
initOcean
-------------------------------------------------------------------------------------------
A funcao inicia a matriz oceano com espacos em branco ' '.*/
void initOcean(char ocean[o][o])
{
    int i,j;
    for (i=0;i<=o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<=o;j++){
            ocean[i][j]=' ';
        }
    }
}
/*
showInventory
-------------------------------------------------------------------------------------------
A funcao mostra a quantidade de torpedos no inventario e quantas naves ainda restam.*/
void showInventory(int d, int s, int t)
{
    printf("Destruidores: %d\nSubmarinos:   %d\nTorpedos:     %d\n\n",d,s,t);
}
/*
showOcean
-------------------------------------------------------------------------------------------
A funcao mostra o oceano atual na tela do usuario.*/
void showOcean(const char ocean[o][o])
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
/*
submarinesIntoOcean
-------------------------------------------------------------------------------------------
A funcao gera pesudo-aleatoriamente os submarinos no oceano.
*/
void submarinesIntoOcean (char ocean[o][o])
{
    int i,j;
    int sub=0;
    
    for (i=0;i<o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<o;j++){
            ocean[i][j]=' ';
        }
    }

    while (sub<s){
        i=rand()%o;
        j=rand()%o;

        if((ocean[i][j]==' ')){
            ocean[i][j]='2';
            ocean[i-1][j-1]='1';
            ocean[i-1][j]='1';
            ocean[i-1][j+1]='1';
            ocean[i][j-1]='1';
            ocean[i][j+1]='1';
            ocean[i+1][j-1]='1';
            ocean[i+1][j]='1';
            ocean[i+1][j+1]='1';
            sub++;
        }
    }
}
/*
showSubmarines
-------------------------------------------------------------------------------------------
Se o modo for CORR, a funcao mostra no oceano onde estao todas as naves.
*/
void showSubmarines(char rep[o][o], char ocean[o][o])
{
    int i,j;
    for (i=0;i<o;i++)
        for(j=0;j<o;j++)
            if(rep[i][j]=='2')
                ocean[i][j]='S';
}
/*
argMD
-------------------------------------------------------------------------------------------
A funcao armazena o argumento de modo de jogo inserido.
*/
int argMD(char *argv[])
{
    int MD=0;
    if(strcmp(argv[1],"-t")==0){
        if(strcmp(argv[4],"PLAY")==0)
            MD=PLAY;
        else 
            MD=CORR;
    }
    else if(strcmp(argv[3],"-t")==0){
        if(strcmp(argv[2],"PLAY")==0)
            MD=PLAY;
        else 
            MD=CORR;
    }
    return MD;
}
/*
argT
-------------------------------------------------------------------------------------------
A funcao armazena o argumento de quantidade de torpedos inseridos.
*/
int argT(char *argv[])
{
    int t=0;
    if(strcmp(argv[1],"-t")==0)
        t=atoi(argv[2]);

    else if(strcmp(argv[3],"-t")==0)
        t=atoi(argv[4]);

    return t;
}
/*
shootTorp
-------------------------------------------------------------------------------------------
A funcao armazena em qual setor do oceano o usuario deseja atacar.
*/
void shootTorp(char *linha, int *coluna,int *linha_1)
{
    int i;
    char lin='@';
    printf("Insira o setor que deseja atacar(ex: A1): ");
    scanf(" %c",&*linha);
    *linha=toupper(*linha);
    scanf("%d",&*coluna);
    *coluna=*coluna-1;

    for(i=0;i<o;i++){
        lin++;
        if(*linha==lin){
            *linha_1=i;
            i=o-1;
            lin='A';
        }
    }
    if(*linha=='A')
        return;
    if(*linha<65||*linha>o+64)
        *linha_1=99;
}
/*
errShoot
-------------------------------------------------------------------------------------------
A funcao verifica se existe algum erro com o setor que o usuario atacou.
Ela retorna um valor.
*/
int errShoot(int coluna, int linha)
{
    if(linha==99)
        return 3;
    if(coluna<0||coluna>o-1){
        return 3;
    }
    else if(linha<0||linha>o-1){
        return 3;
    }
    else
        return 0;
}
/*hitShoot
-------------------------------------------------------------------------------------------
A funcao verifica se o setor que o usuario atacou tem uma nave ou se ele ja 
atirou neste setor. Retorna um valor.
*/
int hitShoot(int coluna, int linha, char rep[o][o], char ocean[o][o])
{
    int i,j;
    if(rep[linha][coluna]=='2'){
        if(ocean[linha][coluna]=='*'||ocean[linha][coluna]=='W')
            return 3;//ja atirou ai

        ocean[linha][coluna]='*';
        return 1;//acertou
    }
    else if (rep[linha][coluna]!='2'){
        if(ocean[linha][coluna]=='W')
            return 3;//ja atirou ai
        ocean[linha][coluna]='W';
        return 2;//errou
    }
}
/*
didHit
-------------------------------------------------------------------------------------------
A funcao verifica e escreve na tela se o usuario ja atirou nesta casa
ou se eh uma casa invalida.
*/
void didHit(int tiro, int *q_t, int *q_s)
{
    switch(tiro){
        case 1:
            printf("\n\n\n\nVoce afundou um submarino!!\n");
            *q_t=*q_t-1;
            *q_s=*q_s-1;
            break;
        case 2:
            printf("\n\n\n\nSeu tiro se perdeu no mar!!\n");
            *q_t=*q_t-1;
            break;
        case 3:
            printf("\n\n\n\nVoce ja atacou esse setor do oceano. Tente novamente.\n");
            break;
    }
}
/*
endGame
-------------------------------------------------------------------------------------------
A funcao verifica qual a condicao de fim de jogo e se o usuario ganhou 
ou perdeu o jogo.
*/
void endGame(int q_d, int q_s, int q_t)
{   
    if(q_t==0){//Verifica qual foi a condicao para o jogo ter acabado
        if((q_s==0)&&(q_d==0))
            printf("\n\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");
        else 
            printf("\n\nVoce perdeu o jogo :(\nAcabaram todos os seus torpedos.\n");
    }
    
    else if((q_s==0)&&(q_d==0))//Verifica qual foi a condicao para o jogo ter acabado
        printf("\n\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");
}