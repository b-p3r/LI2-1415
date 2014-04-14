#include <stdio.h>


/*TODO:

* testar funções (algumas funções têm erros);
* Comentar funções com sintaxe do Doxygen
* Refactoring do código (possível discussão sobre legibilidade e eficiência)*/


/**
 * Esta função calcula o tamanho de uma string dada
 *
 * @return o tamanho da string
 * @param char s [] A string dada.
 * */
int cad_tamanho ( char s [])
{
    int i=0;
    while(s[i]) i++;
    return i;
}

/**
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return o indíce onde se encontra o caractere, -1 caso o caractere não se encontre na string
 * @param char c O caractere a procurar
 * @param char s [] A string onde o caractere será procurado
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

 * @return número de ocorrências do caractere, 0 caso o caracter não se encontrar na string
 * @param char c O caractere a procurar
 * @param char s [] A string onde onde as ocorrências do caractere serão contadas.
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

/*TODO int cad_procurar_str ( char s1 [] , char s2 []);*/

int cad_procurar_str ( char s1 [] , char s2 [])
{

    int i, x;


    for (i =0; s2[i] ; i++);

    for(x = 0; s2 [i] == s1 [i+x] ; x++);

    /*if(s1 [i] != s2 [j+x])*/
    /*enc = 0;*/



    /*if(enc)*/
    return i;
    /*else*/
    /*    return -1;*/
}



/**
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
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
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
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
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
 * */
int cad_primeiro ( char s1 [] , char s2 [])
{

    int size1, size2, e_menor = 0;

    size1 = cad_tamanho (s1);
    size2 = cad_tamanho (s2);

    int i = 0;


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
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
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
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
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
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
 * */
void cad_copiar ( char s1 [] , char s2 [])
{

    int i;

    for ( i = 0; s1[i]; i++)
        s2[i]=s1[i];
    s2[i]='\0';

}
/**
 * Esta função verifica se o segundo argumento contém o primeiro.
 * Por exemplo, verifica se "banana" contém "ana"
 * @return 1 se maior contém pequena, 0 caso contrário
 * @param maior A string maior
 * @param pequena A string mais pequena
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

/* procura um carater numa string e devolve: -1 se não encontrou a posição do carater na string calcular tamanho de uma string*/
void cad_mover ( char m1 [] , char m2 [] , int n )
{
    int i;


    for (i = 0; i < n ; i++)
        m1 [i] = m2 [i];


}
