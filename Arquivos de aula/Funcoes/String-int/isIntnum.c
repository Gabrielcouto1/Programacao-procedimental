/*
isIntnum
-----------------------------------------------------------
A funcao isIntnum serve para testar se o usuario digitou 
um numero inteiro. Ela verifica se ele digitou um sinal
(- ou +), e em seguida testa todas as posicoes do array.
Se algum caractere nao for um numero inteiro, a funcao 
retorna o valor 0. Se todos forem numeros inteiros, retorna 
o valor 1 e a funcao main continua.
*/
int isIntnum (char s[MAX])
{
    int i=((s[0=='-'])||(s[0]=='+'))? 1:0;  //Se comecar com um sinal, o for comeca na segunda posicao da string

    for(;s[i]!='\0';i++){
        if(isdigit(s[i)==0) //Realiza o teste para ver se a posicao atual eh numero
            return 0;
    }

    return 1;
}