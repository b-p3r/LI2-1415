#include <ctype.h>

void limpar_array ( char str[] )
{
    int i;
    for ( i = 0; str[i]; i++ ) {
        str [i] = '\0';

        i++;
    }

}

int append_char2str ( char pal [], char a,  int i )
{

    pal[i] = a;
    pal[i + 1] = '\0';
    i++;
    return i;
}


void str2upper ( char s[] )
{

    int i;

    for ( i = 0; s[i]; i++ )
        s[i] = toupper ( s[i] );

}

