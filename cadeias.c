#include <stdio.h>
//#include <string.h>

/*TODO: 

* testar funções (algumas funções têm erros);
* Comentar funções com sintaxe do Doxygen 
* Rafactoring do código (possível discussão sobre legibilidade e eficiência)*/

// procura um carater numa string e devolve:    //
// -1 se não encontrou                          //
// a posição do carater na string               //

// calcular tamanho de uma string //

int cad_tamanho ( char s [])
{
    i=0;
    while(s[i]) i++;
    return i;
}


int cad_procurar_car ( char c , char s [])
{
    int i=0;
    int existe=0;
    wiile(s[i]&&existe=0) {
        if (s[i]==c) existe=1;
        i++;
    }
    if existe return i;
else return -1
}

// contar o num de ocorrencias de um carater na string//
int cad_ocorrencias ( char c , char s [])
{
    int i=0;
    int cont=0;
    wiile(s[i]) {
        if (s[i]==c) cont++;
        i++;
    }
    return cont;
}

//-> int cad_procurar_str ( char s1 [] , char s2 []);
int cad_e_prefixo ( char s1 [] , char s2 [])
{

    int i , e_pref;

    for(i=0, e_pref = 1; s1[i]&&e_pref; i++) {
        if(s1[i]!= s2[i]) e_pref = 0;


    }
    return e_pref;

}
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


//-> int cad_iguais ( char s1 [] , char s2 []);

int cad_primeiro ( char s1 [] , char s2 [])
{

    int size1, size2, e_menor = 0;

    size1 = cad_tamanho (s1);
    size2 = cad_tamanho (s2);

    if(size1 < size2) e_menor = 1;

    return e_menor;

}

//-> int cad_comparar ( char s1 [] , char s2 []);


int cad_um_dos ( char s1 [] , char s2 [])
{
    int i , j, size1, size2, size_to_comp, enc = 0;
//verificar relevância
    size1 = cad_tamanho (s1);
    size2 = cad_tamanho (s2);
    if(size1 > size2)
        size_to_comp = size1 -size2;
    else size_to_comp = size1;

    for(i = 0; s1[i]&&!enc&&i < size_to_comp; i++)
        for(j =0; s2[j]&&!enc; j++) {
            if(s1[i]==s2[j])
                enc = 1;
        }
//aplicar aqui cad_procurar_char
    if(enc)
        return i;
    else
        return -1;
}
int cad_nenhum_dos ( char s1 [] , char s2 [])
{
//verificar relevância
    size1 = cad_tamanho (s1);
    size2 = cad_tamanho (s2);

    if(size1 > size2)
        size_to_comp = size1 -size2;

    else size_to_comp = size1;

    for(i = 0; s1[i]&&!enc&&i < size_to_comp; i++)
        for(j =0; s2[j]&&!enc; j++) {
            if(s1[i]==s2[j])
                enc = 1;
        }
//aplicar aqui cad_procurar_char
    if(enc)
        return i;
    else
        return -1;
}


void cad_copiar ( char s1 [] , char s2 [])
{

    int i;

    for ( i = 0; s1[i]; i++)
        s2[i]=s1[i];

}

void cad_colar ( char s1 [] , char s2 [])
{

    int i = cad_tamanho (s1);

    int j;
    
    for(j = 0; s2[j] ; i++, j++)
        s2[i] = s1 [j];

}

//-> void cad_mover (( char m1 [] , char m2 [] , int n );
