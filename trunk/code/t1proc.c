# include <stdio.h>
# include "cadeias.h"

/*! O procedimento \e tamanho lê do \e stdin uma \e string e aplica a função \e cad_tamanho.
@param s Apontador para escrita da \e string na memória.
@return O nº de leituras do \e stdin com sucesso.
*/
int tamanho ( char s [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s );

    printf ( "%d\n", cad_tamanho ( s ) );
    return n;
}
/**
O procedimento \e procurar_car lê do \e stdin uma \e string e um caractere e aplica a função \e cad_procurar_car.
@param s Apontador para escrita da \e string na memória.
@param c Caractere para ser utilizado na função cad_procurar_car.
@return O nº de leituras do \e stdin com sucesso.
*/
int procurar_car ( char c, char s [] )
{
    int n;
    printf ( "Introduza uma caractere: " );
    n = scanf ( "%c", &c );

    printf ( "Introduza uma string: " );
    n += scanf ( "%s", s );


    printf ( "%d\n", cad_procurar_car ( c, s ) );
    return n;
}
/**
O procedimento \e ocorrencias lê do \e stdin uma \e string e um caractere e aplica a função \e cad_ocorrencias.
@param s Apontador para escrita da \e string na memória.
@param c Caractere para ser utilizado na função cad_ocorrencias.
@return O nº de leituras do \e stdin com sucesso.
*/
int ocorrencias ( char c, char s [] )
{
    int n;
    printf ( "Introduza uma caractere: " );
    n = scanf ( "%c", &c );
    printf ( "Introduza uma string: " );
    n += scanf ( "%s", s );


    printf ( "%d\n", cad_ocorrencias ( c, s ) );
    return n;
}
/**
O procedimento \e procurar_str lê do \e stdin duas \e string e aplica a função \e cad_procurar_str.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int procurar_str ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_procurar_str ( s1, s2 ) );
    return n;
}

/**
O procedimento \e e_prefixo lê do \e stdin duas \e strings e aplica a função \e cad_e_prefixo.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int e_prefixo ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_e_prefixo ( s1, s2 ) );
    return n;
}

/**
O procedimento \e e_sufixo lê do \e stdin duas \e strings e aplica a função \e cad_e_sufixo.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int e_sufixo ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_e_sufixo ( s1, s2 ) );
    return n;
}

/**
O procedimento \e iguais lê do \e stdin duas \e string e aplica a função \e cad_iguais.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/
int iguais ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_iguais ( s1, s2 ) );
    return n;
}

/**
O procedimento \e primeiro lê do \e stdin duas \e string e aplica a função \e cad_primeiro.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int primeiro ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_primeiro ( s1, s2 ) );
    return n;
}
/**
O procedimento \e comparar lê do \e stdin duas \e strings e aplica a função \e cad_comparar.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int comparar ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_comparar ( s1, s2 ) );
    return n;
}
/**
O procedimento \e um_dos lê do \e stdin duas \e strings e aplica a função \e cad_um_dos.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int um_dos ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_um_dos ( s1, s2 ) );
    return n;
}
/**
O procedimento \e nenhum_dos lê do \e stdin duas \e strings e aplica a função \e cad_nenhum_dos.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int nenhum_dos ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );


    printf ( "%d\n", cad_nenhum_dos ( s1, s2 ) );
    return n;
}

/**
O procedimento \e copiar lê do \e stdin uma \e string e aplica a função \e cad_copiar.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int copiar ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );

    cad_copiar ( s1, s2 );

    printf ( "'%s'", s2 );
    return n;

}
/**
O procedimento \e colar lê do \e stdin duas \e strings e aplica a função \e cad_colar.
@param s1 Apontador para escrita da \e string s1 na memória.
@param s2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int colar ( char s1 [] , char s2 [] )
{
    int n;
    printf ( "Introduza uma string: " );
    n = scanf ( "%s", s1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", s2 );

    cad_colar ( s1, s2 );


    printf ( "%s", s1 );
    return n;

}

/**
O procedimento \e mover lê do \e stdin duas \e strings e aplica a função \e cad_mover.
@param m1 Apontador para escrita da \e string s1 na memória.
@param m2 Apontador para escrita da \e string s2 na memória.
@return O nº de leituras do \e stdin com sucesso.
*/

int mover ( char m1 [] , char m2 [] )
{
    int n;
    int d;
    printf ( "Introduza uma string: " );

    printf ( "Introduza outra nro de bytes: " );
    n = scanf ( "%d", &d );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", m1 );
    printf ( "Introduza outra string: " );
    n += scanf ( "%s", m2 );
    cad_mover ( m1, m2, d );

    printf ( "%s", m1 );
    return n;

}
