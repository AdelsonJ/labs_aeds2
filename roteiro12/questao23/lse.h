#ifndef LSE_H
#define LSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;    
}NO;

typedef struct NO* Lista;

Lista* criaLista();
int listaVazia(Lista *li);
NO* alocarNO();
void liberarNO(NO* q);
int listaBuscaElem(Lista* li, int elem, int *p);
int insereIni(Lista* li, int elem);
int insereFim(Lista* li, int elem);
int removeIni(Lista* li);
int removeFim(Lista* li);
void imprimeLista(Lista* li);
void destroiLista(Lista* li);

#endif
