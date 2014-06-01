#ifndef PROC_SOPA_H
#define PROC_SOPA_H

#include "constants.h"

void init_cabecalho ( int ncol );
void print_sopa ( char mat[][MAX], int nlin, int ncol );
void cria_sopa_letras ( char mat [][MAX], int nlin, int ncol );
int le_coords ( int x [], int y [] );
int le_coords_jogo ( char mat[][MAX], int x [], int y [], int tipo, int nlin, int ncol );
void introduzir_coords ( int *l, int *c );
int dentro_limites ( int l, int c, int nlin, int ncol );
void refrescar_tela ( char mat[][MAX], int nlin, int ncol );
int calcula_pos ( int a[], int b[], int tipo, int nlin, int ncol, int l, int c );
void procura_string ( int x [], int y [], int ncoords, char mat [] [MAX], char resultado [] );

#endif
