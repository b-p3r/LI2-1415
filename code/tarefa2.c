#include <stdio.h>
#define MAX 1000

/**
 * Este procedimento cria uma \e sopa \e de \e letras dado um nº de linhas, colunas e uma matriz que é preenchida pelo utlizador

 * @param mat A matriz para preencher
 * @param nlin O nº de linhas da matriz
 * @param ncol O nº de colunas da matriz
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
  * no array x (abcissas) e no array y (ordenadas)

 * @param x O \e array x (abcissas)
 * @param y O \e array y (ordenadas)
 * @return O número total de pares ordenados
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
/**
 * Este procedimento procura uma \e string, dados dois \e arrays (x - abcissas, y - ordenadas ) com as
 * coordenadas dos caracteres, o nº total de pares ordenados, o nº de linhas e o nº de colunas da matriz:

 * @param x O \e array x (abcissas)
 * @param y O \e array y (ordenadas)
 * @param nlin O nº de linhas da matriz
 * @param ncol O nº de colunas da matriz
 * @param ncoords  O número total de pares ordenados
 * @param mat A matriz a procurar.
 * @param resultado O \e array para guardar o resultado da procura (a string encontrada).
 * */
void procura_string(int x [], int y [], int nlin, int ncol, int ncoords, char mat [] [MAX], char resultado [])
{
    int i,l, c, xi, yi;

    for(i = 0; i < ncoords; i++) {
        xi = x[i]-1;
        yi = y[i]-1;
        for(l = 0; l < nlin; l++) {
            for(c = 0; c < ncol; c++)
                if(xi == l&& yi == c)
                    resultado[i] = mat[l][c];
        }

    }
    resultado[i] = '\0';

}


/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna .
 * */
int main()
{
    int nlin, ncol, n;
    char mat[MAX][MAX];
    int x[MAX], y[MAX];
    int  ncoords;
    char resultado [MAX];

    n = scanf("%d%d\n", &nlin, &ncol);
    if(n == 0)
        return 1;

    cria_sopa_letras(mat, nlin, ncol);

    ncoords = le_coords(x, y);
    procura_string(x, y, nlin, ncol, ncoords,mat, resultado);

    printf("%s\n", resultado);
    return 0;
}
