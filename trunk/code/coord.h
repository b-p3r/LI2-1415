#ifndef COORD_H
#define COORD_H
int existe_c ( int x [], int y [], int l, int c , int tam );
void limpar_array_coords ( int x [], int y [], int n );
int calcularCoordX_Serpen ( int x, int pos );
int calcularCoordY_Serpen ( int y, int pos );
int calcularCoordX_Passo_Cav ( int x, int pos );
int calcularCoordY_Passo_Cav ( int y, int pos );
int jogadas_PossiveisPC ( int a[], int b[], int l, int c, int nlin, int ncol );
int jogadas_Possiveis_Serpent ( int a[], int b[], int l, int c, int nlin, int ncol );

#endif
