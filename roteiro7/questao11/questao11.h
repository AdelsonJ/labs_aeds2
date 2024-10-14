#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct{
    int dados[MAX][MAX];
    int lin, col;
}Matriz;

void zeraMatriz(Matriz *);
Matriz* criaMatriz(int, int);
void destroiMatriz(Matriz *);
int preencheAleatorio(Matriz *, int, int);
int insereElem(Matriz *, int, int, int);
int consultaElem(Matriz *, int *, int, int);
void imprime(Matriz *);
int e_matrizQuadrada(Matriz *);
Matriz* criaTriangularSup(Matriz *);
Matriz* criaTriangularInf(Matriz *);
Matriz* criaDiagonal(Matriz *);
int e_Simetrica(Matriz *);
Matriz* criaTransposta(Matriz *);

#endif