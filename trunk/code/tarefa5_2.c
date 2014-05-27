#include <stdio.h>
#include <ctype.h>
#include "trie_t.h"
#include <stdlib.h>
#include <string.h>



#define MAXSTR 26
#define MAXPAL 100000


#define MAX 1000




/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna.
 * */
int main()
{



    char dict [MAXSTR] = "../dicio.txt";



    int i;
    FILE *f;

    char palavras[MAXPAL] [MAXSTR];
    char  resultado [MAX];



    unsigned int linha, existe_pal;
    NODO* trie;

    linha = existe_pal= 0;





    f = fopen(dict, "r");

    while (fgets(palavras[linha], MAXSTR, f) != NULL) {
        palavras[linha][strlen(palavras[linha])-1] = '\0';
        linha++;

    }
    fclose(f);
    printf("Numero de palavras = %d\n", linha);

    trie = novo_nodo();
    for(i = 0; i < linha ; i++) {


        inserir_pal(trie, palavras[i], 'a');

    }


    i = 0;

    scanf("%s",resultado);

    if(existe(trie, resultado, 'a')) printf("%s EXISTE", resultado);
    else printf("%s NÂO EXISTE", resultado);

//    scanf("%s",resultado);
//
//
//
//    if(e_prefixo(trie, resultado, 'a')) printf("%s E_PREF", resultado);
//    else printf("%s NÂO E_PREF", resultado);

    //imprimir_t(trie, resultado, i, 'a');


    return 0;
}
