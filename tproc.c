# include <stdio.h>
# include "cadeias.h"


void tamanho ( char s [])
{
    scanf ("%s", s);


    printf ("%d\n", cad_tamanho(s));

}
void procurar_car (char c, char s [])
{
    
    /*scanf ("%c", &c);*/
	/*c = getchar();*/

    scanf ("%s", s);


    printf ("%d\n", cad_procurar_car(c, s));
}
void ocorrencias (char c, char s [])
{
    
     /*c = getchar();*/
    scanf ("%s", s);


    printf ("%d\n", cad_ocorrencias(c, s));
}
void procurar_str ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_procurar_str(s1, s2));
}
void e_prefixo ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_e_prefixo(s1, s2));
}
void e_sufixo ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_e_sufixo(s1, s2));
}
void iguais ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_iguais(s1, s2));
}
void primeiro ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_primeiro(s1, s2));
}
void comparar ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_comparar(s1, s2));
}
void um_dos ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_um_dos(s1, s2));
}
void nenhum_dos ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_nenhum_dos(s1, s2));
}
void copiar ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);

    cad_copiar(s1,s2);

    printf("%s", s2);

}
void colar ( char s1 [] , char s2 [])
{
    scanf ("%s", s1);
    scanf ("%s", s2);

    cad_colar(s1, s2);


    printf("%s", s1);

}
void mover ( char m1 [] , char m2 [])
{
    int d;
    scanf ("%d", &d);
    scanf ("%s", m1);
        scanf ("%s", m2);
    cad_mover(m1, m2, d);

    printf("%s", m1);

}

int main()
{
    char s1 [1000];
    char s2 [1000];
    int n, x;
    char c;
    printf("Introduza uma opção: ");
    scanf("%d",&x);

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
