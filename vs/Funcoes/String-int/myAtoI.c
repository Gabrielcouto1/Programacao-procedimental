/*
myAtoI
--------------------------------
A funcao pega o o valor atribuido a string e transforma em numero inteiro.
O usuario eh bem comportado e nao ira digitar nada alem de numeros fora
a primeira casa, se o numero for negativo.
*/
int myAtoI (char s[MAX])
{
    int i=0;    //Contador utilizado no for
    int n=0;    //Variavel que armazena o numero inteiro
    int sinal=1;    //Variavel que indica o sinal do numero, se eh negativo (-1) ou positivo(1)

    if(s[0]=='-'){  //Verifica se o primeiro digito inserido foi o sinal de negativo
        sinal=-1;   //Se for, a variavel sinal sera -1
        i=1;    //O contador do for começa em 1 se o sinal for negativo
    }
    else if(s[0]=='+')
        i=1;
    
    for(;(i<MAX)&&(s[i]!='\0');i++)
        n=n*10+(s[i]-'0');    //Manipulacao de valores decimais da tabela ascii para transformar em numero inteiro

    return (sinal*n);   //Retorna o valor do sinal vezes o numero inteiro
}