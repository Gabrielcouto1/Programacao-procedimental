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