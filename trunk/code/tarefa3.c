#include <stdio.h>

#include "proc_dict.h"
#define MAXSTR 25
#define MAXPAL 100000
#define MODO_LEITURA "r"

/**
  * O intuito deste programa é carregar, em memória, o conteúdo de um
  * dicionário e efetuar a procura de uma dada palavra, através do \e
  * stdin. 
  * O programa pede inicialmente o caminho do ficheiro, e de seguida pede
  * ao utilizador para inserir uma palavra a procurar
  **/
int main()
{
    char dicionario[MAXPAL][MAXSTR];
    char dict [MAXSTR];
    int err, linha = 0;
    printf("Introduza o caminho do dicionario a carregar\n");
    err = scanf("%s", dict);
    if(err==0)
        return 1;

    linha = carregar_dic(dict, dicionario);
    if(linha==0)
        return 1;
    procura_pal(dicionario, linha);




    return 0;
}
