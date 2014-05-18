#include <stdio.h>
#include "proc_sopa.h"
#include "coord.h"


#define MAX 1000



/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna.
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
    procura_string(x, y, ncoords,mat, resultado);

    printf("%s\n", resultado);
    return 0;
}
