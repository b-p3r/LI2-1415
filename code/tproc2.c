# include <stdio.h>
# include "cadeias.h"
int main()
{
    char s1 [1000];
    char s2 [1000];
    int n;
    char c;
    scanf ("%c", &c);
    scanf ("%s", s1);


    printf ("%d\n", cad_ocorrencias(c, s1));
    return 0;
}
