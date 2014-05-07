#include <stdio.h>
#include <string.h>
#define MAXSTR 26
#define MAXPAL 100000
int main()
{
    //char linha[MAXSTR];
    int contador[MAXSTR], i;
    FILE *f;
    int linha = 0;
    char palavras[MAXPAL] [MAXSTR];
    f = fopen("../dicio.txt", "r");


//    for(i=0; i<MAXSTR; i++) {
//        contador[i]=0;
//    }


    while (fgets(palavras[linha], MAXSTR, f) != NULL) {
        palavras[linha][strlen(palavras[linha])-1] = '\0';
        linha++;
        //contador[ linha[0]-'a'] += 1;
    }
    fclose(f);
    printf("Numereo de palavras = %d\n", i);
//    printf("Letra --> Numero de palavras com a letra\n");
//    for(i=0; i<MAXSTR; i++) {
//        printf("%c --> %5d\n", i+'a', contador[i]);

return 0;
}
