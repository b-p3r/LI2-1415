

typedef struct t_nodo NODO;
NODO* novo_nodo ();
void inserir_pal(NODO *t, char pal[], char offset_char);
int e_pal(NODO* t, char pal[], char offset_char);
int e_prefixo(NODO* t, char pal[], char offset_char);
void imprimir_t(NODO *t, char pal[], int i, char offset_char);
NODO* carregar_dic_t(char dict []);

