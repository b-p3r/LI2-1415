#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALFABETO 26


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


void inserir_pal(NODO *t, char pal[], char offset_char)
{

    int  nivel, tam;
    int i = 0;

    NODO *aux = NULL;

    tam = strlen(pal);
    aux = t;


    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-offset_char;

        if(aux->nodo[i]==NULL)
            aux->nodo[i]= novo_nodo();
        aux = aux->nodo[i];
    }

    aux->e_pal=1;

}

int existe(NODO* t, char pal[], char offset_char)
{


    int i, nivel, tam;
    NODO * aux = NULL;
    tam = strlen(pal);
    aux = t;

    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-offset_char;

        if(aux->nodo[i]==NULL)
            return 0;
        aux = aux->nodo[i];
    }

    return (aux!=NULL&&aux->e_pal);
}



int e_prefixo(NODO* t, char pal[], char offset_char)
{


    int i, nivel, tam;
    NODO * aux = NULL;

    tam = strlen(pal);

    aux = t;

    for(nivel = 0; nivel< tam; nivel++) {
        i = pal[nivel]-offset_char;

        if(aux->nodo[i]==NULL)
            return 0;
        aux = aux->nodo[i];
    }

    return (aux!=NULL);
}

int append_char2str(char pal [], char a,  int i)
{

    pal[i]=a;
    pal[i+1]='\0';
    i++;
    return i;
}

int imprimir_t(NODO *t, char pal[], int i, char offset_char)
{

    int nivel;
    if(t==NULL)
        return i;

    NODO * aux = t;

    if(aux->e_pal) {
        getchar();

        printf("%s",pal);

    }

    for(nivel = 0; nivel < ALFABETO; nivel++ ) {

        if(aux->nodo[nivel]!=NULL) {


            i = append_char2str(pal, nivel+offset_char, i);
            i = imprimir_t(aux->nodo[nivel],pal, i, offset_char);
            i--;

        }

    }
    return i;
}
