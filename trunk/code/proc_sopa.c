#include <stdio.h>
#include "coord.h"

#include "constants.h"

/**
 * Este procedimento cria no \e stdout um cabeçalho
 * com o número de coluna na sopa de letras.
 * @param ncol O número total de colunas.
 * */

void init_cabecalho ( int ncol )
{   int i;
    printf ( "   _|" );
    
    for ( i = 0; i < ncol; i++ )
        printf ( "_%4d_", i );
        
    putchar ( '\n' );
}
/**
 * Este procedimento imprime no \e stdout uma sopa de letras, com formatação
 * específica para incluir o número de linha do lado esquerdo.
 * @param mat A matriz com a sopa de letras.
 * @param nlin O número total de linhas da sopa de letras.
 * @param ncol O número total de colunas da sopa de letras.
 * */
void print_sopa ( char mat[][MAX], int nlin, int ncol )
{   int c, l;

    for ( l = 0; l < nlin; l++ )
    {   printf ( "%4d|", l );
    
        for ( c = 0; c < ncol; c++ )
            printf ( " %4c ", mat[l][c] );
            
        putchar ( '\n' );
    }
}


/**
* Este procedimento cria uma \e sopa \e de \e letras dado um nº de linhas, 
* colunas e uma matriz que é preenchida pelo utlizador.
* @param mat A matriz para preencher.
* @param nlin O nº de linhas da matriz.
* @param ncol O nº de colunas da matriz.
* */
void cria_sopa_letras ( char mat [][MAX], int nlin, int ncol )
{   int l, c;

    for ( l = 0; l < nlin; l++ )
    {   for ( c = 0; c < ncol; c++ )
            mat[l][c] = getchar();
            
        getchar();
    }
}
/**
* Este procedimento lê um nº de coordenadas e um conjunto de coordenadas do \e stdin. Estas são guardadas em memória
* no  \e array x (abcissas) e no  \e array y (ordenadas).
* @param x O \e array x (abcissas).
* @param y O \e array y (ordenadas).
* @return O número total de pares ordenados.
* */
int le_coords ( int x [], int y [] )
{   int ncoords, n, err;
    err = scanf ( "%d", &ncoords );
    
    if ( err == 0 )
        return 0;
        
    for ( n = 0; n < ncoords; n++ )
    {   err = scanf ( "%d%d", &x[n], &y[n] );
    
        if ( err == 0 )
            return 0;
    }
    
    return ncoords;
}
/**
  Esta função utiliza as funções \ref jogadas_PossiveisPC e \ref jogadas_Possiveis_Serpent
  para calcular a jogadas legais, segundo um movimento.

 * @param a O \e array \c a a preencher com as jogadas calculadas,
 * relativamente as linhas.
 * @param b O \e array \c a a preencher com as jogadas calculadas,
 * relativamente as linhas.
 * @param tipo O tipo de movimento escolhido.
 * @param nlin O nº total de linhas.
 * @param ncol O nº tototal de colunas.
 * @param l A linha a partir da qual serão calculadas as coordenadas
 * correspondentes às linhas.
 * @param A coluna a partir da qual serão calculadas as coordenadas
 * correspondentes às colunas.
 *
 * @return O número total de jogadas possíveis.
 * */
int calcula_pos ( int a[], int b[], int tipo, int nlin, int ncol, int l, int c )
{   int jogadas = 0;

    if ( tipo == 2 )
        jogadas = jogadas_PossiveisPC ( a, b, l, c, nlin, ncol );
        
    if ( tipo == 1 )
        jogadas = jogadas_Possiveis_Serpent ( a, b, l, c, nlin, ncol );
        
    return jogadas;
}
/**
 * Nesta função é pedido ao utilizador que introduza um par de coordenadas
 * que serão guardadas no endereço de memória das duas variáveis.
 * @param l Um apontador para o endereço da variável linha em memória.
 * @param c Um apontador para o endereço da variável coluna em memória.
 * */
void introduzir_coords ( int *l, int *c )
{   int err = 0;
    printf ( "Introduza um par de coordenadas.\n" );
    
    while ( err==0 )
    {   getchar();
        err = scanf ( "%d%d", l, c );
        
        if ( err==0 )
            printf ( "Introduza coordenadas de forma correta.\n" );
    }
}

/**
 * Esta função utiliza a função \ref init_cabecalho e \ref print_sopa para
 * desenhar a sopa de letras com uma formatão específica no \ stdout
 * @param mat A matriz com a sopa de letras.
 * @param nlin O nº de linhas da matriz.
 * @param ncol O nº de colunas da matriz.
 * */
