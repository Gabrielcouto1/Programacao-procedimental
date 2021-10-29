/*
    O programa gera numeros pseudo-aleatorios de 0 ate 23.
    Quando ele gera o primeiro numero 23, o programa se encerra.
    Ele mostra quantos numeros foram gerados e dispoe todos os numeros
    contendo 5 numeros por linha.
    
    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main()
{
    int N=0;    //Variavel que armazena o numero aleatorio gerado
    int qtd_linha=0;    //Variavel que auxilia a contar quantos numeros estao dispostos por linha
    int qtd_num=0;  //Variavel que armazena a quantidade de numeros gerados ate gerar o numero 23

    srand(time(NULL));

    do{
        if(qtd_linha%5==0)  //Se tiver 5 numeros na linha, ele salta de linha
            printf("\n");       
        qtd_linha++;

        N=rand() % 24;  //Gera um numero aleatorio de 0 ate 23
        
        printf("%d ",N);    //Imprime na tela   
        qtd_num++;  //Aumenta um numero na quantidade de numeros gerados
    }while (N!=23); //Se o numero gerado for 23, ele encerra o programa

    printf("\nQuantidade de numeros = %d\n\n",qtd_num); //Imprime na tela a quantidade de numeros gerados

    return 0;  //Encerra o programa e retorna o valor 0
}