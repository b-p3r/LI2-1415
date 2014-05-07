#include <stdio.h>
#include <string.h>
#define MAXSTR 26

int main() {
	char linha[MAXSTR];
	int contador[MAXSTR], i;
	for(i=0;i<MAXSTR;i++) {
		contador[i]=0;
	}
	while (fgets(linha, MAXSTR, stdin) != NULL) {
		linha[strlen(linha)-1] = '\0';
		contador[ linha[0]-'a'] += 1;
	}
	printf("Letra --> Numero de palavras com a letra\n");
	for(i=0;i<MAXSTR;i++) {
		printf("%c --> %5d\n", i+'a', contador[i]);
	}
	return 0;
}
