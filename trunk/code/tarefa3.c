#include <stdio.h>
#include "proc_dict.h"

#define MAXSTR 25
#define MAXPAL 100000


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
    char palavra[MAXSTR];
    int err, linha, existe_pal;
    linha = existe_pal = 0;
    printf("Introduza o caminho do dicionario a carregar\n");
    err = scanf("%s", dict);
    if(err==0)
        return 1;

    linha = carregar_dic(dict, dicionario);
    if(linha==0)
        return 1;

    printf("Palavra a procurar:\n");
    err = scanf("%s", palavra);
    if(err==0)
        return 1;

    existe_pal  =  existe(dicionario, linha, palavra);
    if (existe_pal)
        printf("%s existe\n", palavra);
    else
        printf("%s NÃO existe\n", palavra);





    return 0;
}
