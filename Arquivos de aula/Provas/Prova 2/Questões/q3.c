/*
    O programa apresenta a area do circulo com um raio de valor inserido
    pelo usuario a tempo de lancamento do programa.

    O usuario pode ser mal comportado.

    Por Gabriel Couto de Freitas em 2021- https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

//Cabecalho das funcoes
int isArgsOk(int argc, char *argv[]);
void errorMsg(int x);
int isFloatNum(char s[]);
float calcArea(float raio);
float myAtoF (char s[]);

int main(int argc, char *argv[])
{
    int erro=isArgsOk(argc,argv);   //Declaracao da variavel erro que recebe o valor da funcao isArgsOK

    if (erro!=0){       //Se o valor nao for 0, tem algum erro na declaracao de argumentos
        errorMsg(erro); //A funcao escreve na tela qual erro foi encontrado
        return erro;    //O programa encerra
    }
    float r=0.0;    //Variavel que armazena o raio, inserido em tempo de lancamento
    
    r=myAtoF(argv[1]);  //Armazena o raio em r

    printf("\nArea do circulo de raio %f eh igual a %f .\n\n",r,calcArea(r));   //Apresenta o raio e a area na tela
    
    return 0;  //Encerra o programa e retorna o valor 0
}
/*
isArgsOk
----------------------------------------------
A funcao checa o argumento inserido e retorna
um valor diferente de 0 se tiver algum erro.
*/
int isArgsOk(int argc, char *argv[])
{
    float f=0.0;

    if(argc<2)
        return 3;
    else if(isFloatNum(argv[1])==0)
        return 5;
    f=atof(argv[1]);
    if(f<=0)
        return 7;
    else 
        return 0;
}
/*
isFloatNum
-------------------------------------------
A funcao checa se o argumento inserido eh 
um numero real. Retorna 0 se nao for, 
retorna 1 se for real.
*/
int isFloatNum(char s[])
{
    int i;
    int virgula=0;
    int err=1;
    int tam=0;

    tam=strlen(s);

    if((s[0]=='-')||(s[0]=='+'))
        i=1;
    else 
        i=0;
    for ( ; ((i<tam)&&(s[i]!='\0')) ; i++ ){ 
        if (s[i]==','||s[i]=='.'){
            if (virgula==0){
                s[i]='.'; 
                virgula=1;
            }
            else 
                err=0;
        }
        else if (isdigit (s[i])==0){
            err=0;
        }
    }

    return err;
}
/*
errorMsg
--------------------------------------------------
A funcao escreve no arquivo stderr qual foi o erro 
apresentado pelo programa.
*/
void errorMsg(int x)
{
    switch(x){
        case 3:
            fprintf(stderr,"\nVoce nao inseriu o argumento do raio.\n\n");
            fprintf(stderr,"Insira da forma ./a.out x  onde x eh um numero real maior que 0.\n\n");
            break;
        case 5:
            fprintf(stderr,"\nO argumento do raio inserido nao eh um numero real.\n\n");
            fprintf(stderr,"Insira da forma ./a.out x  onde x eh um numero real maior que 0.\n\n");
            break;
        case 7:
            fprintf(stderr,"\nVoce inseriu um raio menor ou igual a 0.\n\n");
            fprintf(stderr,"Insira da forma ./a.out x  onde x eh um numero real maior que 0.\n\n");
            break;
    }
}
/*
myAtoF
--------------------------------------------------------------------------
A funcao pega a string inserida e transforma ela em numero real (float)
e retorna este valor.
*/
float myAtoF (char s[])
{
    float n=0.0;    //numero relacionado a str
    int sinal=1;    //Sinal do numero
    int d=0;        //Quantidade de casas decimais
    int dp=0;       //Indica se tem casas decimais
    int i=0;
    int tam=0;  //tamanho da string 
    int result=1;   //resultado

    tam=strlen(s);
    if(s[0]=='-'){
        sinal=-1;
        i=1;
    }
    else if (s[0]=='+')
        i=1;

    for(;(i<tam)&&(s[i]!='\0');i++){
        if(s[i]=='.')
            dp=1;
        else {
            n=n*10+(s[i]-'0');
            if(dp==1)
                d++;
        }
    }
    for(i=0;i<d;i++)
        result*=10;
    
    return (n/(result)*sinal);
}
/*
calcArea
-----------------------------------------
A funcao calcula a area do circulo
com o raio inserido e retorna esse valor.
*/
float calcArea(float raio)
{
    return (3.141592653589*(raio*raio));
}