#ifndef MATRIZDIN_H
#define MATRIZDIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int **dados;
    int lin, col;
}Matriz;

void zeraMatriz(Matriz *);
Matriz* criaMatriz(int, int);
void destroiMatriz(Matriz *);
int preencheAleatorio(Matriz *, int, int);
int insereElem(Matriz *, int, int, int);
int consultaElem(Matriz *, int *, int, int);
void imprime(Matriz *);

//Matrizes Quadradas e propriedades

int e_matrizQuadrada(Matriz *);
Matriz* criaTriangularSup(Matriz *);
Matriz* criaTriangularInf(Matriz *);
Matriz* criaDiagonal(Matriz *);
int e_Simetrica(Matriz *);
Matriz* criaTransposta(Matriz *);

#endif