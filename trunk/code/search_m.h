#ifndef SEARCH_H
#define SEARCH_H

#include "trie_t.h"
#include "constants.h"
void depth_first_serpente ( int l, int c, int nlin, int ncol, char pal[], int i, char mat[] [MAX], int mat_flag[][MAX], NODO *trie, NODO *store );
void depth_first_cavalo ( int l, int c, int nlin, int ncol, char pal[], int i, char mat[] [MAX], int mat_flag[][MAX], NODO *trie, NODO *store );
#endif
