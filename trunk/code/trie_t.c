#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/*!
   Constante utilizada para definir o modo de acesso a um determinado ficheiro (neste caso só leitura).
*/
#define MODO_LEITURA "r"
/*!< */

#define ALFABETO 26


#define OFFSET_CHAR 'A'

#define MAXSTR 25


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

int e_pal(NODO* t, char pal[], char offset_char)
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


int imprimir_t(NODO *t, char pal[], int i, char offset_char)
{

    int nivel;
    if(t==NULL)
        return i;

    NODO * aux = t;

    if(aux->e_pal) {
        /*getchar();*/

        printf("%s\n",pal);

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
NODO* carregar_dic_t(char dict [])
{
    NODO* store = NULL;

    char palavra[MAXSTR];


    int linha = 0;
    FILE *d;
    d = fopen(dict, MODO_LEITURA);
    if (d!=NULL) {
        store = novo_nodo();
        while (fgets(palavra, MAXSTR, f) != NULL) {
            palavra[strlen(palavra)-1] = '\0';
            str2upper(palavra);

            inserir_pal(store, palavra, OFFSET_CHAR);


        }
        fclose(d);

    }


    return store;

}



