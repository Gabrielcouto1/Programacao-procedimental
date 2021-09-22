while (dest<d){//Determina a posicao dos destruidores
        i_2[dest]=rand()%o;
        j_2[dest]=rand()%o;
        dir_dest=rand()%2;
        if(dir_dest==0){    //O destruidor tem 2 casas verticais 
            if(oceano[i_2[dest]][j_2[dest]]==' '&&oceano[i_2[dest]+1][j_2[dest]]==' '){
            oceano[i_2[dest]][j_2[dest]]='D';
            oceano[i_2[dest]+1][j_2[dest]]='D';
            dest++;
            }
        }
        else{               //O destruidor tem 2 casas horizontais
            if(oceano[i][j]==' '&&oceano[i][j+1]==' '){
            oceano[i][j]='D';
            oceano[i][j+1]='D';
            dest++;
            }
        }
        
    }