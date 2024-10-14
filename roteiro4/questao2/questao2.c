#include <stdio.h>
#include <stdlib.h>
#include "questao2.h"

Lista* criaLista(){
    Lista *li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;//True - Vazia!
    return 0;//False - tem elemento!
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = *li;
    *li = novo;
    return 1;
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}

int removeIni(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    *li = aux->prox;
    liberarNO(aux);
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* ant, *aux = *li;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == *li)
        *li = aux->prox;
    else   
        ant->prox = aux->prox;
    liberarNO(aux);
    return 1;
}

void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *li;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiLista(Lista* li){
    if(li != NULL){
        NO* aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}

int Tamanho(Lista* li){
    int tam = 1;
    NO* aux = *li;
    while(aux->prox != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int Procura(Lista* li, int elem){
    int tam = 0;
    NO* aux = *li;
    while(aux->prox != NULL){
        aux = aux->prox;
        tam++;
        if(aux->info == elem)
            return tam;
    }
    return -1;
}

int insereOrdenada(Lista* li, int elem){
    NO* novo = alocarNO();
    novo->info = elem;

    if(listaVazia(li) || (*li)->info > elem){
        insereIni(li,elem);
        return 1;
    }

    NO* aux = *li;
    while(aux->prox != NULL && elem > aux->prox->info)
        aux = aux->prox;

    novo->prox = aux->prox;
    aux->prox = novo;
    
    return 1;
}

int removeOrdenada(Lista* li, int elem){
    if(listaVazia(li))
        printf("Lista Vazia\n");
    

    if((*li)->info > elem){
        removeIni(li);
        return 1;
    }

    if(Procura(li,elem) != -1){
        NO* anterior = *li;
        NO* atual = (*li)->prox;

        while (atual != NULL && atual->info < elem) {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual != NULL && atual->info == elem) {
            anterior->prox = atual->prox;
            free(atual);
            return 1;
        }

    }else  
        printf("Elemento nao esta na lista\n");
}