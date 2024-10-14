#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int qtd, ini, fim;
    int dados[MAX];
}Deque;

/* Funcoes */
Deque* criaDeque();
void destroiDeque(Deque *);
int tamanhoDeque(Deque *);
int estaCheio(Deque *);
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