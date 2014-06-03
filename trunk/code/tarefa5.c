#include <stdio.h>
#include <ctype.h>
#include "proc_sopa.h"
#include "coord.h"
#include "cadeias.h"
#include "trie_t.h"
#include "utils.h"
#include "search_m.h"
#include "constants.h"
#include <string.h>



/**
 * A função principal deste programa lê um movimento de \e stdin, as
 * dimensões de uma matriz da sopa de letras, e a sopa de letras. De
 * seguida calcula todas as jogadas e procura todas as palavras da sopa de
 * letras segundo um movimento.
 * */

int main()
{   int i, index, l, c, mov, err, nlin, ncol;
    NODO *trie;
    NODO *store;
    char movimento[8];
    char mat [MAX] [MAX];
    int mat_flag[MAX] [MAX];
    char  resultado [MAXSTR];
    index = 0;
    trie = carregar_dic_t ( DICIONARIO, OFFSET_CHAR_UPPER );
    
    if ( trie == NULL )
        return 1;
        
    store = novo_nodo();
    
    if ( store==NULL )
        return 1;
        
    mov = i = 0;
    err = scanf ( "%s", movimento );
    
    if ( err  == 0 )
        return 1;
        
    if ( strcmp ( movimento , SERPENTE ) == 0 )
        mov = MOV_SERP;
        
    else if ( strcmp ( movimento , CAVALO ) == 0 )
        mov = MOV_SERP;
        
    else return 1;
    
    err = scanf ( "%d%d\n", &nlin, &ncol );
    
    if ( err  == 0 )
        return 1;
        
    cria_sopa_letras ( mat, nlin, ncol );
    
    if ( mov==MOV_SERP )
    {   */
    
        for ( l = 0, i = 0; l < nlin; l++ )
            for ( c = 0; c < ncol; c++ )
                depth_first_serpente ( l, c, nlin, ncol, resultado, index, mat, mat_flag, trie, store );
    }
    
    if ( mov==MOV_CAV )
    {   for ( l = 0, i = 0; l < nlin; l++ )
            for ( c = 0; c < ncol; c++ )
                depth_first_cavalo ( l, c, nlin, ncol, resultado, index, mat, mat_flag, trie, store );
    }
    
    i = 0;
    imprimir_t ( store, resultado, i, OFFSET_CHAR_UPPER );
    return 0;
}


