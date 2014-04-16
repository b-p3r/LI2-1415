#include <stdio.h>

/*! \mainpage Projeto de Laboratórios de Informática II 2013/2014
 * O projeto de LI2 consiste em criar uma aplicação na linguagem de programação c
 * que resolva um puzzle chamado Sopa de Letras. O projeto foi dividido em duas
 * etapas, cada uma com uma série de tarefas a realizar. Cada tarefa é um pequeno
 * passo para a construção do puzzle.
 *
 * \section sec_1 Etapa 1
 * Esta etapa consistiu na realização de de duas tarefas. A
 * Tarefa 1 ( implementação de funções de manipulação de strings)
 * e a Tarefa 2 ( implementação de um programa de leitura de uma
 * string numa matriz.
 *
 * \subsection subsec_ 1 Tarefa 1 - Funções de manipulação de strings
 * As funções de manipulações de strings implementadas
 * são um versão alternativa das funções já existentes
 * na biblioteca padrão do C. O âmbito das funções é
 * entender o processo da sua análise e conceção, i. e.
 * perceber o que estas funções fazem, para as utilizar
 * com maior eficiência, em particular,  e de modo geral
 * como preparação para as restantes tarefas do projeto.
 *
 * \subsection subsec_2 Tarefa 2
 *
 * O programa desta tarefa consiste em descobrir
 * uma string, dado um conjunto de coordenadas, numa matriz
 * que representa uma sopa de letras. O âmbito deste programa
 * é o entendimento das operações com matrizes, e, de igual
 * as funções de manipulação de strings serve como preparação
 * para as restantes tarefas do projeto.
 *
 */



/**
 * Esta função calcula o tamanho de uma string dada
 * @param  s A string dada.
 * @return o tamanho da string
 * */
int cad_tamanho ( char s [])
{
    int i=0;
    while(s[i]) i++;
    return i;
}

/**
 * Esta função procura um caractere numa \e string e devolve o índice da sua ocorrência.
 * Por exemplo, procura o caratere 'c' em "disco" de devolve 3.
 * @param c O caractere a procurar.
 * @param s A string onde o caractere será procurado.
 * @return o indíce onde se encontra o caractere, -1 caso o caractere não se encontre na \e string.
 * */
int cad_procurar_car ( char c , char s [])
{
    int i, existe=0;
    for(i = 0; s[i]; i++)
        if (s[i]==c) {
            existe=1;
            break;
        }

    if (existe) return i;
    else return -1;
}


/**
 * Esta função conta o número de ocorrências de um caractere numa string
 * Por exemplo, conta as ocorrências de 'a' em "anagrama" e devolve o nº de ocorrências.
 * @return número de ocorrências do caractere, 0 caso não houver ocorrências do caractere na string.
 * @param c O caractere a procurar.
 * @param s A string onde onde as ocorrências do caractere serão contadas.
 * @return número de ocorrências do caractere, 0 caso não houver ocorrências do caractere na string.
 * */
int cad_ocorrencias ( char c , char s [])
{
    int i, cont;
    i = cont=0;
    while(s[i]) {
        if (s[i]==c) cont++;
        i++;
    }
    return cont;
}

/**
 * Esta função procura o primeiro índice em que uma string s1 se encontra dentro de outra string s2.
 * Por exemplo, procura "tal" em "mentalmente"
 * @return número de ocorrências do caractere, 0 caso não houver ocorrências do caractere na string.
 * @param c O caractere a procurar.
 * @param s A string onde onde as ocorrências do caractere serão contadas.
 * @return número de ocorrências do caractere, 0 caso não houver ocorrências do caractere na string.
 * */
int cad_procurar_str ( char s1 [] , char s2 [])
{
    int i, j;
   for (i =0; s2[i]; i++) {
       for(j = 0; s2[j]&&(s2 [j+i] == s1 [j]) ; j++);
       if(s1 [j]=='\0')
           return i;
   }
   return -1;

}
/**
 * Esta função verifica se o primeiro argumento é prefixo do segundo.
 * Por exemplo, verifica se "pro" é prefixo de "prototipo"
 * @param s1 A string a verificar se é prefixo da segunda
 * @param s2 A string a ser verificada.
 * @return 1 se s1 é prefixo de s2, 0 caso contrário.
 * */
int cad_e_prefixo ( char s1 [] , char s2 [])
{

    int i , e_pref;

    for(i=0, e_pref = 1; s1[i]&&e_pref; i++) {
        if(s1[i]!= s2[i]) e_pref = 0;


    }
    return e_pref;

}

/**
 * Esta função verifica se o primeiro argumento é sufixo do segundo.
 * Por exemplo, verifica se "mente" é sufixo de "mentalmente"
 * @param s1 A string a verificar se é sufixo da segunda
 * @param s2 A string a ser verificada.
 * @return 1 se s1 é sufixo de s2, 0 caso contrário.
 * */
int cad_e_sufixo ( char s1 [] , char s2 [])
{

    int i, j, e_suf = 1;


    i = cad_tamanho (s1) - 1;
    j = cad_tamanho (s2) - 1;



    while(i>=0&&j>=0&&e_suf) {

        if (s1[i]!=s2[j])
            e_suf = 0;

        i--;
        j--;

    }

    return e_suf&&i==-1;
}


/**
 * Esta função verifica se uma string é igual uma segunda string.
 * Por exemplo, verifica se "computador" é igual a "computador" e retorna 1.
 * @param s1 A 1ª string a comparar.
 * @param s2 A 2ª string a comparar.
 * @return 1 se s1 é igual a s2, 0 caso contrário.
 * */
