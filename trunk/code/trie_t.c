#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "constants.h"


/*!

  \typedef NODO
    @brief Tipo NODO que é uma \e struct \c t_nodo
	*
*/
/** @struct t_nodo;
 *  @brief Estrutura que representa um nodo de uma \e retrieval \e tree (árvore de prefixos).
 */
typedef struct t_nodo
{   /*@{*/
    struct t_nodo *nodo [ALFABETO];/**< Um \e array de apontadores para os filhos da árvore */
    /*@}*/
    /*@{*/
    int e_pal;/**< Um inteiro para representar se um nodo é uma folha da árvore */
    /*@{*/
    
} NODO;


/*!
     A função \c novo_nodo(), aloca memória para um novo nodo da árvore,
     colocando todos os apontadores do nodo a NULL.
     @return Um endereço de um novo nodo.
     */
NODO *novo_nodo ()
{   NODO *res = NULL;
    res = ( NODO * ) malloc ( sizeof ( struct t_nodo ) );
    
    if ( res != NULL )
    {   int i;
        res->e_pal = 0;
        
        for ( i = 0; i < ALFABETO; i++ )
            res->nodo[i] = NULL;
    }
    
    return res;
}

/*!
* A função \c inserir_pal, aloca memória para um novo nodo da árvore,
* colocando todos os apontadores do nodo a NULL.
* @param t O endereço da árvore
* @param pal A \e string a inserir.
* @param offset_char O caractere para cálculo do índice do \e array
* onde estará um apontador.
* @return Um endereço de um novo nodo da árvore.
  */
void inserir_pal ( NODO *t, char pal[], char offset_char )
{   int  nivel, tam;
    int i = 0;
    NODO *ap = NULL;
    tam = strlen ( pal );
    ap = t;
    
    for ( nivel = 0; nivel < tam; nivel++ )
    {   i = pal[nivel] - offset_char;
    
        if ( ap->nodo[i] == NULL )
            ap->nodo[i] = novo_nodo();
            
        ap = ap->nodo[i];
    }
    
    ap->e_pal = 1;
}
/*!
* A função \c e_vizinho, verifica se determinado caractere da árvore tem
* algum nodo na vizinhaça. Recebe um nodo
* colocando todos os apontadores do nodo a NULL.
* @param t O endereço do nodo
* @param letra O  caractere a procurar.
* @param offset_char O caractere para cálculo do índice do \e array.
* @return O endereço de um novo nodo num nível abaixo da árvore,
* ou o mesmo nodo caso contrário.
*
  */
NODO *e_vizinho ( NODO *t, char letra, char offset_char )
{   NODO *ap = t;
    int i = letra - offset_char;
    
    if ( ap->nodo[i] != NULL )
    {   ap = ap->nodo[i];
        return ap;
    }
    
    else
        return NULL;
}

/*!
 * A função \c e_prefixo, verifica se determinado \e string é um prefixo, i. e,
 * se todos os caracteres da \e string pertencem à árvore.
 * @param t O endereço do nodo
 * @param pal A palavra a verificar.
 * @param offset_char O caractere para cálculo do índice do \e array.
 * @return  ap  O endereço de um novo nodo correspondente do nível que contém a referência para 
 * o último caractere, ou o NULL caso contrário.
     */
NODO *e_prefixo ( NODO *t, char pal[], char offset_char )
{   
int i, nivel, tam;
    NODO *ap = NULL;
    tam = strlen ( pal );
    ap = t;
    
    for ( nivel = 0; nivel < tam; nivel++ )
    {   i = pal[nivel] - offset_char;
    
        if ( ap->nodo[i] == NULL )
            return NULL;
            
        ap = ap->nodo[i];
    }
    
    return ( ap );
}

/*!
 * A função \c e_pal, verifica se determinada \e string pertence à arvore.
 * @param t O endereço do árvore
 * @param pal A \e string a procurar.
 * @param offset_char O caractere para cálculo do índice do \e array.
 * @return  1 se a palavra existe, 0, caso contrário.
     */
int e_pal ( NODO *t, char pal[], char offset_char )
{   NODO *ap = NULL;
    ap = t;
    
    if ( ap == NULL )
        return 0;
        
    if ( ap != NULL )
        ap = e_prefixo ( ap, pal, offset_char );
        
	return ( ap != NULL && ap->e_pal );
}

/*!
 * A função \c imprimir_t imprime no \e stdout todas as palavras de uma dada \e trie, por ordem alfabética.
 * @param t O endereço da árvore
 * @param pal A \e string que irá guardar os caracteres, calculados em cada chamada recursiva da função.
 * @param index O índice da \e string, que será incrementado e decrementado, 
 * consoante novos caracteres sejam obtidos, ou não sejam necessários.
 * @param offset_char O caractere para cálculo do índice do \e array.
 * @return  index   O índice actual da \e string.
     */
int imprimir_t ( NODO *t, char pal[], int index, char offset_char )
{   int nivel;
    NODO *ap = t;
    
    if ( t == NULL )
        return index;
        
    if ( ap->e_pal )
        printf ( "%s\n", pal );
        
    for ( nivel = 0; nivel < ALFABETO; nivel++ )
    {   if ( ap->nodo[nivel] != NULL )
        {   index = append_char2str ( pal, nivel + offset_char, index );
            index = imprimir_t ( ap->nodo[nivel], pal, index, offset_char );
            index--;
        }
    }
    
    return index;
}

/**
 * Este procedimento carrega um ficheiro de texto em memória com a estrutura de uma \e trie.
 * @param dict O caractere a procurar.
 * @param offset_char O caractere para cálculo do índice do \e array.
 * */
NODO *carregar_dic_t ( char dict [] , char offset_char )
{   NODO *store = NULL;
    char palavra[MAXSTR];
    FILE *d;
    d = fopen ( dict, MODO_LEITURA );
    
    if ( d != NULL )
    {   store = novo_nodo();
    
        while ( fgets ( palavra, MAXSTR, d ) != NULL )
        {   palavra[strlen ( palavra ) - 1] = '\0';
        
            if ( offset_char == OFFSET_CHAR_UPPER )
                str2upper ( palavra );

                
            inserir_pal ( store, palavra, offset_char );
        }
        
        fclose ( d );
    }
    
    return store;
}




