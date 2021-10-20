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
Gabriel Couto de Freitas https://github.com/gabrielcouto1
*/

#include <stdio.h> //Inclusao de biblioteca de funcoes basicas em C
#include <stdlib.h> //Inclusao de biblioteca de funcoes basicas em C
#include <ctype.h> //Inclusao de biblioteca para utilizacao de toupper, afim de reduzir erros do usuario   
#include <string.h>//Inclusao de biblioteca de strings em C
#include "Bat.h"

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
#include "Bat.c"