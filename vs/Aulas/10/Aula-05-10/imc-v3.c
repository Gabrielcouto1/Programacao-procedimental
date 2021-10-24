/*
    O algoritmo apresenta o peso, a altura, o IMC e a interpretacao do IMC.
    O usuario ira inserir o peso e a altura no lancamento do programa.
    Por Gabriel Couto de Freitas em 2021
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

void calc_imc(float peso, float altura);
int main(int argc,char *argv[])
{
    
    if (argc>1){
        if(argc<3){
            fprintf(stderr,"\nFaltam argumentos.\nDigite o peso e a altura.\n");
            return 3;
        }
        float p=0;
        float a=0;
        if (strcmp(argv[1],"-p")==0){
            p=atof(argv[2]);
            a=atof(argv[4]);
        }
        else {
            p=atof(argv[4]);
            a=atof(argv[2]);
        }
        
        calc_imc(p,a);
    }
    else 
        fprintf(stderr,"\nNao ha argumentos.\n");

    return 0;  //Encerra o programa e retorna o valor 0
}
/*
myAtoF
--------------------------------------------------------------------------
A funcao pega a string inserida e transforma ela em numero real (float)
e retorna este valor.
*/
float myAtoF (char str[MAX])
{
    float n=0.0;    //numero relacionado a str
    int sinal=1;    //Sinal do numero
    int d=0;        //Quantidade de casas decimais
    int dp=0;       //Indica se tem casas decimais
    int i=0;

    if(str[0]=='-'){
        sinal=-1;
        i=1;
    }
    else if (str[0]=='+')
        i=1;

    for(;(i<MAX)&&(str[i]!='\0');i++){
        if(str[i]=='.')
            dp=1;
        else {
            n=n*10+(str[i]-'0');
            if(dp==1)
                d++;
        }
    }

    return (n/(pow(10,d))*sinal);
}
int argsOK(int argc, char *argv[])
{
    int err=0;

    if (argc<5)
        return 1;
    else if (argc>5)
        return 2;
    else if ((strcmp(argv[1],"-a")!=0)&&(strcmp(argv[3],"-p")!=0))
        return 3;
    else if ((strcmp(argv[1],"-p")!=0)&&(strcmp(argv[3],"-a")!=0))
        return 3;
    else if((strcmp(argv[1],"-a")==0)&&(strcmp(argv[3],"-p")==0)){

    }

}
/*
calc_imc
--------------------
A função calcula e interpreta o IMC com o peso e altura inseridos
e diz se o usuario e abaixo do peso, peso normal, acima do peso ou obeso.

*/
void calc_imc(float peso, float altura)
{
    float imc=0;
    imc=peso/(altura*altura);
    printf("\nIMC=%.2f\n",imc);
    if(imc<18.5)
        printf("\nAbaixo do peso.\n\n");
    else if(imc<25.0)
        printf("\nIMC normal.\n\n");
    else if(imc<30.0)
        printf("\nSobrepeso.\n\n");
    else   
        printf("\nObesidade.\n\n");
}