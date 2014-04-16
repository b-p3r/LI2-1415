

/**
 * Esta função calcula o tamanho de uma  \e string dada
 * @param  s A  \e string dada.
 * @return O tamanho da  \e string.
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
 * @param s A  \e string onde o caractere será procurado.
 * @return O índice onde se encontra o caractere, -1 caso o caractere não se encontre na \e string.
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
 * Esta função conta o número de ocorrências de um caractere numa  \e string
 * Por exemplo, conta as ocorrências de 'a' em "anagrama" e devolve o nº de ocorrências.
 * @return número de ocorrências do caractere, 0 caso não houver ocorrências do caractere na  \e string.
 * @param c O caractere a procurar.
 * @param s A  \e string onde onde as ocorrências do caractere serão contadas.
 * @return O número de ocorrências do caractere, 0 caso não houver ocorrências do caractere na  \e string.
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
 * Esta função procura o primeiro índice em que uma  \e string  \e s1 se encontra dentro de outra  \e string  \e s2.
 * Por exemplo, procura "tal" em "mentalmente" e devolve 3.
 
 * @param s1 A \e string a verificar na segunda \e string.
 * @param s2 A  \e string de destino, onde se irá verificar se \e s1 se encontra dentro.
 * @return O número do primeiro índice de  \e s2 onde se encontre um caractere de  \e s1, -1 caso não houver ocorrências de caracteres da \e string.
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
 * Esta função verifica se o primeiro argumento é prefixo do segundo argumento.
 * Por exemplo, verifica se "pro" é prefixo de "prototipo"
 * @param s1 A  \e string a verificar se é prefixo da segunda
 * @param s2 A  \e string a ser verificada.
 * @return 1 ,se  \e s1 é prefixo de  \e s2, 0 caso contrário.
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
 * @param s1 A  \e string a verificar se é sufixo da segunda
 * @param s2 A  \e string a ser verificada.
 * @return 1, se  \e s1 é sufixo de  \e s2, 0 caso contrário.
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
 * Esta função verifica se uma  \e string é igual uma segunda  \e string.
 * Por exemplo, verifica se "computador" é igual a "computador" e retorna 1.
 * @param s1 A 1ª  \e string a comparar.
 * @param s2 A 2ª  \e string a comparar.
 * @return 1, se  \e s1 é igual a  \e s2, 0 caso contrário.
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
 * Esta função verifica se o primeiro argumento é menor que o segundo argumento,
 * segundo a ordem lexicográfica.
 * Por exemplo, "Joana" é menor que "Pedro", uma vez que Joana aparece primeiro no dicionário.
 * @param s1 A 1ª  \e string a comparar.
 * @param s2 A 2ª  \e string a comparar.
 * @return 1, se  \e s1 é menor que  \e s2, 0 caso contrário.
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
 * Esta função verifica se o primeiro argumento é menor, maior ou igual ao segundo argumento,
 * segundo a ordem lexicográfica.
 * Por exemplo, verifica se "Joana" é menor, maior ou igual que "Pedro" (neste cado retorna -1).
 * Um outro exemplo: verifica se "Ana" é menor,maior, ou igual a "Joana" (neste caso retorna 1).
 * @param s1 A 1ª  \e string a comparar.
 * @param s2 A 2ª  \e string a comparar.
 * @return -1, se  \e s1 é menor que  \e s2, 0 se  \e s1 é igual a  \e s2, ou 1 se se  \e s1 é maior que  \e s2.
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
 * Esta função procura o 1º índice de uma  \e string (1º argumento) que contém um dos caracteres de uma segunda  \e string (2º argumento).
 * Por exemplo, procura os caracteres de "rato" em "mar" (devolve 1 neste caso).
 * Um outro exemplo: procura os caracteres de "calar" em "tubo" (devolve -1 neste caso).
 * @param s1 A 1ª  \e string de origem para procura.
 * @param s2 A 2ª  \e string de destino para procura.
 * @return -1, se  \e s2 não contém nenhum caractere em  \e s1, ou o índíce da 1ª ocorrência de  \e s1 em  \e s2.
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
 * Esta função procura o 1º índice de uma  \e string (1º argumento) que não contém um dos caracteres de uma segunda  \e string (2º argumento).
 * Por exemplo, procura os caracteres de "lago" em "lata" (devolve 2 neste caso).
 * Um outro exemplo: procura os caracteres de "tarte" em "tarte" (devolve -1 neste caso).
 * @param s1 A 1ª  \e string de origem para procura.
 * @param s2 2ª  \e string de destino para procura.
 * @return -1, se  \e s2 contém todos os carcteres de  \e s1, ou o índíce da 1ª ocorrência de  \e s1 em que não contém um caractere de  \e s2.
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
 * Esta função copia o primeiro argumento para o segundo argumento.
 *
 * @param s1 A  \e string de origem (a ser copiada).
 * @param s2 A  \e string de destino.
 * */
void cad_copiar ( char s1 [] , char s2 [])
{

    int i;

    for ( i = 0; s1[i]; i++)
        s2[i]=s1[i];
    s2[i]='\0';

}
/**
 * Esta função concatena a  \e string, que está como segundo argumento, com
 * a  \e string que está como primeiro argumento.
 * Por exemplo, concatena "mente" com "mentalmente", originado uma nova  \e string "mentalmente"
 * @param s1 A  \e string que recebe uma outra  \e string a colar.
 * @param s2 A  \e string a colar.
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
 * Os parâmetros estão representados como  \e strings onde cada \e byte corresponde a um caractere.
 * Por exemplo, mover 5 \e bytes de "Braga" para "Portugal" ( resultado "Bragagal").
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
