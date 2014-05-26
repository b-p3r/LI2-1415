#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>
#include <string.h>

#define ALFABETO (27)



#define MAXSTRI 26
#define MAXPAL 100000


#define MAX 1000


typedef struct t_nodo {

    struct t_nodo * nodo [ALFABETO];
    int value;

}NODO;

typedef struct arv_trie {

    NODO* raiz;
    int count;

}TRIE;


NODO *novo_nodo(void)
{
    NODO *res = NULL;

    res = (NODO *)malloc(sizeof(struct t_nodo));

    if( res ) {
        int i;

        res->value = 0;

        for(i = 0; i < ALFABETO; i++) {
            res->nodo[i] = NULL;
        }
    }

    return res;
}

void init(TRIE *t)
{
    t->raiz = novo_nodo();
    t->count = 0;
}

void inserir_pal(TRIE *t, char pal[])
{

    int  nivel, tam;
    int i = 0;

    tam = strlen(pal);

    NODO *aux = NULL;
    t->count++;
    aux = t->raiz;


    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-'a';

        if(aux->nodo[i]==NULL)
            aux->nodo[i]= novo_nodo();
        aux = aux->nodo[i];
    }

    aux->value = t->count;
}

int existe(TRIE *t, char pal[])
{
    int i, nivel, tam;

    tam = strlen(pal);


    NODO * aux = NULL;
    aux = t->raiz;


    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-'a';
 
        aux = aux->nodo[i];
    }

    return (aux!=NULL&&aux->value);
}




/**
 * A função principal lê dois inteiros do \e stdin (o no de linhas \e nlin e o
no de colunas \e ncol da sopa de letras) e seguidamente lê linhas da sopa de letras. Após isso o
programa lê o nº de coordenadas \e n e seguidamente os \e n pares de coordenadas sabendo que
primeiro lê o no da linha e depois o no da coluna.
 * */
int main()
{
    
    char dict [MAXSTRI] = "./dicio.txt";

    
    unsigned int i;
    FILE *f;

    char palavras[MAXPAL] [MAXSTRI];
    char resultado [MAX];



    unsigned int j,l, c ,linha, err, escolha , nlin, ncol, existe_pal;
    TRIE trie;

    linha = existe_pal= 0;
    err = 0;




    f = fopen(dict, "r");

    while (fgets(palavras[linha], MAXSTRI, f) != NULL) {
        palavras[linha][strlen(palavras[linha])-1] = '\0';
        linha++;

    }
    fclose(f);
    printf("Numero de palavras = %d\n", linha);

    init(&trie);


    
    for(i = 0; i < linha ; i++) {

       
        inserir_pal(&trie, palavras[i]);

    }


    printf("Numero de palavras = %d\n", linha);
    scanf("%s",resultado);


    if(existe(&trie, resultado)) printf("%s EXISTE", resultado);
    else printf("%s NÂO EXISTE", resultado);





    return 0;
}
