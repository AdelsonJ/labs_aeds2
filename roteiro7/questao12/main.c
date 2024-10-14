#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao12.h"

int main(){
    int *elemento = (int *)malloc(sizeof(int));
    Matriz *matriz = criaMatriz(4, 4);
    preencheAleatorio(matriz, 0, 9);
    imprime(matriz);

    insereElem(matriz, 6, 0, 2);
    consultaElem(matriz, elemento, 0, 2);
    printf("O elemento na posicao [0][2] da matriz eh: %d\n\n", *elemento);

    if(e_matrizQuadrada(matriz)==1)
        printf("A matriz eh quadrada!\n");
    else
        printf("A matriz nao eh quadrada!\n");

    Matriz *mts = criaTriangularSup(matriz);
    imprime(mts);

    Matriz *mti = criaTriangularInf(matriz);
    imprime(mti);

    Matriz *md = criaDiagonal(matriz);
    imprime(md);

    Matriz *mt = criaTransposta(matriz);
    imprime(mt);

    destroiMatriz(matriz);

    return 0;
}