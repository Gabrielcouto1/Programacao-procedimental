/*
loadMatrix 
-----------------------------------------------------------------------------
Carrega a matriz LxC inserida. Pode ser usada para digitacao do usuario
ou para carregamento de valores contidos em um arquivo.
*/
void loadMatrix (int mtx[L][C]){
    int i,j;
    int v=0;    //Valor digitado pelo usuario ou coletado em algum arquivo

    for(i=0;i<L;i++)
        for(j=0;j<C;j++){
            scanf("%d",&v);
            mtx[i][j]=v;
        }
}