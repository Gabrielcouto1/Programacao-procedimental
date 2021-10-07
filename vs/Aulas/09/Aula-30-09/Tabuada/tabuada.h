const int MAX=20;   //Quantidade de algarismos suportados

/*
getStr
----------------------------------------------------------------
A funcao getStr captura um numero que sera inserido pelo usuario
e em seguida verifica se o usuario digitou mais algarismos que 
o MAX preestabelecido. Se o maximo for excedido, retorna o valor 0.
Se o maximo nao for excedido, retorna o valor 1.
*/
int getStr(char s[MAX]);

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
int isIntnum(char s[MAX]);

/*
times Table 
-------------------------------
Apresenta a tabuada de n indo de 1 ate q, 
com k multiplicacoes por linha.
*/
void timesTable (int n, int q, int k);
