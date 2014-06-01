#include "trie_t.h"
#include "constants.h"
#include <stdio.h>


/**
 * Esta função conta o número de ocorrências de um caractere numa  \e string
 * Por exemplo, conta as ocorrências de 'a' em "anagrama" e devolve o nº de ocorrências.

 * @param c O caractere a procurar.
 * @param s A  \e string onde onde as ocorrências do caractere serão contadas.
 * */
void depth_first_serpente ( int l, int c, int nlin, int ncol, char pal[], int index, char mat[] [MAX], int mat_flag[][MAX], NODO *trie, NODO *store )

{

    if ( ( ( l >= 0 && l < nlin ) && ( c >= 0 && c < ncol ) ) && mat_flag[l][c] == 0 ) {

        pal[index] = mat[l][c];

        pal[index + 1] = '\0';


        mat_flag[l][c] = 1;

    } else return;

    /*if(!e_prefixo(trie, pal, 'a')) {*/
    /*        mat_flag[l][c] = 0;*/
    /*  return;*/
    /* }*/
    if ( e_pal ( trie, pal, OFFSET_CHAR_UPPER ) ) {
        inserir_pal ( store, pal, OFFSET_CHAR_UPPER );

    }

    index++;

    depth_first_serpente ( l - 1, c, nlin, ncol, pal, index, mat, mat_flag, trie, store );

    depth_first_serpente ( l - 1, c - 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );

    depth_first_serpente ( l - 1, c + 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );

    depth_first_serpente ( l, c - 1, nlin, ncol, pal,  index, mat, mat_flag, trie, store );

    depth_first_serpente ( l, c + 1, nlin, ncol, pal,  index, mat, mat_flag, trie, store );

    depth_first_serpente ( l + 1, c - 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );

    depth_first_serpente ( l + 1, c + 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );

    depth_first_serpente ( l + 1, c, nlin, ncol, pal, index, mat, mat_flag, trie, store );

    mat_flag[l][c] = 0;

}
/**
 * Esta função conta o número de ocorrências de um caractere numa  \e string
 * Por exemplo, conta as ocorrências de 'a' em "anagrama" e devolve o nº de ocorrências.

 * @param c O caractere a procurar.
 * @param s A  \e string onde onde as ocorrências do caractere serão contadas.
 * */
void depth_first_cavalo ( int l, int c, int nlin, int ncol, char pal[], int i, char mat[] [MAX], int mat_flag[][MAX], NODO *trie, NODO *store )

{

    if ( ( ( l >= 0 && l < nlin ) && ( c >= 0 && c < ncol ) ) && mat_flag[l][c] == 0 ) {

        pal[i] = mat[l][c];

        pal[i + 1] = '\0';

        mat_flag[l][c] = 1;

    } else return;

    /*if(!e_prefixo(trie, pal, 'a')) {*/
    /*        mat_flag[l][c] = 0;*/
    /*  return;*/
    /* }*/
    if ( e_pal ( trie, pal, OFFSET_CHAR_UPPER ) ) {
        inserir_pal ( store, pal, OFFSET_CHAR_UPPER );
        /*printf("%s\n",pal);*/
    }

    i++;

    depth_first_cavalo ( l - 2 , c + 1 , nlin, ncol, pal, i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l - 2 , c - 1 , nlin, ncol, pal, i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l - 1 , c - 2 , nlin, ncol, pal, i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l + 1, c - 2 , nlin, ncol, pal,  i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l - 1, c + 2 , nlin, ncol, pal,  i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l + 1 , c + 2 , nlin, ncol, pal, i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l + 2 , c + 1 , nlin, ncol, pal, i, mat, mat_flag, trie, store );

    depth_first_cavalo ( l - 2 , c - 1 , nlin, ncol, pal, i, mat, mat_flag, trie, store );

    mat_flag[l][c] = 0;

}
