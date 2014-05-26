#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>
#include <string.h>
#define ALFABETO (26)



#define MAXSTRI 26
#define MAXPAL 100000


#define MAX 1000


typedef struct t_nodo {

    struct t_nodo * nodo [ALFABETO];
    int e_pal;

} NODO;


NODO* novo_nodo ()
{

    NODO * res = NULL;

    res = (NODO*) malloc (sizeof(struct t_nodo));

    if(res!=NULL) {
        int i;
        res->e_pal = 0;
        for(i = 0; i < ALFABETO; i++)
            res->nodo[i]=NULL;
    }
    return res;


}


void inserir_pal(NODO *t, char pal[])
{

    int  nivel, tam;
    int i = 0;

    tam = strlen(pal);

    NODO *aux = NULL;

    aux = t;


    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-'a';

        if(aux->nodo[i]==NULL)
            aux->nodo[i]= novo_nodo();
        aux = aux->nodo[i];
    }

    aux->e_pal=1;

}

int existe(NODO* t, char pal[])
{


    int i, nivel, tam;

    tam = strlen(pal);


    NODO * aux = NULL;
    aux = t;



    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-'a';

        if(aux->nodo[i]==NULL)
            return 0;
        aux = aux->nodo[i];
    }

    return (aux!=NULL&&aux->e_pal);


}
void cria_sopa_letras(char mat [][MAX], int nlin, int ncol)
{
    int l, c;

    for(l = 0; l < nlin; l++) {
        for(c = 0; c < ncol; c++)
            mat[l][c] = getchar();
        getchar();
    }

}

void depth_first (int l, int c,int nlin, int ncol, char pal[], int i, char mat[] [MAX], int mat_flag[][MAX], NODO* trie)
{

    if(((l>=0&&l<nlin)&&(c>=0&&c<ncol))&&mat_flag[l][c]==0) {
        pal[i] = tolower(mat[l][c]);
        pal[i+1]='\0';
        mat_flag[l][c] = 1;
    } else return;
    if(existe(trie, pal)) {
        printf("%s\n",pal);
    }

    i++;


    depth_first(l-1, c,nlin, ncol, pal, i, mat, mat_flag, trie);


    depth_first(l-1, c-1,nlin, ncol, pal, i, mat, mat_flag,trie);


    depth_first(l-1, c+1,nlin, ncol, pal, i, mat, mat_flag,trie);


    depth_first(l, c-1, nlin, ncol,pal,  i, mat, mat_flag,trie);



    depth_first(l, c+1, nlin, ncol,pal,  i, mat, mat_flag,trie);


    depth_first(l+1, c-1, nlin, ncol,pal, i, mat, mat_flag,trie);


    depth_first(l+1, c+1, nlin, ncol,pal, i, mat, mat_flag,trie);


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

    char dict [MAXSTRI] = "./dicio.txt";



    unsigned int i;
    FILE *f;

    char palavras[MAXPAL] [MAXSTRI];
    char resultado [MAX];



    unsigned int j,l, c ,linha, err, escolha , nlin, ncol, existe_pal;
    NODO* trie;

    linha = existe_pal= 0;
    err = 0;




    f = fopen(dict, "r");

    while (fgets(palavras[linha], MAXSTRI, f) != NULL) {
        palavras[linha][strlen(palavras[linha])-1] = '\0';
        linha++;

    }
    fclose(f);
    printf("Numero de palavras = %d\n", linha);

    trie = novo_nodo();
    for(i = 0; i < linha ; i++) {


        inserir_pal(trie, palavras[i]);

    }





    /*    for(i = 0; i < linha ; i++) {
            if(palavras[i][0] == '\0')
                break;
            inserir_pal(&trie, palavras[i]);*/

    /*}*/
    /*err = scanf("%d%d\n",&nlin,&ncol);
    if(err  == 0)
        return 1;



    cria_sopa_letras(mat, nlin, ncol);

    for(i = 0; i < nlin; i++) {
        for(j = 0; j < ncol; j++)
            mat_flag[i][j]= 0;
    }*/



    /*while(err == 0) {
        printf("Escolha um movimento.\n");
        printf("1   Serpente.\n");
        printf("2   Passo de cavalo.\n");
        printf("0   Sair.\n");
        err = scanf("%d", &escolha);
        if(err  == 0)
            return 1;

    }*/



    /*for(l = 0, i = 0; l < nlin; l++) {
        for(c = 0; c < ncol; c++)



            depth_first(l, c, nlin, ncol,resultado, i, mat, mat_flag, &trie);



    }*/


    scanf("%s",resultado);



    if(existe(trie, resultado)) printf("%s EXISTE", resultado);
    else printf("%s NÂO EXISTE", resultado);




    return 0;
}
