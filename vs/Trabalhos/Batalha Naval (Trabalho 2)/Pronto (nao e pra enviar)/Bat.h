const int o = 5;
const int s = 3;
const int d = 0;

#define PLAY 0  //Definicao de "PLAY" para alterar facilmente o modo de execucao do codigo
#define CORR 1  //Definicao de "CORR" para alterar facilmente o modo de execucao do codigo

int argsOk(int argc, char *argv[]);
void errorMSG(int x);
void initOcean(char ocean[o][o]);
void showInventory(int d, int s, int t);
void showOcean(const char ocean[o][o]);
void submarinesIntoOcean (char ocean[o][o]);
void showSubmarines(char rep[o][o], char ocean[o][o]);
int argMD(char *argv[]);
int argT(char *argv[]);
void shootTorp(char *linha, int *coluna,int *linha_1);
int errShoot(int coluna, int linha);
int hitShoot(int coluna, int linha, char rep[o][o], char ocean[o][o]);
void didHit(int tiro, int *q_t, int *q_s);
void endGame(int q_d, int q_s, int q_t);