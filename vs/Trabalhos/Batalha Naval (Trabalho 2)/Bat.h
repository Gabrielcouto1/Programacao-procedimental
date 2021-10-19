const int o=5;
const int s=3;
const int d=0;

#define PLAY 0  //Definicao de "PLAY" para alterar facilmente o modo de execucao do codigo
#define CORR 1  //Definicao de "CORR" para alterar facilmente o modo de execucao do codigo

int argsOk(int argc, char *argv[]);
void initOcean(char ocean[o][o]);
void showOcean(char ocean[o][o]);
void showInventory(int d, int s, int t);
void submarinesIntoOcean (char ocean[o][o]);
void errorMSG(int x);