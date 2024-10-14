#ifndef MESPARSACSR_H
#define MESPARSACSR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao12.h"

typedef struct{
    int *A; //Valores
    int *IA;
    int *JA;
    int lin, col, QNN, QI;
}MEsparsaCSR;
//QNN - Quantidade de Nao Nulos
//QI - Quantidade de Inseridos

MEsparsaCSR* criaMatrizEsparsa(int, int, int);
int* meuRealloc(int *, int);
void imprimeEsparsaVetores(MEsparsaCSR *);
int insereElemEsparsa(MEsparsaCSR *, int, int, int);
int removeElemEsparsa(MEsparsaCSR *, int, int);
MEsparsaCSR* transformarEmCSR(Matriz *);
int consultaElemEsparsa(MEsparsaCSR *, int, int);
void imprimeEsparsa(MEsparsaCSR *);
void destroiMatrizEsparsa(MEsparsaCSR *);

/*Funcao extra*/
void aguardaLimpa();

#endif