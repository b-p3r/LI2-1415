

typedef struct t_nodo NODO;
NODO* novo_nodo ();
void inserir_pal(NODO *t, char pal[]);
int existe(NODO* t, char pal[]);
int e_prefixo(NODO* t, char pal[]);
void imprimir_t(NODO *t, char *pal[]);

