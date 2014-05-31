
#include <stdio.h>
#include <string.h>
#include "cadeias.h"
#include "constants.h"

/**
* Esta função verifica se determinada palavra existe no dicionário
* carregado em memória.
* @param dic O dicionário carregado em memória.
* @param numpal O número total de linhas do dicionário.
* @param pal A palavra a procurar.
* @return 1 caso encontre a palavra no dicionário carregado em memória, 0 caso contrário.
**/
int existe ( char dic[MAXPAL][MAXSTR], int numpal, char pal[MAXSTR] )
{
    int encontrou = 0, res, liminf = 0, limsup = numpal - 1, meio;

    while ( !encontrou && liminf <= limsup ) {
        meio = liminf + ( limsup - liminf ) / 2;

        res = cad_comparar ( dic[meio], pal );

        switch ( res ) {
            case -1:
                liminf = meio + 1;
                break;
            case 0:
                encontrou = 1;
                break;
            case 1:
                limsup = meio - 1;
                break;
        }
    }

    return encontrou;
}


/**
  * Esta função carrega os dados de um dicionário em memória, e devolve
  * o número total de linhas do documento.
  * @param dict O caminho do ficheiro a carregar em memória.
  * @param dicionario A matriz para onde será carregado o conteúdo do
  * ficheiro.
  * @return linha O número total de linhas do documento.
 **/
int carregar_dic ( char dict [MAXSTR], char dicionario[MAXPAL][MAXSTR] )
{

    int linha = 0;
    FILE *d;
    d = fopen ( dict, MODO_LEITURA );

    if ( d != NULL ) {
        while ( fgets ( dicionario[linha], MAXSTR, d ) != NULL ) {
            dicionario[linha][strlen ( dicionario[linha] ) - 1] = '\0';
            linha += 1;
        }

        fclose ( d );
        printf ( "Dicionário em memória!\n" );
    } else {
        printf ( "Não foi possível ler dicionario!\n" );
    }

    return linha;

}




