const int o = 5;
const int s = 3;
const int d = 0;

#define PLAY 0  //Definicao de "PLAY" para alterar facilmente o modo de execucao do codigo
#define CORR 1  //Definicao de "CORR" para alterar facilmente o modo de execucao do codigo

/*
argsOk
-------------------------------------------------------------------------------------------
A funcao checa se os argumentos inseridos sao validos e retorna um valor.*/
int argsOk(int argc, char *argv[]);
/*
errorMSG
-------------------------------------------------------------------------------------------
A funcao checa o valor retornado na funcao argsOk e se tiver algum erro
ela mostra na tela e encerra o programa.
*/
void errorMSG(int x);
/*
initOcean
-------------------------------------------------------------------------------------------
A funcao inicia a matriz oceano com espacos em branco ' '.*/
void initOcean(char ocean[o][o]);
/*
showInventory

A funcao mostra a quantidade de torpedos no inventario e quantas naves ainda restam.*/
void showInventory(int d, int s, int t);
/*
showOcean
-------------------------------------------------------------------------------------------
A funcao mostra o oceano atual na tela do usuario.*/
void showOcean(const char ocean[o][o]);
/*
submarinesIntoOcean
-------------------------------------------------------------------------------------------
A funcao gera pesudo-aleatoriamente os submarinos no oceano.
*/
void submarinesIntoOcean (char ocean[o][o]);
/*
showSubmarines
-------------------------------------------------------------------------------------------
Se o modo for CORR, a funcao mostra no oceano onde estao todas as naves.
*/
void showSubmarines(char rep[o][o], char ocean[o][o]);
/*
argMD
-------------------------------------------------------------------------------------------
A funcao armazena o argumento de modo de jogo inserido.
*/
int argMD(char *argv[]);
/*
argT
-------------------------------------------------------------------------------------------
A funcao armazena o argumento de quantidade de torpedos inseridos.
*/
int argT(char *argv[]);
/*
shootTorp
-------------------------------------------------------------------------------------------
A funcao armazena em qual setor do oceano o usuario deseja atacar.
*/
void shootTorp(char *linha, int *coluna,int *linha_1);
/*
errShoot
-------------------------------------------------------------------------------------------
A funcao verifica se existe algum erro com o setor que o usuario atacou.
Ela retorna um valor.
*/
int errShoot(int coluna, int linha);
/*hitShoot
-------------------------------------------------------------------------------------------
A funcao verifica se o setor que o usuario atacou tem uma nave ou se ele ja 
atirou neste setor. Retorna um valor.
*/
int hitShoot(int coluna, int linha, char rep[o][o], char ocean[o][o]);
/*
didHit
-------------------------------------------------------------------------------------------
A funcao verifica e escreve na tela se o usuario ja atirou nesta casa
ou se eh uma casa invalida.
*/
void didHit(int tiro, int *q_t, int *q_s);
/*
endGame
-------------------------------------------------------------------------------------------
A funcao verifica qual a condicao de fim de jogo e se o usuario ganhou 
ou perdeu o jogo.
*/
void endGame(int q_d, int q_s, int q_t);