void refrescar_tela ( char mat[][MAX], int nlin, int ncol )
{   init_cabecalho ( ncol );
    print_sopa ( mat, nlin, ncol );
}
/**
 * Neste procedimento são pedidos o nº total de coordenadas ao utilizador,
 * bem como as coordenadas corresponderes à jogada do utilizador, até ao
 * fim da jogada.

 * @param mat A matriz com a sopa de letras.
 * @param x O \e array com as coordenadas correspondentes às linhas.
 * @param y O \e array com as coordenadas correspondetes às colunas.
 * @param tipo O tipo de movimento (serpente ou passo de cavalo).
 * @param nlin O nº de linhas da matriz.
 * @param ncol O nº de colunas da matriz.
 * @return O total de coordenada introduzidas
 * */
int le_coords_jogo ( char mat[][MAX], int x [], int y [], int tipo, int nlin, int ncol )
{   int ncoords, n, jog, l, c, err;
    int tmpx[MAX_TEMP];
    int tmpy[MAX_TEMP];
    int dim = nlin*ncol;
    err=0;
    n = 0;
    /* Introdução de total de coordenadas */
    printf ( "Introduza o total de coordenadas.\n" );
    
    while ( err==0||ncoords>dim||ncoords==0 )
    {   getchar();
        err = scanf ( "%d", &ncoords );
        
        if ( err==0 )
            printf ( "Introduza o total de coordenadas de forma correta.\n" );
            
        if ( ncoords>dim )
            printf ( "Número de coordenadas é maior que o total de letras na sopa.\n" );
            
        if ( ncoords==0 )
            printf ( "Número de coordenadas não pode ser nulo.\n" );
    }
    
    printf ( "Total %d coordenadas\n", ncoords );
    introduzir_coords ( &l, &c );
    printf ( "Jogada introduzida com sucesso!\n\n" );
    
    /*Introdução de jogada válidas no stdin */
    while ( ! ( ( l>=0&&l<nlin ) && ( c>=0&&c<ncol ) ) )
    {   printf ( "Jogada Inválida.\nCoordenadas introduzidas estão fora do limites.!!!!\n\n" );
        introduzir_coords ( &l, &c );
    }
    
    /* Primeiras coordenadas são introduzidas nos \e arrays \c x e \c y */
    x[0]=l;
    y[0]=c;
    /* Índice dos  \e arrays \c x e \c y é incrementado */
    n++;
    /* Cálculo das jogadas legais que serão colocadas nos arrays
     * temporários, sendo jog o número totals de jogadas válidas*/
    jog = calcula_pos ( tmpx, tmpy, tipo, nlin, ncol, l, c );
    refrescar_tela ( mat, nlin, ncol );
    
    for ( ; n < ncoords; n++ )
    {   /* verifica se as jogadas válidas segundo um movimento não existem
         * nos arrays temporários ou se existem nas jogadas já efetuadas*/
        while ( !existe_c ( tmpx, tmpy, l, c, jog ) ||existe_c ( x, y, l, c, n ) )
        {   introduzir_coords ( &l, &c );
            printf ( "Jogada Inválida. Introduza novamente!\n" );
            
            if ( !existe_c ( tmpx, tmpy, l, c, jog ) )
                printf ( "(%d %d) não correpondem ao movimento\n", l, c );
                
            if ( existe_c ( x, y, l, c, n ) )
                printf ( "(%d %d) já foram jogadas \n", l, c );
        }
        
        /* Limpar array temporário com coordenadas calculadas */
        limpar_array_coords ( tmpx, tmpy, MAX_TEMP );
        /* Insere coordenadas l (linha) e c (coluna) nos dois arrays com
         * as coordenadas*/
        x[n]=l;
        y[n]=c;
        printf ( "Jogada introduzida com sucesso!\n\n" );
        refrescar_tela ( mat, nlin, ncol );
        
        /* Calcula posições legais até à penúltima jogada */
        if ( n < ncoords-1 )
            jog = calcula_pos ( tmpx, tmpy, tipo, nlin, ncol, l, c );
    }
    
    return ncoords;
}


/**
* Este procedimento procura uma \e string, dados dois \e arrays (x - abcissas, y - ordenadas ) com as
* coordenadas dos caracteres, o nº total de pares ordenados, o nº de linhas e o nº de colunas da matriz.

* @param x O \e array x (abcissas);
* @param y O \e array y (ordenadas);
* @param nlin O nº de linhas da matriz;
* @param ncol O nº de colunas da matriz;
* @param ncoords  O número total de pares ordenados;
* @param mat A matriz a procurar.
* @param resultado O \e array para guardar o resultado da procura (a string encontrada).
* */
void procura_string ( int x [], int y [], int ncoords, char mat [] [MAX], char resultado [] )
{   int i, xi, yi;

    for ( i = 0; i < ncoords; i++ )
    {   xi = x[i] - 1;
        yi = y[i] - 1;
        resultado[i] = mat[xi][yi];
    }
    
    resultado[i] = '\0';
}

