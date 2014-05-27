#include <stdio.h>
#include <ctype.h>
#include "proc_sopa.h"
#include "coord.h"
#include "cadeias.h"
#include "trie_t.h"
#include "utils.h"
#include "search_m.h"

#include <stdlib.h>
#include <string.h>




#define OFFSET_CHAR 'A'

#define MAX 100
#define DICIONARIO "../dicio.txt"
#define SERPENTE "serpente"
#define CAVALO "cavalo"
#define MOV_SERP 1
#define MOV_CAV 2



/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna.
 * */
int main()
{



    int i,j,l,c, mov, err, nlin, ncol;

    NODO* trie;
    NODO* store;

    char movimento[8];
    char mat [MAX] [MAX];
    int mat_flag[MAX] [MAX];
    char  resultado [MAX];



    trie = carregar_dict_t(DICIONARIO);
    if(trie == NULL)
        return 1;
    store = novo_nodo();
    if(store==NULL)
        return 1;


    mov = i = 0;
    /*função de escolha do movimento*/
    err = scanf("%s",movimento);

    if(err  == 0)
        return 1;

    mov = strcmp(movimento , SERPENTE);

    if(mov==0)
        printf("S %d\n", MOV_SERP);
    mov = -1;
    mov = strcmp(movimento , CAVALO);

    if(mov==0)
        printf("C %d\n", MOV_CAV);


    err = scanf("%d%d\n",&nlin,&ncol);
    if(err  == 0)
        return 1;


    cria_sopa_letras(mat, nlin, ncol);

    /*função para inicializar matriz para sopa*/
    for(i = 0; i < nlin; i++) {
        for(j = 0; j < ncol; j++)
            mat_flag[i][j]= 0;
    }


    for(l = 0, i = 0; l < nlin; l++) {
        for(c = 0; c < ncol; c++) {

            depth_first(l, c, nlin, ncol,resultado, i, mat, mat_flag, trie, store);

        }

    }



    imprimir_t(store, resultado, i, OFFSET_CHAR);


    return 0;
}
