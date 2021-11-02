/*
timesTable 
-------------------------------
Apresenta a tabuada de n indo de 1 ate q, 
com k multiplicacoes por linha.
*/
void timesTable (int n, int k, int q){
    int i=1;
    int t=0;
    int m=0;

    for (m=1; m<=q;m++){
        printf("%d * %d = %d\t",n,m,n*m);
        if(m%k==0){
            printf("\n");
        }
    }
    printf("\n");
}