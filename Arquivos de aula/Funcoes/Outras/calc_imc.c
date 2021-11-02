/*
calc_imc
--------------------
A função calcula e interpreta o IMC com o peso e altura inseridos
e diz se o usuario e abaixo do peso, peso normal, acima do peso ou obeso.

*/
void calc_imc(float peso, float altura)
{
    float imc=0;
    imc=peso/(altura*altura);
    printf("\nIMC=%.2f\n",imc);
    if(imc<18.5)
        printf("\nAbaixo do peso.\n\n");
    else if(imc<25.0)
        printf("\nIMC normal.\n\n");
    else if(imc<30.0)
        printf("\nSobrepeso.\n\n");
    else   
        printf("\nObesidade.\n\n");
}