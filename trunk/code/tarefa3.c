#include <stdio.h>
#include "constants.h"
#include "trie_t.h"



/**
  * O intuito deste programa é carregar, em memória, o conteúdo de um
  * dicionário e efetuar a procura de uma dada palavra, através do \e
  * stdin.
  * O programa pede inicialmente o caminho do ficheiro, e de seguida pede
  * ao utilizador para inserir uma palavra a procurar num dicionário, previemente carregado em memória.
  **/
int main()
{   char dict [MAXSTR];
    char palavra[MAXSTR];
    int err,  existe_pal;
    NODO *trie;
    existe_pal = 0;
    printf ( "Introduza o caminho do dicionario a carregar\n" );
    err = scanf ( "%s", dict );
    
    if ( err == 0 )
        return 1;
        
    trie = carregar_dic_t ( dict, OFFSET_CHAR_LOWER );
    
    if ( trie == NULL )
        return 1;
        
    printf ( "Palavra a procurar:\n" );
    err = scanf ( "%s", palavra );
    
    if ( err == 0 )
        return 1;
        
    existe_pal =  e_pal ( trie, palavra, OFFSET_CHAR_LOWER );
    
    if ( existe_pal )
        printf ( "%s existe\n", palavra );
        
    else
        printf ( "%s NÃO existe\n", palavra );
        
    return 0;
}


