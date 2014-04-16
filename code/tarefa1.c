#include <stdio.h>
#include "cadeias.h"

void tamanho ( char s [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s);
    if(n == 0)
        return;

    printf ("%d\n", cad_tamanho(s));

}
void procurar_car (char c, char s [])
{
    int n;
    printf("Introduza uma caractere: ");
    n = scanf ("%c", &c);
    if(n == 0)
        return;
    printf("Introduza uma string: ");

    n = scanf ("%s", s);
    if(n == 0)
        return;

    printf ("%d\n", cad_procurar_car(c, s));
}
void ocorrencias (char c, char s [])
{
    int n;

    printf("Introduza um caractere: ");
    n = scanf ("%c", &c);
    if(n == 0)
        return;
    printf("Introduza uma string: ");
    n = scanf ("%s", s);
    if(n == 0) return;


    printf ("%d\n", cad_ocorrencias(c, s));
}
void procurar_str ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_procurar_str(s1, s2));
}
void e_prefixo ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_e_prefixo(s1, s2));
}
void e_sufixo ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_e_sufixo(s1, s2));
}
void iguais ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_iguais(s1, s2));
}
void primeiro ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_primeiro(s1, s2));
}
void comparar ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_comparar(s1, s2));
}
void um_dos ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_um_dos(s1, s2));
}
void nenhum_dos ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    printf ("%d\n", cad_nenhum_dos(s1, s2));
}
void copiar ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;


    cad_copiar(s1,s2);

    printf("%s", s2);

}
void colar ( char s1 [] , char s2 [])
{
    int n;
    printf("Introduza uma string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;
    printf("Introduza outra string: ");
    n = scanf ("%s", s1);
    if(n == 0) return;

    cad_colar(s1, s2);


    printf("%s", s1);

}
void mover ( char m1 [] , char m2 [])
{
    int n, d;
    printf("Introduza uma string: ");
   
    n = scanf ("%d", &d);
    if(n == 0) return;
    n = scanf ("%s", m1);
    if(n == 0) return;
    n = scanf ("%s", m2);
    if(n == 0) return;
    cad_mover(m1, m2, d);

    printf("%s", m1);

}

