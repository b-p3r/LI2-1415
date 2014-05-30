

typedef struct t_nodo NODO;
NODO* novo_nodo ();
void inserir_pal(NODO *t, char pal[], char offset_char);
int existe(NODO* t, char pal[], char offset_char);
int e_prefixo(NODO* t, char pal[], char offset_char);
int append_char2str(char pal [], char a,  int i, char offset_char);
void imprimir_t(NODO *t, char pal[], int i, char offset_char);

