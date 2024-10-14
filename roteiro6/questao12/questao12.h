#ifndef DDE_H
#define DDE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
    struct NO* ant;
}NO;

typedef struct{
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Deque;

/* Funcoes */
NO* alocarNO();
void liberarNO(NO *);
Deque* criaDeque();
void destroiDeque(Deque *);
int tamanhoDeque(Deque *);
int estaVazio(Deque *);
int insereIni(Deque *, int);
int insereFim(Deque *, int);
int removeIni(Deque *);
int removeFim(Deque *);
int verInicio(Deque *, int *);
int verFim(Deque *, int *);
void imprime(Deque *);

/*Funcao extra*/
void aguardaLimpa();

#endif