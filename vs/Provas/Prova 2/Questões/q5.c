/*
    O programa le um arquivo de nome inserido pelo usuario e imprime na tela 
    a linha que o usuario digitar.
    Ambos o nome do arquivo e a linha a ser impressa serao inseridos a 
    tempo de lancamento do programa.
    
    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;     //Variavel que armazena os caracteres do arquivo
    int L;  //Linha que o usuario ira digitar
    int linha_atual=1;  //Variavel que armazena a linha que o programa esta lendo
    int limite=0;   //Variavel que dira se o usuario digitou um numero invalido para L
    FILE *F=NULL;

    F=fopen(argv[1],"r");

    if(argc<3){//Se faltar argumenos ele encerra o programa
        fprintf(stderr,"\nArgumentos insuficientes.\n\n");
        return 3;
    }

    if(F==NULL){//Se o nome do arquivo nao existir encerra o programa
        fprintf(stderr,"\nNao foi possivel abrir o arquivo inserido.\n\n");
        return 5;
    }

    L=atoi(argv[2]);

    if(L<=0){   
        fprintf(stderr,"\nVoce digitou um valor <=0 para L. Digite um numero maior que 0.\n\n");
        return 7;
    }

    for( ; ; ){     //Loop infinito para ler o arquivo
    
        fscanf(F,"%c",&c);  //Le caractere por caractere do programa

        if (feof(F))    //Quando o arquivo acabar ele sai do loop
            break;

        if(linha_atual==L){ //Quando chegar na linha que o usuario digitou, escreve ela na tela
            printf("%c",c);
            limite=1;
        }
            
        if (c=='\n')    //Quando pula de linha, contabiliza isso
            linha_atual++;
    }
    
    printf("\n");

    if(limite==0)   //Se ele inserir um valor de linhas invalido
        fprintf(stderr,"\nVoce inseriu uma linha maior que a quantidade de linhas do arquivo.\n\n");

    fclose(F);
    return 0;  //Encerra o programa e retorna o valor 0
}