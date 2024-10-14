#include <stdio.h>
#include <stdlib.h>
#include "questao21.h"

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

FilaP* criaFila(){
    FilaP* fp;
    fp = (FilaP*) malloc (sizeof(FilaP));
    if(fp != NULL)
        *fp = NULL;
    return fp;
}

int estaVazia(FilaP* fp){
    if(fp == NULL) return -1;
    return ((*fp) == NULL);
}

int inserirPrio(FilaP* fp, int elem, int pri){
    if(fp == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    
    novo->info = elem;
    novo->prio = pri;

    if(estaVazia(fp)){
        novo->prox = *fp;
        *fp = novo;
    }else{
        NO* aux, *ant;
        ant = NULL;
        aux = *fp;//Inicio
        while(aux != NULL && aux->prio >= novo->prio){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            novo->prox = *fp;
            *fp = novo;
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
    return 1;
}

int removeIni(FilaP* fp){
  if(fp == NULL) return 0;
  if(estaVazia(fp)) return 0;
  NO* aux = *fp;
  *fp = aux->prox;
  liberarNO(aux);
  return 1;
}

int verIni(FilaP* fp, int* p){
  if(fp == NULL) return 0;
  if(estaVazia(fp)) return 0;
  *p = (*fp)->info;
  return 1;
}

void imprime(FilaP* fp){
    if(fp == NULL) return;
    if(estaVazia(fp)){
        printf("Fila Vazia!\n");
        return;
    }
    NO* aux = *fp;
    while(aux != NULL){
        printf("[%d, %d] ", aux->prio, aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiFila(FilaP* fp){
  if(fp != NULL){
    NO* aux;
    while((*fp) != NULL){
      aux = *fp;
      *fp = (*fp)->prox;
      liberarNO(aux);
    }
    free(fp);
  }
}

/* Funcao que conta os itens na fila de prioridade*/
int conta(FilaP* fp){
    if(fp == NULL) return 0;
    if(estaVazia(fp)){
        printf("Fila Vazia!\n");
        return 0;
    }

    int contador = 0;

    NO* aux = *fp;
    while(aux != NULL){
        contador++;
        aux = aux->prox;
    }

    return contador;
}

/* Funcao para esperar resposta do usuario e depois limpar*/
void aguardaLimpa(){
    getchar();
    printf("\n\nAperte qualquer tecla para continuar\n");
    getchar();
    system("clear");
}