#include <stdio.h>
#include "coord.h"

/*!
  \def MAX 1000

*/
/*!
   Máximo para \e arrays, colunas e linhas de matrizes.
*/
#define MAX 1000
/*!< */


#define MAX_TEMP 8



void init_cabecalho (int ncol)
{

    int i;
    printf("   _|");
    for(i = 0; i < ncol; i++) {
        printf("_%d_", i);
    }
    putchar('\n');

}

void print_sopa(char mat[][MAX], int nlin, int ncol)
{
    int c, l;

    for(l = 0; l < nlin; l++) {
        printf("%4d|", l);
        for(c = 0; c < ncol; c++) {
            printf(" %c ", mat[l][c]);
        }
        putchar('\n');
    }
}


/**
* Este procedimento cria uma \e sopa \e de \e letras dado um nº de linhas, colunas e uma matriz que é preenchida pelo utlizador.

* @param mat A matriz para preencher.
* @param nlin O nº de linhas da matriz.
* @param ncol O nº de colunas da matriz.
* */
void cria_sopa_letras(char mat [][MAX], int nlin, int ncol)
{
    int l, c;

    for(l = 0; l < nlin; l++) {
        for(c = 0; c < ncol; c++)
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
int le_coords(int x [], int y [])
{
    int ncoords, n, err;
    err = scanf("%d", &ncoords);
    if(err == 0)
        return 0;
    for(n = 0; n < ncoords; n++) {
        err = scanf("%d%d", &x[n], &y[n]);
        if(err == 0)
            return 0;
    }
    return ncoords;

}

int calcula_pos(int a[], int b[], int tipo, int nlin, int ncol, int l, int c)
{


    int jogadas = 0;


    if(tipo == 2)
        jogadas = jogadas_PossiveisPC(a, b, l, c, nlin, ncol);
    if(tipo == 1)
        jogadas = jogadas_Possiveis_Serpent(a, b, l, c, nlin, ncol);

    return jogadas;


}
void introduzir_coords(int * l, int * c)
{
    int err = 0;
    while(err == 0) {
        printf("Introduza um par de coordenadas válido.\n");
        err = scanf("%d%d", &(*l), &(*c));
    }
}

int dentro_limites(int l, int c, int nlin, int ncol)
{

    return (l>=0&&l<nlin)&&(c>=0&&c<ncol);
}


void refrescar_tela(char mat[][MAX], int nlin, int ncol )
{

    init_cabecalho(ncol);
    print_sopa(mat, nlin, ncol);

}
/**
*  * Este procedimento lê um nº de coordenadas e um conjunto de
*  coordenadas do \e stdin. Estas são guardadas em memória
*   * no  \e array x (abcissas) e no  \e array y (ordenadas).
*    * @param x O \e array x (abcissas).
*     * @param y O \e array y (ordenadas).
*      * @return O número total de pares ordenados.
*             * */
int le_coords_jogo(char mat[][MAX], int x [], int y [], int tipo, int nlin, int ncol)
{
    int ncoords, n, jog, l, c, err;

    int tmpx[MAX_TEMP];
    int tmpy[MAX_TEMP];
    n = 0;
    printf("Introduza o total de coordenadas.\n");
    err = scanf("%d", &ncoords);
    if(err == 0)
        return 0;
    printf("Total %d coordenadas\n", ncoords);
    introduzir_coords(&l, &c);
    printf("Jogada introduzida com sucesso!\n\n");
    while(!dentro_limites(l, c, nlin, ncol)) {
        printf("Jogada Inválida.\nCoordenadas introduzidas estão fora do limites.!!!!\n\n");
        introduzir_coords(&l, &c);
    }


    x[0]=l;
    y[0]=c;
    n++;

    jog = calcula_pos(tmpx, tmpy, tipo, nlin, ncol, l, c);

    refrescar_tela(mat, nlin, ncol );
    for( ; n < ncoords; n++) {
        introduzir_coords(&l, &c);

        while(!existe_c(tmpx, tmpy, l, c, jog)||existe_c(x, y, l, c, n)) {
            printf("Jogada Inválida. Introduza novamente!\n");
            if(!existe_c(tmpx, tmpy, l, c, jog))
                printf("(%d %d) não correpondem ao movimento\n", l, c);
            if(existe_c(x, y, l, c, n))
                printf("(%d %d) já foram jogadas \n", l, c);


            introduzir_coords(&l, &c);

        }
        limpar_array_coords(tmpx, tmpy, MAX_TEMP);

        x[n]=l;
        y[n]=c;
        printf("Jogada introduzida com sucesso!\n\n");
        refrescar_tela(mat, nlin, ncol );
        if(n < ncoords-1) {

            jog = calcula_pos(tmpx, tmpy, tipo, nlin, ncol, l, c);

        }
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
void procura_string(int x [], int y [], int ncoords, char mat [] [MAX], char resultado [])
{
    int i, xi, yi;

    for(i = 0; i < ncoords; i++) {
        xi = x[i]-1;
        yi = y[i]-1;

        resultado[i] = mat[xi][yi];
    }


    resultado[i] = '\0';

}

