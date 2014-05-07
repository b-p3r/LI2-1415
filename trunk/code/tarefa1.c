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

/*! \mainpage Projeto de Laboratórios de Informática II 2013/2014
 * O projeto de LI2 consiste em criar uma aplicação na linguagem de programação \e c,
 * que resolva um puzzle do tipo \e Sopa \e de \e Letras. O projeto foi dividido em duas
 * etapas, cada uma com uma série de tarefas a realizar. Cada tarefa é um pequeno
 * passo para a construção do puzzle.
 *
 * \section sec_1 Etapa 1
 * Esta etapa consistiu na realização de de duas tarefas. A
 * Tarefa 1 (implementação de funções de manipulação de  \e strings)
 * e a Tarefa 2 (implementação de um programa de leitura de uma
 *  \e string numa matriz).
 *
 * \subsection subsec_1 Tarefa 1 - Funções de manipulação de strings
 * As funções de manipulações de \e strings implementadas
 * são um versão alternativa das funções já existentes
 * na biblioteca padrão do C. O âmbito das funções é
 * entender o processo da sua análise e conceção, i. e.
 * perceber o que estas funções fazem, para as utilizar
 * com maior eficiência, em particular. De um modo geral servem
 * como preparação para as restantes tarefas do projeto.
 *
 * \subsection subsec_2 Tarefa 2
 *
 * O programa desta tarefa consiste em descobrir
 * uma \e string, dado um conjunto de coordenadas, numa matriz
 * que representa uma sopa de letras. O âmbito deste programa
 * é o entendimento das operações com matrizes, e de igual modo,
 * as funções de manipulação de \e strings servem como preparação
 * para as restantes tarefas do projeto.
 *
 */


/** A função principal deste programa coloca no \e stdout um conjunto de opções
 * para testar de uma forma mais rápida as funções implementadas em "cadeias.c"
*/
int main()
{
    char s1 [MAX];
    char s2 [MAX];
    int n, x;
    char c;

    printf("	** Opções disponíveis **         \n");
    printf("1 cad_tamanho		7 cad_iguais     \n");
    printf("2 cad_procurar_car		8 cad_primeiro   \n");
    printf("3 cad_ocorrencias		9 cad_comparar   \n");
    printf("4 cad_procurar_str		10 cad_um_dos    \n");
    printf("5 cad_e_prefixo		11 cad_nenhum_dos\n");
    printf("6 cad_e_sufixo		12 cad_copiar    \n");
    printf("7 cad_iguais		13 cad_colar     \n");
    printf("8 cad_primeiro 		14 cad_mover     \n");


    printf("Introduza uma opção: ");
    n = scanf("%d",&x);
    if(n == 1)
        printf("Opção selecionada com sucesso!\n");
    switch(x) {


    case 1:
        tamanho(s1);
        break;
    case 2:
        c = getchar();
        procurar_car(c, s1);
        break;
    case 3:
        c = getchar();
        ocorrencias(c, s1);
        break;
    case 4:
        procurar_str(s1, s2);
        break;

    case 5:
        e_prefixo(s1, s2);
        break;
    case 6:
        e_sufixo(s1, s2);
        break;
    case 7:
        iguais(s1, s2);
        break;
    case 8:
        primeiro(s1, s2);
        break;
    case 9:
        comparar(s1, s2);
        break;
    case 10:
        um_dos(s1, s2);
        break;
    case 11:
        nenhum_dos(s1, s2);
        break;
    case 12:
        copiar(s1, s2);
        break;
    case 13:
        colar(s1, s2);
        break;
    case 14:
        mover(s1, s2);
        break;

    }

    return 0;
}
