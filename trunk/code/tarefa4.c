#include <stdio.h>
#include <ctype.h>
#include "proc_sopa.h"
#include "coord.h"
#include "utils.h"
#include "trie_t.h"
#include "constants.h"



/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna.
 * */
int main()
{
    char mat[MAX][MAX];
    int x1[MAX], y1[MAX];
    NODO *trie;
    char dict [MAXSTR];
    char resultado [MAX];
    char tmp[MAX];
    char c;
    int i, xi, yi , ncoords, err, escolha , nlin, ncol, existe_pal, dim;
    i = ncoords = dim = existe_pal = 0;
    err = 0;
    /*    while ( linha == 0 ) {*/
    /*        printf ( "Introduza o caminho do dicionario a carregar\n" );
            err = scanf ( "%s", dict );*/
    /*  if ( err == 0 )
          return 1;*/
    trie = carregar_dic_t ( DICIONARIO , OFFSET_CHAR_LOWER );
    /*  }*/
    err = 0;
    printf ( "Introduza o dimensões da matriz\n" );
    err = scanf ( "%d%d\n", &nlin, &ncol );
    dim = nlin*ncol;
    printf ( "%d\n", dim );
    if ( err  == 0 )
        return 1;
    if ( dim==1 ) {
        printf ( "Matriz demasiado pequena! Não é possível jogar!\n" );
        return 1;
    }
    cria_sopa_letras ( mat, nlin, ncol );
    init_cabecalho ( ncol );
    print_sopa ( mat, nlin, ncol );
    printf ( "Escolha um movimento.\n" );
    printf ( "1   Serpente.\n" );
    if ( dim>4 )
        printf ( "2   Passo de cavalo.\n" );
    printf ( "0   Sair.\n" );
    err = scanf ( "%d", &escolha );
    if ( err  == 0 )
        return 1;
    while ( !existe_pal ) {
        switch ( escolha ) {
            case 1 :
                ncoords = le_coords_jogo ( mat, x1, y1, 1, nlin, ncol );
                break;
            case 2:
                ncoords = le_coords_jogo ( mat, x1, y1, 2, nlin, ncol );
                break;
        }
        if ( escolha == 0 )
            return 0;
        for ( i = 0; i < ncoords; i++ ) {
            xi = x1[i];
            yi = y1[i];
            resultado[i] = mat[xi][yi];
            tmp [i] = tolower ( mat[xi][yi] );
        }
        resultado[i] = '\0';
        tmp[i] = '\0';
        /*if ( linha == 0 )
            return 1;*/
        printf ( "%s\n", resultado );
        existe_pal = e_pal ( trie, tmp, OFFSET_CHAR_LOWER );
        if ( existe_pal ) {
            printf ( "%s é uma palavra! Parabéns!\n", resultado );
            printf ( "Quer jogar novamente?(s/n)\n" );
            getchar();
            c = getchar();
            if ( c == 's' || c == 'S' )
                existe_pal = 0;
            else return 0;
        } else {
            printf ( "%s não é uma palavra!\n", resultado );
            printf ( "Quer jogar novamente?(s/n)\n" );
            getchar();
            c = getchar();
            if ( c == 's' || c == 'S' )
                existe_pal = 0;
            else return 0;
        }
        while ( tmp[i] ) {
            tmp [i] = '\0';
            i++;
        }
    }
    return 0;
}
