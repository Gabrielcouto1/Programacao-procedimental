const int L=2;  //Quantidade de linhas das matrizes
const int C=3;  //Quantidade de colunas das matrizes

/*
doubleMatrix
-----------------------------------------------------------------------------
Calcula o dobro da matriz m inserida previamente e armazena na matriz d.
Ambas tem dimensao LxC.
*/
void doubleMatrix(int m[L][C], int d[L][C]);

/*
loadMatrix 
-----------------------------------------------------------------------------
Carrega a matriz LxC inserida. Pode ser usada para digitacao do usuario
ou para carregamento de valores contidos em um arquivo.
*/
void loadMatrix (int mtx[L][C]);

/*
showMatrix 
-------------------------------------------
Imprime a matriz mtx na tela, da forma LxC.
*/
void showMatrix (int mtx[L][C]);