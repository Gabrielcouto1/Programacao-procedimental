/*
doubleMatrix
-----------------------------------------------------------------------------
Calcula o dobro da matriz m inserida previamente e armazena na matriz d.
Ambas tem dimensao LxC.
*/
void doubleMatrix(int m[L][C], int d[L][C]){
    int i,j;

    for (i=0;i<L;i++)
        for(j=0;j<C;j++)
            d[i][j]=2*m[i][j];
}