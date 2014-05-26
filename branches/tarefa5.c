#include <stdio.h>
#include <ctype.h>





#include <stdlib.h>
#include <string.h>


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])


#define ALPHABET_SIZE (26)


#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define MAXSTRI 26
#define MAXPAL 100000


#define MAX 1000


typedef struct trie_node trie_node_t;
struct trie_node {
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};


typedef struct trie trie_t;
struct trie {
    trie_node_t *root;
    int count;
};


trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode ) {
        int i;

        pNode->value = 0;

        for(i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}

void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] ) {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    pCrawl->value = pTrie->count;
}

int search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);

        if( !pCrawl->children[index] ) {
            return 0;
        }

        pCrawl = pCrawl->children[index];
    }

    return (0 != pCrawl && pCrawl->value);
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

void cria_sopa_letras(char mat [][MAX], int nlin, int ncol)
{
    int l, c;

    for(l = 0; l < nlin; l++) {
            for(c = 0; c < ncol; c++)
                mat[l][c] = getchar();
            getchar();
        }

}

void depth_first (int l, int c,int nlin, int ncol, char pal[], int i, char mat[] [MAX], int mat_flag[][MAX], trie_t *trie)
{

    if(((l>=0&&l<nlin)&&(c>=0&&c<ncol))&&mat_flag[l][c]==0) {
        pal[i] = tolower(mat[l][c]);
        pal[i+1]='\0';
        mat_flag[l][c] = 1;
    } else return;
    if(search(trie, pal)) {
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
    char dicionario[MAXPAL][MAXSTRI];
    char dict [MAXSTRI] = "./dicio.txt";


    int contador[MAXSTRI];
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

 

            depth_first(l, c, nlin, ncol,resultado, i, mat, mat_flag, &trie);



    }




    /*existe_pal  =  existe(dicionario, linha, tmp);*/




    return 0;
}
