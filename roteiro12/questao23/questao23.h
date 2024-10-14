#ifndef HASH_H
#define HASH_H

#include "lse.h"

typedef struct{
    Lista **tabela;
    int tam, qtd;
}Hash;


void preencheAleatorio(int* v, int n, int ini, int fim);
Hash* criaHash(int t);
void destroiHash(Hash *h);
int chaveDivisao(int chave, int tam);
int chaveMultiplicacao(int chave, int tam);
int chaveDobra(int chave, int tam);
int valorString(char *str);
int insereHashLSE(Hash* h, int elem);
int buscaHashLSE(Hash* h, int elem, int *p);
void imprimeHash(Hash *h);
#endif