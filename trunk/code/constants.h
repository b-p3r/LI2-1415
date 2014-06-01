

/*!
  \def MAXSTR 25

*/
/*!
   Valor máximo para as \e strings deste módulo (máximo de colunas para a matriz sopa de letras).
*/
#define MAXSTR 25



/*!
  \def MAX 2500

*/
/*!
   Máximo para \e arrays, colunas e linhas de matrizes.
*/
#define MAX 2500
/*!< */

/*!
   Valor máximo para \e arrays auxiliares.
*/
#define MAX_TEMP 8
/*!< */





/*!
  \def ALFABETO 26

*/
/*!
   Valor para o tamanho do \e array de apontadores da \e struct \c t_nodo, correspondente ao tamanho do alfabeto.
*/
#define ALFABETO 26
/*!< */


/*!
  \def MODO_LEITURA "r"

*/
/*!
   Constante utilizada para definir o modo de acesso a um determinado ficheiro (neste caso só leitura).
*/
#define MODO_LEITURA "r"
/*!< */


/*!
  \def OFFSET_CHAR_UPPER 'A'

*/
/*!
   Valor para o cálculo do índice da struct \ref t_nodo, em caso de letras maiúsculas.
*/
#define OFFSET_CHAR_UPPER 'A'
/*!< */

/*!
  \def OFFSET_CHAR_LOWER 'a';

*/
/*!
   Valor para o cálculo do índice da struct \ref t_nodo, em caso de letras minúsculas.
*/
#define OFFSET_CHAR_LOWER 'a'
/*!< */




/*!
  \def DICIONARIO "./dicio.txt"

*/
/*!
   Constante para que define localização e ficheiro a ser utilizado neste projeto (com a exceção da tarefa 4).
*/
#define DICIONARIO "./dicio.txt"
/*!< */

/*!
  \def SERPENTE "serpente"

*/
/*!
   Valor para comparação de movimento introduzido, correspondente ao movimento de serpente.
*/
#define SERPENTE "serpente"
/*!< */

/*!
  \def CAVALO "cavalo"

*/
/*!
    Valor para comparação de movimento introduzido, correspondente ao movimento de passo de cavalo.
*/
#define CAVALO "cavalo"
/*!< */

/*!
  \def MOV_SERP 1

*/
/*!
   Constante para definir escolha para movimento de serpente.
*/
#define MOV_SERP 1
/*!< */


/*!
  \def MOV_CAV 2

*/
/*!
   Constante para definir escolha para movimento de passo de cavalo.
*/
#define MOV_CAV 2
/*!< */



/**
 * \defgroup PCS Pontos Cardeiais Segmentados
 * @{
* @brief Pontos cardeais segmentados a parti de uma posição central.
 *
 * Cada ponto cardeal principal (N, S, W, E) foi segmentados em dois, a partir de uma posição central
 * para corresponder ao passo de cavalo. Por exemplo, o Norte foi dividido em dois: esquerdo e direito.
 */


/** Norte Esquerdo */
#define N1 1
/** Norte Direito */
#define N2 5

/** Oeste Esquerdo */
#define W1 3
/** Oeste Direito */
#define W2 7

/** Este Esquerdo */
#define E1 4
/** Este Direito */
#define E2 8

/** Sul Esquerdo */
#define S1 2
/** Sul Direito */
#define S2 6


/*@}*/


/**
 * \defgroup PC Pontos Cardeais
 * @{


**
 * @brief Pontos cardeiais para representar o movimento de serpente.
 *
 *
 */


/** Norte */
#define N 1
/** Nordeste */
#define NE 2
/** Noroeste */
#define NW 3
/** Oeste */
#define W 4
/** Este */
#define E 5
/** Sudoeste */
#define SW 6
/** Sudeste */
#define SE 7
/** Sul */
#define S 8
/*@}*/




