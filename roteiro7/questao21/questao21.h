#ifndef MFAIXA_H
#define MFAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int *diagonal;
    int *superior;
    int *inferior;
    int tam;
}MFaixa;

void zeraMatriz(MFaixa *);
MFaixa* criaMatriz(int);
void destroiMatriz(MFaixa *);
int preencheAleatorio(MFaixa *, int, int);
int insereElem(MFaixa *, int, int, int);
int consultaElem(MFaixa *, int, int);
void imprimeFaixaVetores(MFaixa *);
void imprimeFaixa(MFaixa *);

/*Funcao extra*/
void aguardaLimpa();

#endif