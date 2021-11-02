/*
showMatrix 
-------------------------------------------
Imprime a matriz mtx na tela, da forma LxC.
*/
void showMatrix (int mtx[L][C]){
    int i,j;
    
    for(i=0;i<L;i++){
        for(j=0;j<C;j++)
            printf("%2d ",mtx[i][j]);
        printf("\n");
    }
}