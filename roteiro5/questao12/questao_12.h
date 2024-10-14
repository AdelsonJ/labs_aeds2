#ifndef FSE_H
#define FSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info ;
    struct NO *prox ;
} NO ;

typedef struct {
    int qtd ;
    struct NO *ini ;
    struct NO *fim ;
} Fila ;


Fila* criaFila();
void destroiFila(Fila *);
int tamanhoFila(Fila *);
int estaCheia(Fila *);
int estaVazia(Fila *);
int enfileirar(Fila *, int);
int desenfileirar(Fila *);
int verInicio(Fila *, int*);
void imprime(Fila *);

/*Funcoa extra*/
void aguardaLimpa();

# endif
