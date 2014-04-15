#include <stdio.h>
#define MAX 1000

int main()
{
    int nlin, ncol;
    char mat[MAX][MAX] = {{'A', 'B', 'C', 'D'}, {'E', 'F', 'G', 'H'}, {'I', 'J', 'K', 'L'}};
    int x[MAX], y[MAX];
    int ncoords;
    int l, c, n, xi, yi, i;
    char resultado [MAX];
    
   scanf("%d%d\n", &nlin, &ncol);


    for(l = 0; l < nlin; l++) {
       for(c = 0; c < ncol; c++)
            mat[l][c] = getchar();
        getchar();	/* ler o \n final de cada linha */
    }

    //for(l = 0; l < nlin; l++) {
    //    for(c = 0; c < ncol; c++)
    //        putchar(mat[l][c]); /* ler o \n final de cada linha */
    //    putchar('\n');
    //}

    scanf("%d", &ncoords);
    for(n = 0; n < ncoords; n++) {
        scanf("%d%d", &x[n], &y[n]);
    }
    for(i = 0; i < n; i++) {
        xi = x[i]-1;
        yi = y[i]-1;
        for(l = 0; l < nlin; l++) {
            for(c = 0; c < ncol; c++)
                if(xi == l&& yi == c)
                    resultado[i] = mat[l][c];
        }}
        /*
         *     Fazer o codigo que procura a string e a devolve
         *       */
        printf("Encontrei a string '%s'\n", resultado);
    return 0;
}
