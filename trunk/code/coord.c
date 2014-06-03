#include <stdio.h>
#include "constants.h"

/**
 * Esta função verifica se uma determinada posição existe, tanto no
 * calculo das jogadas possíveis, bem como verifica na verificação de uma
 * jogada já efetuada.
 * @param x Um \e array que guarda os valores das primeiras componentes dos pares ordenados.
 * @param y Um \e array que guarda os valores das segundas componentes dos pares ordenados.
 * @param l O nº  de linha do posição da qual se irá fazer a comparação.
 * @param c O nº  de coluna da posição da qual se irá fazer a comparação.
 * @param tam O tamanho da \e string.
 * @return 1 se a posição existe. 0 caso contrário
 * */

int existe_c ( int x [], int y [], int l, int c , int tam )
{   int i, existe = 0;

    for ( i = 0; i <= tam; i++ )
    {   if ( x[i] == l && y[i] == c )
        {   existe = 1;
            break;
        }
    }

    return existe;
}


/** Esta função apaga todas posições guardadas nos \e arrays com as
 * coordenadas colocando o valor -1 (valor impossível das coordenadas).
 * Esta função é aplicada para apgar os valores das jogadas legais
 * calculdas.
 * @param x O array que guarda os valores das primeiras componentes dos
 * pares ordenados.
 * @param y O array que guarda os valores das segundas componentes dos
 * pares ordenados.
 * @param n O tamanho de ambos os \e arrays. 
 * */
void limpar_array_coords ( int x [], int y [], int n )
{   int i;

    for ( i = 0; i < n; i++ )
    {   x[i] = -1;
        y[i] = -1;
    }
}

/**
 * Esta função calcula a coordenada correspondente a linha dada uma
 * orientação, para efeito de cálculo de jogadas possíveis, segundo 
 * o movimento de serpente.

 * @param l O número da linha para o cálculo. 
 * @param pos A orientação para onde deve ser feito o cálculo de
 * translação
 * */
int calcularCoordX_Serpen ( int l, int pos )
{   int res = 0;

    switch ( pos )
    {   case N :
            res = l - 1;
            break;

        case NW :
            res = l - 1;
            break;

        case NE :
            res = l - 1;
            break;

        case W :
            res = l;
            break;

        case E :
            res = l;
            break;

        case SW :
            res = l + 1;
            break;

        case SE :
            res = l + 1;
            break;

        case S :
            res = l + 1;
            break;
    }

    return res;
}

/**
 * Esta função calcula a coordenada correspondente a coluna dada uma
 * orientação, para efeito de cálculo de jogadas possíveis, segundo 
 * o movimento de serpente.

 * @param c O número da coluna para o cálculo 
 * @param pos A orientação para onde deve ser feito o cálculo de
 * translação
 * */
int calcularCoordY_Serpen ( int c, int pos )
{   int res = 0;

    switch ( pos )
    {   case N :
            res = c;
            break;

        case NW :
            res = c - 1;
            break;

        case NE :
            res = c + 1;
            break;

        case W :
            res = c - 1;
            break;

        case E :
            res = c + 1;
            break;

        case SW :
            res = c - 1;
            break;

        case SE :
            res = c + 1;
            break;

        case S :
            res = c;
            break;
    }

    return res;
}


/**
 * Esta função calcula a coordenada correspondente a linha dada uma
 * orientação, para efeito de cálculo de jogadas possíveis, segundo 
 * o movimento de passo de cavalo.

 * @param l O número da linha para o cálculo 
 * @param pos A orientação para onde deve ser feito o cálculo de
 * translação
 * */

int calcularCoordX_Passo_Cav ( int l, int pos )
{   int res = 0;

    switch ( pos )
    {   case N1 :
            res = l - 2;
            break;

        case N2 :
            res = l - 2;
            break;

        case W1 :
            res = l - 1;
            break;

        case E1 :
            res = l - 1;
            break;

        case W2 :
            res = l + 1;
            break;

        case E2 :
            res = l + 1;
            break;

        case S1 :
            res = l + 2;
            break;

        case S2 :
            res = l + 2;
            break;
    }

    return res;
}


/**
 * Esta função calcula a coordenada correspondente a coluna dada uma
 * orientação, para efeito de cálculo de jogadas possíveis, segundo 
 * o movimento de passo de cavalo.

 * @param c O número da coluna para o cálculo 
 * @param pos A orientação para onde deve ser feito o cálculo de
 * translação.
 * */
int calcularCoordY_Passo_Cav ( int c, int pos )
{   int res = 0;

    switch ( pos )
    {   case N1 :
            res = c - 1;
            break;

        case N2 :
            res = c + 1;
            break;

        case W1 :
            res = c - 2;
            break;

        case E1 :
            res = c + 2;
            break;

        case W2 :
            res = c - 2;
            break;

        case E2 :
            res = c + 2;
            break;

        case S1 :
            res = c - 1;
            break;

        case S2 :
            res = c + 1;
            break;
    }

    return res;
}

/**
 * Esta função aplica as funções \ref calcularCoordX_Passo_Cav e \ref
 * calcularCoordY_Passo_Cav e calcula todas as coordenadas possíveis
 * a partir de uma posição, para o movimento passo de cavalo.
     
 * @param a Um \e array temporário que guarda os valores das primeiras
 * componentes dos pares ordenados
 * @param b Um \e array temporário que guarda os valores das segundas
 * componentes dos pares ordenados
 * @param l O nº  de linha do posição da qual se irá fazer o cálculo.
 * @param c O nº  de coluna da posição da qual se irá fazer o cálculo.
 * @param nlin O total nº de linhas.
 * @param ncol O total nº de colunas.
 * @return i O total das jogadas calculadas.
 * */
int jogadas_PossiveisPC ( int a[], int b[], int l, int c, int nlin, int ncol )
{   int i, j, linha , coluna;

    for ( i = 0, j = 1; j <= 8; j++ )
    {   linha = calcularCoordX_Passo_Cav ( l, j );
        coluna = calcularCoordY_Passo_Cav ( c, j );

        if ( ( l >= 0 && l < nlin ) && ( c >= 0 && c < ncol ) )
        {   a[i] = linha;
            b[i] = coluna;
            i++;
        }
    }

    return i;
}


/**
 * Esta função aplica as funções \ref calcularCoordX_Serpen e \ref
 * calcularCoordY_Serpen e calcula todas as coordenadas possíveis
 * a partir de uma posição, para o movimento de serpente.
     
 * @param a Um \e array temporário que guarda os valores das primeiras
 * componentes dos pares ordenados
 * @param b Um \e array temporário que guarda os valores das segundas
 * componentes dos pares ordenados
 * @param l O nº  de linha do posição da qual se irá fazer o cálculo.
 * @param c O nº  de coluna da posição da qual se irá fazer o cálculo.
 * @param nlin O total nº de linhas.
 * @param ncol O total nº de colunas.
 * @return i O total das jogadas calculadas.
 * */
int jogadas_Possiveis_Serpent ( int a[], int b[], int l, int c, int nlin, int ncol )
{   int i, j, linha , coluna;

    for ( i = 0, j = 1; j <= 8; j++ )
    {   linha = calcularCoordX_Serpen ( l, j );
        coluna = calcularCoordY_Serpen ( c, j );

        if (  ( l >= 0 && l < nlin ) && ( c >= 0 && c < ncol ) )
        {   a[i] = linha;
            b[i] = coluna;
            i++;
        }
    }

    return i;
}



