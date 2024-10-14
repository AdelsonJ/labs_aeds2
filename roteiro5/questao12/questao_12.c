#include <stdio.h>
#include <stdlib.h>
#include "questao_12.h"

Fila* criaFila(){
    Fila* fi;
    fi = (Fila*) malloc (sizeof(Fila));
    if(fi != NULL){
        fi->qtd = 0;
        fi->ini = fi->fim = NULL;
    }
    return fi;
}

void destroiFila(Fila *fi){
    if(fi != NULL) {
        while (fi->ini != NULL) {
            NO* aux = fi->ini;
            fi->ini = fi->ini->prox;
            free(aux);
        }
        free(fi);
    }
}

int tamanhoFila(Fila *fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int estaCheia(Fila *fi){
    return 0; // Em uma fila encadeada, ela nunca fica cheia
}

int estaVazia(Fila *fi){
    if(fi == NULL)
        return -1;
    return (fi->qtd == 0);
}

int enfileirar(Fila* fi, int elem){
    if(fi == NULL) return 0;
    
    NO* novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL) return 0;
    
    novo->info = elem;
    novo->prox = NULL;
    
    if(estaVazia(fi)){
        fi->ini = fi->fim = novo;
    } else {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    
    fi->qtd++;
    return 1;
}

int desenfileirar(Fila* fi){
    if(fi == NULL || estaVazia(fi)) return 0;
    
    NO* aux = fi->ini;
    fi->ini = fi->ini->prox;
    
    if(fi->ini == NULL)
        fi->fim = NULL;
    
    free(aux);
    fi->qtd--;
    return 1;
}

int verInicio(Fila* fi, int* p){
    if(fi == NULL || estaVazia(fi)) return 0;
    *p = fi->ini->info;
    return 1;
}

void imprime(Fila* fi){
    if(fi == NULL) return;
    if(estaVazia(fi)){
        printf("Fila Vazia!\n");
        return;
    }
    NO* aux = fi->ini;
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