#include <stdio.h>
#include <stdlib.h>
#include "questao_22.h"

Pilha* criaPilha(){
    Pilha* pi;
    pi = (Pilha*) malloc (sizeof(Pilha));
    if(pi != NULL){
        pi->qtd = 0;
        pi->topo = NULL;
    }
    return pi;
}

void destroiPilha(Pilha *pi){
    if(pi != NULL) {
        while (pi->topo != NULL) {
            NO* aux = pi->topo;
            pi->topo = pi->topo->prox;
            free(aux);
        }
        free(pi);
    }
}

int tamanhoPilha(Pilha *pi){
    if(pi == NULL)
        return -1;
    return pi->qtd;
}

int estaCheia(Pilha *pi){
    return 0;
}

int estaVazia(Pilha *pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

int empilhar(Pilha* pi, int elem){
    if(pi == NULL) return 0;
    
    NO* novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL) return 0;
    
    novo->info = elem;
    novo->prox = pi->topo;
    
    pi->topo = novo;
    pi->qtd++;
    
    return 1;
}

int desempilhar(Pilha* pi){
    if(pi == NULL || estaVazia(pi)) return 0;
    
    NO* aux = pi->topo;
    pi->topo = pi->topo->prox;
    free(aux);
    pi->qtd--;
    
    return 1;
}

int verTopo(Pilha* pi, int* p){
    if(pi == NULL || estaVazia(pi)) return 0;
    *p = pi->topo->info;
    return 1;
}

void imprime(Pilha* pi){
    if(pi == NULL) return;
    if(estaVazia(pi)){
        printf("Pilha Vazia!\n");
        return;
    }
    
    NO* aux = pi->topo;
    printf("Elementos: \n");
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

/* Funcao para esperar resposta do usuario e depois limpar*/
void aguardaLimpa(){
    getchar();
    printf("\n\nAperte qualquer tecla para continuar\n");
    getchar();
    system("clear");
}
