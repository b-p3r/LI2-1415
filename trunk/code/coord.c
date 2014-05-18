#include <stdio.h>

#define N1 1
#define S1 2
#define W1 3
#define E1 4

#define N2 5
#define S2 6
#define W2 7
#define E2 8




#define N 1
#define NE 2
#define NW 3
#define W 4

#define E 5
#define SW 6
#define SE 7
#define S 8

int existe_c(int x [], int y [], int l, int c , int tam)
{

    int i, existe = 0;
    for(i = 0; i <=tam; i++) {
        if(x[i]==l&&y[i]==c) {
            existe = 1;
            break;
        }
    }
    return existe;

}

void limpar_array_coords(int x [], int y [], int n)
{
    int i;
    for(i = 0; i < n; i++) {
        x[i]=-1;
        y[i]=-1;
    }



}



int calcularCoordX_Serpen (int l, int pos)
{
    int res = 0;

    switch (pos) {

    case N :

        res = l-1;
        break;
    case NW :

        res = l-1;
        break;
    case NE :
        res = l-1;
        break;
    case W :
        res = l;
        break;

    case E :
        res = l;
        break;
    case SW :
        res = l+1;
        break;

    case SE :

        res = l+1;
        break;
    case S :

        res = l+1;
        break;

    }

    return res;

}


int calcularCoordY_Serpen (int c, int pos)
{
    int res = 0;

    switch (pos) {

    case N :

        res = c;
        break;
    case NW :

        res = c-1;
        break;
    case NE :
        res = c+1;
        break;
    case W :
        res = c-1;
        break;

    case E :
        res = c+1;
        break;
    case SW :
        res = c-1;
        break;

    case SE :

        res = c+1;
        break;
    case S :

        res = c;
        break;

    }


    return res;
}


int calcularCoordX_Passo_Cav (int l, int pos)
{
    int res = 0;

    switch (pos) {

    case N1 :

        res = l-2;
        break;
    case N2 :

        res = l-2;
        break;
    case W1 :
        res = l-1;
        break;
    case E1 :
        res = l-1;
        break;

    case W2 :
        res = l+1;
        break;
    case E2 :
        res = l+1;
        break;

    case S1 :

        res = l+2;
        break;
    case S2 :

        res = l+2;
        break;

    }

    return res;

}



int calcularCoordY_Passo_Cav (int c, int pos)
{
    int res = 0;

    switch (pos) {

    case N1 :
        res = c-1;

        break;
    case N2 :
        res= c+1;
        break;

    case W1 :

        res = c-2;
        break;
    case E1 :

        res = c+2;
        break;
    case W2 :

        res = c-2;
        break;
    case E2 :

        res = c+2;
        break;

    case S1 :
        res = c-1;
        break;
    case S2 :
        res = c+1;
        break;

    }
    return res;
}


int e_Jogada_Valid(int l, int c, int nlin, int ncol)
{

    return (l>=0&&l<nlin)&&(c>=0&&c<ncol);

}




int jogadas_PossiveisPC(int a[], int b[],int l, int c, int nlin, int ncol)
{
    int i, j, linha , coluna;


    for(i=0, j=1; j <= 8; j++) {
        linha = calcularCoordX_Passo_Cav(l,j);
        coluna = calcularCoordY_Passo_Cav(c,j);
        if(e_Jogada_Valid(linha, coluna, nlin,ncol)) {
            a[i]=linha;
            b[i]=coluna;
            i++;
        }
    }

   
    return i;
}

int jogadas_Possiveis_Serpent(int a[], int b[],int l, int c, int nlin, int ncol)
{
    int i, j, linha , coluna;
    for(i=0, j=1; j <= 8; j++) {
        linha = calcularCoordX_Serpen(l,j);
        coluna = calcularCoordY_Serpen(c,j);
      
        if(e_Jogada_Valid(linha, coluna, nlin,ncol)) {
            a[i]=linha;
            b[i]=coluna;
            i++;
        }
    }

    return i;
}
