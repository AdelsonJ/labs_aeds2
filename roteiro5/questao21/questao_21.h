#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int topo;
    int dados[MAX];
}Pilha;


Pilha* criaPilha();
void destroiPilha(Pilha *);
int tamanhoPilha(Pilha *);
int estaCheia(Pilha *);
int estaVazia(Pilha *);
int empilhar(Pilha *, int);
int desempilhar(Pilha *);
int verTopo(Pilha *, int *);
void imprime(Pilha *);

/* Funcao extra */
void aguardaLimpa();

#endif