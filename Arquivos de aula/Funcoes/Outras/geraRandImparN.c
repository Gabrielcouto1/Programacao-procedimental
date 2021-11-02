/*
geraRandImparN
-------------------------------------------------------
A funcao retorna um numero inteiro aleatorio impar menor 
que o numero int N inserido na funcao.
*/
int geraRandImparN(int n)
{
    int p=0;

    srand(time(NULL));

    for(; ;){
        p= rand()%n;
        if(p%2)
            break;
    }
    return p;
}