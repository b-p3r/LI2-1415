# include <stdio.h>
#include "t1proc.h"

/*!
  \def MAX 1000

*/
/*!
   Máximo para \e arrays.
*/
#define MAX 1000
/*!< */


/** A função principal deste programa coloca no \e stdout um conjunto de opções
 * para testar de uma forma mais rápida as funções implementadas em "cadeias.c"
*/
int main()
{   char s1 [MAX];
    char s2 [MAX];
    int n, x;
    char c;
    printf ( "          ** Opções disponíveis **         \n" );
    printf ( "1 cad_tamanho		7 cad_iguais     \n" );
    printf ( "2 cad_procurar_car        8 cad_primeiro   \n" );
    printf ( "3 cad_ocorrencias	        9 cad_comparar   \n" );
    printf ( "4 cad_procurar_str        10 cad_um_dos    \n" );
    printf ( "5 cad_e_prefixo           11 cad_nenhum_dos\n" );
    printf ( "6 cad_e_sufixo            12 cad_copiar    \n" );
    printf ( "7 cad_iguais              13 cad_colar     \n" );
    printf ( "8 cad_primeiro            14 cad_mover     \n" );
    printf ( "Introduza uma opção: " );
    n = scanf ( "%d", &x );

    if ( n == 1 )
        printf ( "Opção selecionada com sucesso!\n" );

    switch ( x )
    {   case 1:
            tamanho ( s1 );
            break;
        case 2:
            c = getchar();
            procurar_car ( c, s1 );
            break;
        case 3:
            c = getchar();
            ocorrencias ( c, s1 );
            break;
        case 4:
            procurar_str ( s1, s2 );
            break;
        case 5:
            e_prefixo ( s1, s2 );
            break;
        case 6:
            e_sufixo ( s1, s2 );
            break;
        case 7:
            iguais ( s1, s2 );
            break;
        case 8:
            primeiro ( s1, s2 );
            break;
        case 9:
            comparar ( s1, s2 );
            break;
        case 10:
            um_dos ( s1, s2 );
            break;
        case 11:
            nenhum_dos ( s1, s2 );
            break;
        case 12:
            copiar ( s1, s2 );
            break;
        case 13:
            colar ( s1, s2 );
            break;
        case 14:
            mover ( s1, s2 );
            break;
    }

    return 0;
}
