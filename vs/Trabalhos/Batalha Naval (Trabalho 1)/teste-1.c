for(i=0;i<o;i++){   //Caso o usuario acerte um tiro
            for(j=0;j<o;j++){
                if((i_1[i]==coluna_ataque-1)&&(j_1[j]==linha_ataque_1)){
                    printf("\nVoce acertou um navio!\n");
                    acerto++;
                    oceano[linha_ataque_1][coluna_ataque]='*';
                }
            }
        }
        if (acerto==0){//O usuario errou o tiro
            printf("Voce nao acertou nenhum navio!\n");
            oceano[linha_ataque_1][coluna_ataque]='W';
        }
        acerto=0;
        //182-195