int cad_iguais ( char s1 [] , char s2 [])
{

    int i, igual = 1;
    int size1 = cad_tamanho (s1);
    int size2 = cad_tamanho (s2);
    if(size1==size2) {
        for(i = 0; s1[i]&&s2[i]&&igual; i++)
            if(s1[i]!=s2[i])
                igual = 0;
    } else
        igual = 0;
    return igual;
}
/**
 * Esta função verifica se o primeiro argumento é menor que o segundo
 * segundo a ordem lexicográfica.
 * Por exemplo, "Joana" é menor que "Pedro", uma vez que Joana aparece primeiro no dicionário.
 * @param s1 A 1ª string a comparar.
 * @param s2 2ª string a comparar.
 * @return 1 se s1 é menor que s2, 0 caso contrário.
 * */
int cad_primeiro ( char s1 [] , char s2 [])
{

    int size1, size2, i = 0;

    size1 = cad_tamanho (s1);
    size2 = cad_tamanho (s2);

    while(s1[i]&&s2[i]) {

        if(s1 [i] == s2 [i]) {
            i++;
            continue;
        } else if(s1 [i] < s2 [i])
            return 1;
        else
            return 0;
    }

    if (size1 < size2)
        return 1;
    else
        return 0;
}



/**
 * Esta função verifica se o primeiro argumento é menor, maior ou igual ao segundo
 * segundo a ordem lexicográfica.
 * Por exemplo, verifica se "Joana" é menor, maior ou igual que "Pedro" (neste cado retorna -1)
 * Um outro exemplo: verifica se "Ana" é menor,maior, ou igual a "Joana" (neste caso retorna 1)
 * @param s1 A 1ª string a comparar.
 * @param s2 2ª string a comparar.
 * @return -1 se s1 é menor que s2, 0 se s1 é igual a s2, ou 1 se se s1 é maior que s2.
 * */
int cad_comparar ( char s1 [] , char s2 [])
{

    int i = 0;
    int size1 = cad_tamanho(s1);
    int size2 = cad_tamanho(s2);
    while(s1[i]&&s2[i]) {

        if(s1 [i] == s2 [i]) {
            i++;
            continue;
        }
        if(s1 [i] < s2 [i])
            return -1;
        if(s1 [i] > s2 [i])
            return 1;
    }
    if(size1 > size2)
        return 1;
    else if (size1 < size2)
        return -1;
    else
        return 0;
}



/**
 * Esta função procura o 1º índice de uma string (1º argumento) que contém um dos caracteres de uma segunda string (2º argumento)
 * Por exemplo, procura os caracteres de "rato" em "mar" (devolve 1 neste caso)
 * Um outro exemplo: procura os caracteres de "calar" em "tubo" (devolve -1 neste caso)
 * @param s1 A 1ª string de origem para procura.
 * @param s2 2ª string de destino para procura.
 * @return -1 se s2 não contém nenhum caractere em s1, ou o índíce da 1ª ocorrência de s1 em s2
 * */
int cad_um_dos ( char s1 [] , char s2 [])
{
    int i , j, index, enc = 0;

    for(i = 0; !enc&&s1[i]; i++) {
        for(j =0; !enc&&s2[j]; j++)
            if(s1[i]==s2[j]) {
                enc = 1;
                index = i;

            }
    }

    if(enc)
        return index;
    else
        return -1;
}
/**
 * Esta função procura o 1º índice de uma string (1º argumento) que não contém um dos caracteres de uma segunda string (2º argumento)
 * Por exemplo, procura os caracteres de "lago" em "lata" (devolve 2 neste caso)
 * Um outro exemplo: procura os caracteres de "tarte" em "tarte" (devolve -1 neste caso)
 * @param s1 A 1ª string de origem para procura.
 * @param s2 2ª string de destino para procura.
 * @return -1 se s2 contém todos os carcteres de s1, ou o índíce da 1ª ocorrência de s1 em que não contém um caractere de s2
 * */
int cad_nenhum_dos ( char s1 [] , char s2 [])
{


    int i , enc = 0;

    for(i=0; s1[i]==s2[i]&&s1[i]&&s2[i]; i++);

    if(s1[i]!=s2[i])
        enc = 1;


    if(enc)
        return i;
    else
        return -1;
}

/**
 * Esta função copia o primeiro argumento para o segundo argumento;
 *
 * @param s1 A string de origem (a ser copiada).
 * @param s2 A string de destino
 * */
void cad_copiar ( char s1 [] , char s2 [])
{

    int i;

    for ( i = 0; s1[i]; i++)
        s2[i]=s1[i];
    s2[i]='\0';

}
/**
 * Esta função concatena a string, que está como segundo argumento, com
 * a string que está como primeiro argumento.
 * Por exemplo, concatena "mente" com "mentalmente", originado uma nova string "mentalmente"
 * @param s1 A string que recebe uma outra string a colar.
 * @param s2 A string a colar.
 * */
void cad_colar ( char s1 [] , char s2 [])
{


    int size1 = cad_tamanho (s1);
    int n = cad_tamanho (s2) + size1;
    int i, j;

    for(i = size1, j = 0; i < n  ; i++, j++)
        s1[i] = s2 [j];
    s2[i]='\0';
}
/**
 * Esta função move \e n \e bytes da área m2 para a área m1.
 * Os parâmetros estão representados como strings onde cada \e byte corresponde a um caractere.
 * Por exemplo, mover 5 \e bytes de "Braga" para "Portugal" ( resultado "Bragagal")
 * @param m1 A área da memória de destino da cópia.
 * @param m2 A área de origem da memória para a cópia.
 * @param n O número de \e bytes a mover.
 * */
void cad_mover ( char m1 [] , char m2 [] , int n )
{
    int i;

    for (i = 0; i < n ; i++)
        m1 [i] = m2 [i];


}
