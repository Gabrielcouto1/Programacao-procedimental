int argsOk(int argc, char *argv[])
{
    char isint=' ';
    int t=0;

    if(argc>5)
        return 3;
    else if(argc<5)
        return 5;
    else if((strcmp(argv[1],"-t")!=0)&&(strcmp(argv[1],"-m")!=0))
        return 7;
    else if((strcmp(argv[3],"-t")!=0)&&(strcmp(argv[3],"-m")!=0))
        return 7;
    else if((strcmp(argv[1],"-t")==0)&&(strcmp(argv[3],"-m")==0)){
        isint=*argv[2];
        t=atoi(argv[2]);
        if(t<=0)
            return 13;
        else if (t<(s+d))
            return 15;
        if(isdigit(isint)==0)
            return 9;
        else if((strcmp(argv[4],"PLAY")!=0)&&(strcmp(argv[4],"CORR")!=0))
            return 11;   
    }
    else if((strcmp(argv[3],"-t")==0)&&(strcmp(argv[1],"-m")==0)){
        isint=*argv[4];
        t=atoi(argv[4]);
        if(t<=0)
            return 13;
        else if (t<(s+d))
            return 15;
        if(isdigit(isint)==0)
            return 9;
        else if((strcmp(argv[2],"PLAY")!=0)&&(strcmp(argv[2],"CORR")!=0))
            return 11;
    }
    else 
        return 0;
}
void errorMSG(int x)
{
    switch (x){
        case 3:
            fprintf(stderr,"\nVoce digitou mais argumentos que 5.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 5:
            fprintf(stderr,"\nVoce digitou menos argumentos que 5.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 7:
            fprintf(stderr,"\nVoce nao digitou a identificacao dos argumentos (-t ou -m).\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 9:
            fprintf(stderr,"\nO argumento que indica a quantidade de torpedos nao foi um numero inteiro.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 11:
            fprintf(stderr,"\nO argumento que inserido que indica o modo de jogo nao foi PLAY ou CORR.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 13:
            fprintf(stderr,"\nFoi inserido uma quantidade menor ou igual a 0 de torpedos.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 15:
            fprintf(stderr,"\nFoi inserido uma quantidade de torpedos menor que a quantidade de naves no oceano.\n");
            fprintf(stderr,"\nInsira da forma ./a.out -t 6 -m PLAY ou entao ./a.out -m PLAY -t 6.\n");
            break;
        case 0:
            break;
    }
}
void initOcean(char ocean[o][o])
{
    int i,j;
    for (i=0;i<=o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<=o;j++){
            ocean[i][j]=' ';
        }
    }
}
void showInventory(int d, int s, int t)
{
    printf("Destruidores: %d\nSubmarinos:   %d\nTorpedos:     %d\n\n",d,s,t);
}
void showOcean(const char ocean[o][o])
{
    int i,j,k,h;
    char linha='A';

    for(i=0;i<=o;i++){//Imprime o oceano final na tela, contendo as informacoes de tiros e navios afundados
            if(i==0){
                printf(" ");
                for(h=0;h<o;h++){
                    if(h==o-1)
                        printf("   %d\n",h+1);
                    else 
                        printf("   %d",h+1);
                }
            }
            printf("  ");
            for(k=0;k<o;k++){
                printf("+---");
                if(k==o-1){
                    printf("+");
                }
            }
            printf("\n");
            if(i!=o){
                printf("%c ",linha);
                linha++;
                for(j=0;j<o;j++){
                    printf("| %c ",ocean[i][j]);
                    if(j==o-1)
                        printf("|");
                }
            }
            printf("\n");
        }
}
void submarinesIntoOcean (char ocean[o][o])
{
    int i,j;
    int sub=0;
    
    for (i=0;i<o;i++){  //Define o estado inicial da matriz como um espaco vazio
        for(j=0;j<o;j++){
            ocean[i][j]=' ';
        }
    }

    while (sub<s){
        i=rand()%o;
        j=rand()%o;

        if((ocean[i][j]==' ')){
            ocean[i][j]='2';
            ocean[i-1][j-1]='1';
            ocean[i-1][j]='1';
            ocean[i-1][j+1]='1';
            ocean[i][j-1]='1';
            ocean[i][j+1]='1';
            ocean[i+1][j-1]='1';
            ocean[i+1][j]='1';
            ocean[i+1][j+1]='1';
            sub++;
        }
    }
}
void showSubmarines(char rep[o][o], char ocean[o][o])
{
    int i,j;
    for (i=0;i<o;i++)
        for(j=0;j<o;j++)
            if(rep[i][j]=='2')
                ocean[i][j]='S';
}
int argMD(char *argv[])
{
    int MD=0;
    if(strcmp(argv[1],"-t")==0){
        if(strcmp(argv[4],"PLAY")==0)
            MD=PLAY;
        else 
            MD=CORR;
    }
    else if(strcmp(argv[3],"-t")==0){
        if(strcmp(argv[2],"PLAY")==0)
            MD=PLAY;
        else 
            MD=CORR;
    }
    return MD;
}
int argT(char *argv[])
{
    int t=0;
    if(strcmp(argv[1],"-t")==0)
        t=atoi(argv[2]);

    else if(strcmp(argv[3],"-t")==0)
        t=atoi(argv[4]);

    return t;
}
void shootTorp(char *linha, int *coluna,int *linha_1)
{
    int i;
    char lin='@';
    printf("Insira o setor que deseja atacar(ex: A1): ");
    scanf(" %c",&*linha);
    *linha=toupper(*linha);
    scanf("%d",&*coluna);
    *coluna=*coluna-1;

    for(i=0;i<o;i++){
        lin++;
        if(*linha==lin){
            *linha_1=i;
            i=o-1;
            lin='A';
        }
    }
    if(*linha=='A')
        return;
    if(*linha<65||*linha>o+64)
        *linha_1=99;
}
int errShoot(int coluna, int linha)
{
    if(linha==99)
        return 3;
    if(coluna<0||coluna>o-1){
        return 3;
    }
    else if(linha<0||linha>o-1){
        return 3;
    }
    else
        return 0;
}
int hitShoot(int coluna, int linha, char rep[o][o], char ocean[o][o])
{
    int i,j;
    if(rep[linha][coluna]=='2'){
        if(ocean[linha][coluna]=='*'||ocean[linha][coluna]=='W')
            return 3;//ja atirou ai

        ocean[linha][coluna]='*';
        return 1;//acertou
    }
    else if (rep[linha][coluna]!='2'){
        if(ocean[linha][coluna]=='W')
            return 3;//ja atirou ai
        ocean[linha][coluna]='W';
        return 2;//errou
    }
}
void didHit(int tiro, int *q_t, int *q_s)
{
    switch(tiro){
        case 1:
            printf("\n\n\n\nVoce afundou um submarino!!\n");
            *q_t=*q_t-1;
            *q_s=*q_s-1;
            break;
        case 2:
            printf("\n\n\n\nSeu tiro se perdeu no mar!!\n");
            *q_t=*q_t-1;
            break;
        case 3:
            printf("\n\n\n\nVoce ja atacou esse setor do oceano. Tente novamente.\n");
            break;
    }
}
void endGame(int q_d, int q_s, int q_t)
{   
    if(q_t==0){//Verifica qual foi a condicao para o jogo ter acabado
        if((q_s==0)&&(q_d==0))
            fprintf(stderr,"\n\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");
        else 
            fprintf(stderr,"\n\nVoce perdeu o jogo :(\nAcabaram todos os seus torpedos.\n");
    }
    
    else if((q_s==0)&&(q_d==0))//Verifica qual foi a condicao para o jogo ter acabado
        fprintf(stderr,"\n\nVoce ganhou o jogo :)!!!!\nAcabaram todos os navios no oceano.\n");
}