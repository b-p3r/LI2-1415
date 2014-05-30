#include <stdio.h>
#include <ctype.h>
#include "proc_sopa.h"
#include "coord.h"
#include "proc_dict.h"
#include "cadeias.h"
#include "trie_t.h"

#include <stdlib.h>
#include <string.h>

typedef struct mat_content{

char mat[MAX][MAX];
int mat_flag[MAX][MAX];




}


void print_string(char s [], int n)
{
    int i;

    for(i =0; i < n; i++)
        putchar(s[i]);

    putchar('\n');
}

void print_array(int mat [][MAX], int nlin, int ncol)
{
    int i, j;

    for(i =0; i < nlin; i++) {
        for(j =0; j < ncol; j++) {
            if(mat[i][j]==1)
                printf("\033[1;31m %d \033[0m", mat[i][j]);
            else printf(" %d ", mat[i][j]);
        }
        putchar('\n');
    }
}

void limpar_array(char s [], int n)
{
    int i;
    for(i = 0; i < n; i++)
        s[i] = '\0';
}



void depth_first (int l, int c,int nlin, int ncol, char pal[], int i, char mat[] [MAX], int mat_flag[][MAX], trie_t *trie)
{
  
    if(dentro_limites(l, c, nlin, ncol))
        pal[i] = tolower(mat[l][c]);
    pal[i+1]='\0';
 

    if(mat_flag[l][c]==0)
        mat_flag[l][c] = 1;
    else return;
    if(search(trie, pal)) {
        printf("%s\n",pal);
    } 
    
    i++;

    if(dentro_limites(l-1, c, nlin, ncol))
        depth_first(l-1, c,nlin, ncol, pal, i, mat, mat_flag, trie);

    if(dentro_limites(l-1, c-1, nlin, ncol))
        depth_first(l-1, c-1,nlin, ncol, pal, i, mat, mat_flag,trie);

    if(dentro_limites(l-1, c+1, nlin, ncol))
        depth_first(l-1, c+1,nlin, ncol, pal, i, mat, mat_flag,trie);

    if(dentro_limites(l, c-1, nlin, ncol))
        depth_first(l, c-1, nlin, ncol,pal,  i, mat, mat_flag,trie);


    if(dentro_limites(l, c+1, nlin, ncol))
        depth_first(l, c+1, nlin, ncol,pal,  i, mat, mat_flag,trie);

    if(dentro_limites(l+1, c-1, nlin, ncol))
        depth_first(l+1, c-1, nlin, ncol,pal, i, mat, mat_flag,trie);

    if(dentro_limites(l+1, c+1, nlin, ncol))
        depth_first(l+1, c+1, nlin, ncol,pal, i, mat, mat_flag,trie);

    if(dentro_limites(l+1, c, nlin, ncol))
        depth_first(l+1, c, nlin, ncol,pal, i, mat, mat_flag,trie);


    mat_flag[l][c] = 0;

}


/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna.
 * */
int main()
{
    char mat[MAX][MAX];
    int mat_flag[MAX][MAX];
    char dicionario[MAXPAL][MAXSTRI];
    char dict [MAXSTRI] = "./dicio.txt";
   


    unsigned int i;
    FILE *f;

    char palavras[MAXPAL] [MAXSTRI];
    char resultado [MAX];



    unsigned int j,l, c ,linha, err, escolha , nlin, ncol, existe_pal;
    trie_t trie;

    linha = existe_pal= 0;
    err = 0;




    f = fopen(dict, "r");

    while (fgets(palavras[linha], MAXSTRI, f) != NULL) {
        palavras[linha][strlen(palavras[linha])-1] = '\0';
        linha++;

    }
    fclose(f);
    printf("Numero de palavras = %d\n", linha);

    initialize(&trie);


    printf("Palavra %s\n", palavras[0]);
    printf("Palavra %u\n", ARRAY_SIZE(palavras));
    for(i = 0; i < ARRAY_SIZE(palavras) ; i++) {

        if(palavras[i][0] == '\0')
            break;
        insert(&trie, palavras[i]);

    }
    err = scanf("%d%d\n",&nlin,&ncol);
    if(err  == 0)
        return 1;


    cria_sopa_letras(mat, nlin, ncol);
    for(i = 0; i < nlin; i++) {
        for(j = 0; j < ncol; j++)
            mat_flag[i][j]= 0;
    }

    init_cabecalho(ncol);
    print_sopa(mat, nlin, ncol);
    /*while(err == 0) {
        printf("Escolha um movimento.\n");
        printf("1   Serpente.\n");
        printf("2   Passo de cavalo.\n");
        printf("0   Sair.\n");
        err = scanf("%d", &escolha);
        if(err  == 0)
            return 1;

    }*/



    for(l = 0, i = 0; l < nlin; l++) {
        for(c = 0; c < ncol; c++)

            /* printf("(%d,%d)\n", c,l);
             printf("%c\n", mat[l][c]);*/
            depth_first(l, c, nlin, ncol,resultado, i, mat, mat_flag, &trie);

        /*limpar_array(resultado , i);
        i = 0;*/
    }




    /*existe_pal  =  existe(dicionario, linha, tmp);*/




    return 0;
}
