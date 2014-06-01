#include "trie_t.h"
#include "constants.h"
#include <stdio.h>
#include <string.h>


/** Esta função procura recursivamente numa sopa de letras, todas as
 * palavras segundo o movimento de serpente.
 * À medida que a sopa de letras é percorrida as palavras encontradas são
 * colocadas numa \e trie \c store, e cada posição fica marcada já
 * percorrida fica marcada numa matriz com \e flags correspondente
 * à matriz de sopa de letras, e vai construindo palavras utilizando
 * os parâmetros \c pal (\e string) e \c index, através da chamada
 * recursiva da função.
 * A função implementa um algoritmo de \e depth-first-search.

 * @param l A linha correspondente à primeira componente do par ordenado a verificar.
 * @param c A coluna correspondente à segunda componente do par ordenado
 * a verificar.
 * @param nlin O total número de linhas.
 * @param ncol O total número de colunas.
 * @param pal A \e string que recebe os caracteres obtidos da sopa de
 * letras.
 * @param index O índice da \e string \c pal.
 * @param mat A matriz correspondentes à sopa de letras.
 * @param mat_flag A matriz correspondente à matriz de \e flags.
 * @param trie A \e trie com um dicionário carregado.
 * @param store A \e trie para armazenar as palavras encontradas.
 *
 * */
void depth_first_serpente ( int l, int c, int nlin, int ncol, char pal[], int index, char mat[] [MAX], int mat_flag[][MAX], NODO *trie, NODO *store )
{   NODO *aux =NULL;

    if ( ( ( l >= 0 && l < nlin ) && ( c >= 0 && c < ncol ) ) && mat_flag[l][c] == 0 && strlen ( pal ) < 26 )
    {   aux  =  e_vizinho ( trie, mat[l][c], OFFSET_CHAR_UPPER );
    
        if ( aux != NULL )
        {   pal[index] = mat[l][c];
            pal[index + 1] = '\0';
            mat_flag[l][c] = 1;
        }
        
        else
        {   mat_flag[l][c] = 1;
            return;
        }
    }
    
    else
        return;
        
    if ( e_pal ( trie, pal, OFFSET_CHAR_UPPER ) )
        inserir_pal ( store, pal, OFFSET_CHAR_UPPER );
        
    index++;
    depth_first_serpente ( l - 1, c,     nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l - 1, c - 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l - 1, c + 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l,     c - 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l,     c + 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l + 1, c - 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l + 1, c + 1, nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_serpente ( l + 1, c,     nlin, ncol, pal, index, mat, mat_flag, trie, store );
    mat_flag[l][c] = 0;
}




/** Esta função procura recursivamente numa sopa de letras, todas as
 * palavras segundo o movimento de cavalo.
 * À medida que a sopa de letras é percorrida as palavras encontradas são
 * colocadas numa \e trie \c store, e cada posição fica marcada já
 * percorrida fica marcada numa matriz com \e flags correspondente
 * à matriz de sopa de letras, e vai construindo palavras utilizando
 * os parâmetros \c pal (\e string) e \c index, através da chamada
 * recursiva da função.
 * A função implementa um algoritmo de \e depth-first-search.
 *
 * @param l A linha correspondente à primeira componente do par ordenado a verificar.
 * @param c A coluna correspondente à segunda componente do par ordenado
 * a verificar.
 * @param nlin O total número de linhas.
 * @param ncol O total número de colunas.
 * @param pal A \e string que recebe os caracteres obtidos da sopa de
 * letras.
 * @param index O índice da \e string \c pal.
 * @param mat A matriz correspondentes à sopa de letras.
 * @param mat_flag A matriz correspondente à matriz de \e flags.
 * @param trie A \e trie com um dicionário carregado.
 * @param store A \e trie para armazenar as palavras encontradas.
 *
 * */
void depth_first_cavalo ( int l, int c, int nlin, int ncol, char pal[], int index, char mat[] [MAX], int mat_flag[][MAX], NODO *trie, NODO *store )

{   NODO *aux = NULL;

    if ( ( ( l >= 0 && l < nlin ) && ( c >= 0 && c < ncol ) ) && mat_flag[l][c] == 0 && strlen ( pal ) < 26 )
    {   aux  =  e_vizinho ( trie, mat[l][c], OFFSET_CHAR_UPPER );
    
        if ( aux != NULL )
        {   pal[index] = mat[l][c];
            pal[index + 1] = '\0';
            mat_flag[l][c] = 1;
        }
        
        else
        {   mat_flag[l][c] = 1;
            return;
        }
    }
    
    else
        return;
        
    if ( e_pal ( trie, pal, OFFSET_CHAR_UPPER ) )
        inserir_pal ( store, pal, OFFSET_CHAR_UPPER );
        
    index++;
    depth_first_cavalo ( l - 2 , c + 1 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l - 2 , c - 1 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l - 1 , c - 2 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l + 1 , c - 2 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l - 1 , c + 2 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l + 1 , c + 2 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l + 2 , c + 1 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    depth_first_cavalo ( l - 2 , c - 1 , nlin, ncol, pal, index, mat, mat_flag, trie, store );
    mat_flag[l][c] = 0;
}






