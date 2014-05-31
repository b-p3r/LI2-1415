#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "constants.h"


/*!
  \typedef t_nodo
  Estrutura que representa um nodo de uma \e retrieval \e tree (árvore de prefixos).

*/
typedef struct t_nodo {
	/*@{*/
    struct t_nodo *nodo [ALFABETO];/**< Um \e array de apontadores para os filhos da árvore */
    /*@}*/
    /*@{*/
    int e_pal;/**< Um inteiro para representar se um nodo é uma folha da árvore */
    /*@{*/

} NODO;


/*!
     A função novo_nodo(), aloca memória para um novo nodo da árvore, 
     colocando todos os apontadores do nodo a NULL.
	 .
     @return  res   Um endereço de um novo nodo da árvore.
     */
NODO *novo_nodo ()
{

    NODO *res = NULL;

    res = ( NODO * ) malloc ( sizeof ( struct t_nodo ) );

    if ( res != NULL ) {
        int i;
        res->e_pal = 0;

        for ( i = 0; i < ALFABETO; i++ )
            res->nodo[i] = NULL;
    }

    return res;


}

/*!
     A função inserir_pal, aloca memória para um novo nodo da árvore, 
     colocando todos os apontadores do nodo a NULL.
	 @param t O endereço da árvore
	 @param pal A \e string a inserir.
	 @param offset_char O caractere para cálculo do índice do \e array 
	 onde estará um apontador.
     @return  res   Um endereço de um novo nodo da árvore.
     */
void  ( NODO *t, char pal[], char offset_char )
{

    int  nivel, tam;
    int i = 0;

    NODO *aux = NULL;

    tam = strlen ( pal );
    aux = t;


    for ( nivel = 0; nivel < tam; nivel++ ) {
        i = pal[nivel] - offset_char;

        if ( aux->nodo[i] == NULL )
            aux->nodo[i] = novo_nodo();

        aux = aux->nodo[i];
    }

    aux->e_pal = 1;

}
/*!
     A função e_vizinho, verifica se determinado caractere da árvore tem
     algum nodo na vizinhaça. Recebe um nodo
     colocando todos os apontadores do nodo a NULL.
	 @param t O endereço do nodo
	 @param letra O  caractere a procurar.
	 @param offset_char O caractere para cálculo do índice do \e array.
     @return  ap   O endereço de um novo nodo num nível abaixo da árvore,
      ou o mesmo nodo caso contrário.
     */
NODO *e_vizinho ( NODO *t, char letra, char offset_char )
{
    NODO *ap = t;
    int i = letra - offset_char;

    if ( ap->nodo[i] != NULL ) {
        ap = next->nodo[i];
        return ap;
    } else return ap;
}

/*!
     A função e_vizinho, verifica se determinado caractere da árvore tem
     algum nodo na vizinhaça. Recebe um nodo
     colocando todos os apontadores do nodo a NULL.
	 @param t O endereço do nodo
	 @param letra O  caractere a procurar.
	 @param offset_char O caractere para cálculo do índice do \e array.
     @return  ap   O endereço de um novo nodo num nível abaixo da árvore,
      ou o mesmo nodo caso contrário.
     */
NODO *e_prefixo ( NODO *t, char pal[], char offset_char )
{


    int i, nivel, tam;
    NODO *ap = NULL;

    tam = strlen ( pal );

    ap = t;

    for ( nivel = 0; nivel < tam; nivel++ ) {
        i = pal[nivel] - offset_char;

        if ( ap->nodo[i] == NULL )
            return NULL;

         = aux->nodo[i];
    }

    return ( aux );
}

/*!
    A função e_pal, verifica se determinada \e string pertence à arvore.
    * 
	 @param t O endereço do árvore
	 @param pal A \e string a inserir.
	 @param offset_char O caractere para cálculo do índice do \e array.
     @return  1 se a palavra existe, 0, caso contrário.
     */
int e_pal ( NODO *t, char pal[], char offset_char )
{


    NODO *aux = NULL;
    aux = t;

    if ( aux == NULL )
        return 0;

    if ( aux != NULL )
        aux = e_prefixo ( aux, pal, offset_char );

    return ( aux != NULL && aux->e_pal );
}

/*!
     @param t O endereço da árvore
	 @param pal A \e string que irá guardar os caracteres, calculados em 
	 cada chamada recursiva da função.
	 @param index O índice da \e string, que será incrementado e 
	 decrementado, consoante novos caracteres sejam obtidos, ou não 
	 sejam necessários.
	 @param offset_char O caractere para cálculo do índice do \e array.
	 .
     @return  index   O índice actual da \e string.
     */
int imprimir_t ( NODO *t, char pal[], int index, char offset_char )
{

    int nivel;

    NODO *aux = t;

    if ( t == NULL )
        return index;


    if ( aux->e_pal ) {

        printf ( "%s\n", pal );

    }

    for ( nivel = 0; nivel < ALFABETO; nivel++ ) {

        if ( aux->nodo[nivel] != NULL ) {


            index = append_char2str ( pal, nivel + offset_char, i );
            index = imprimir_t ( aux->nodo[nivel], pal, i, offset_char );
            index--;

        }

    }

    return index;
}

/*!
     A função novo_nodo(), aloca memória para um novo nodo da árvore, 
     colocando todos os apontadores do nodo a NULL.
	 .
     @return  res   Um endereço de um novo nodo da árvore.
     */
NODO *carregar_dic_t ( char dict [] , char offset_char)
{
    NODO *store = NULL;

    char palavra[MAXSTR];



    FILE *d;
    d = fopen ( dict, MODO_LEITURA );

    if ( d != NULL ) {
        store = novo_nodo();

        while ( fgets ( palavra, MAXSTR, d ) != NULL ) {
            palavra[strlen ( palavra ) - 1] = '\0';
            if(offset_char == OFFSET_CHAR_LOWER)
            str2upper ( palavra );

            inserir_pal ( store, palavra, offset_char);

        }

        fclose ( d );

    }

    return store;

}



