#include
#define MAX 1000

int main()
{
    int nlin, ncol;
    char mat[MAX][MAX];
    int x[MAX], y[MAX];
    int ncoords;
    int l, c, n;
char resultado [MAX];
    scanf("%d%d\n", &nlin, &ncol);
    for(l = 0; l < nlin; l++) {
        for(c = 0; c < ncol; c++)
            mat[l][c] = getchar();
        getchar(); /* ler o \n final de cada linha */
    }
    scanf("%d", &ncoords);
    for(n = 0; n < ncoords; n++) {
        scanf("%d%d", &x[n], &y[n]);
    }
	for(i = 0; i < n; i++)
		x[i]; y[i];
	
    /*
     *     Fazer o codigo que procura a string e a devolve
     *       */
    printf("Encontrei a string '%s'\n", resultado);
    return 0;
}
