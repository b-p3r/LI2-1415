#include <stdio.h>
#include <ctype.h>
#include "proc_sopa.h"
#include "coord.h"
#include "utils.h"
#include "trie_t.h"
#include "constants.h"



/**
 * Este programa tem por objetivo, disponibilizar a um utilizador, o jogo da sopa de letras
 * com dois movimentos: o serpentear e o passo de cavalo. O programa
 * carrega o dicionário para consulta em memória, pede ao utilizador as
 * dimensões da matriz, a sopa de letras e total de coordendas. De seguida o jogador
 * introduz as coordenadas correspondentes às posições das letras na sopa,
 * construindo assim uma palavra, que poderá está ou não na sopa de letras
 * */
int main()
{   char mat[MAX][MAX];
    int x1[MAX], y1[MAX];
    NODO *trie;
    char dict [MAXSTR];
    char resultado [MAX];
    char tmp[MAX];
    char c;
    int i, xi, yi , ncoords, err, escolha , nlin, ncol, existe_pal, dim;
    i = ncoords = dim = existe_pal = 0;
    err = 0;
    /*Carregar dicionário na árveore de profixos*/
    trie = carregar_dic_t ( DICIONARIO , OFFSET_CHAR_LOWER );
    
    if ( trie == NULL )
        return 1;
        
    /* Intruduzir dimensões da matriz*/
    printf ( "Introduza o dimensões da matriz\n" );
    err = scanf ( "%d%d\n", &nlin, &ncol );
    dim = nlin*ncol;
    
    if ( err  == 0 )
        return 1;
        
    /* Se a matriz for 1x1 não é possível jogar*/
    if ( dim==1 )
    {   printf ( "Matriz demasiado pequena! Não é possível jogar!\n" );
        return 1;
    }
    
    cria_sopa_letras ( mat, nlin, ncol );
    init_cabecalho ( ncol );
    print_sopa ( mat, nlin, ncol );
    printf ( "Escolha um movimento.\n" );
    printf ( "1   Serpente.\n" );
    
    /*Se ao dimensão for 2x2 no é possível jogar com passo de cavalo*/
    if ( dim>4 )
        printf ( "2   Passo de cavalo.\n" );
        
    printf ( "0   Sair.\n" );
    /*Selecciona escolha*/
    err = scanf ( "%d", &escolha );
    
    if ( err  == 0 )
        return 1;
        
    /* Enquanto não encontrar uma palavra continua o ciclo*/
    while ( !existe_pal )
    {   switch ( escolha )
        {   case 1 :
                ncoords = le_coords_jogo ( mat, x1, y1, 1, nlin, ncol );
                break;
                
            case 2:
                ncoords = le_coords_jogo ( mat, x1, y1, 2, nlin, ncol );
                break;
        }
        
        if ( escolha == 0 )
            return 0;
            
        /*Guarda os valores introduzidos das jogadas num array
        * temporário*/
        
        for ( i = 0; i < ncoords; i++ )
        {   xi = x1[i];
            yi = y1[i];
            resultado[i] = mat[xi][yi];
            tmp [i] = tolower ( mat[xi][yi] );
        }
        
        resultado[i] = '\0';
        tmp[i] = '\0';
        printf ( "%s\n", resultado );
        /* procura palavra na árvore de prefixos*/
        existe_pal = e_pal ( trie, tmp, OFFSET_CHAR_LOWER );
        
        if ( existe_pal )
        {   printf ( "%s é uma palavra! Parabéns!\n", resultado );
            printf ( "Quer jogar novamente?(s/n)\n" );
            getchar();
            c = getchar();
            
            if ( c == 's' || c == 'S' )
                existe_pal = 0;
                
            else
                return 0;
        }
        
        else
        {   printf ( "%s não é uma palavra!\n", resultado );
            printf ( "Quer jogar novamente?(s/n)\n" );
            getchar();
            c = getchar();
            
            if ( c == 's' || c == 'S' )
                existe_pal = 0;
                
            else
                return 0;
        }
        
        limpar_array ( tmp );
    }
    
    return 0;
}

