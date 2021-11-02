#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include "Bat.h"
#include "Bat.c"

int main(int argc, char *argv[])
{
    if(argsOk(argc,argv)!=0){
        errorMSG(argsOk(argc,argv));
        return argsOk(argc,argv);
    }
    char rep[o][o];
    char oceano[o][o];
    int q_d=d;
    int q_s=s; 
    int q_t=argT(argv);
    int coluna_ataque=0;
    char linha_ataque=' '; 
    int linha_ataque_1=0;

    initOcean(oceano);
    submarinesIntoOcean(rep);
    showSubmarines(rep,oceano,argv);
    showOcean(oceano);
    showInventory(q_d,q_s,q_t);

    do{
        shootTorp(&linha_ataque,&coluna_ataque,&linha_ataque_1);
        if(errShoot(coluna_ataque,linha_ataque_1)!=0){ 
            printf("Voce digitou um setor do oceano inexistente.\n");
            return 1;
        }
        didHit(hitShoot(coluna_ataque,linha_ataque_1,rep,oceano),&q_t,&q_s);
        showOcean(oceano);
        showInventory(q_d,q_s,q_t);
    } while((q_t>0)&&((q_d>0)||(q_s>0)));
    
    endGame(q_d,q_s,q_t);
    
    return 0;
}