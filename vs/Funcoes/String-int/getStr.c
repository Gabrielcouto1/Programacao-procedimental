/*
getStr
----------------------------------------------------------------
A funcao getStr captura um numero que sera inserido pelo usuario
e em seguida verifica se o usuario digitou mais algarismos que 
o MAX preestabelecido. Se o maximo for excedido, retorna o valor 0.
Se o maximo nao for excedido, retorna o valor 1.
*/
int getStr(char s[MAX])
{
    int i;  //Variavel utilizada no for para captura dos elementos da string

    for(i=0;i<MAX;i++){
        scanf("%c",&s[i]);
        if(s[i]=='\n')  //No momento que o usuario digita enter, a captura cessa
            break;
    }
    
    if(i==MAX)  //Se o contador tem o mesmo valor de MAX, indica que o usuario digitou mais algarismos que o permitido
        return 0;   //O programa encerra

    s[i]='\0';   
    return 1;  //Senao, o programa continua normalmente
}