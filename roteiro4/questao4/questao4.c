#include <stdio.h>
#include <stdlib.h>
#include "questao4.h"


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
    if(listaVazia(li)){
        novo->prox = novo;
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *li;
        *li = novo;        
    }
    return 1;
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    if(listaVazia(li)){
        novo->prox = novo;
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *li;       
    }
    return 1;
}

int removeIni(Lista *li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* prim = *li;
    if(prim == prim->prox){
        //apenas 1 elemento
        *li = NULL;
    }else{
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = (*li)->prox;
        *li = (*li)->prox;
    }
    liberarNO(prim);
    return 1;
}

int removeFim(Lista *li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    if(aux == aux->prox){
        //apenas 1 elemento
        *li = NULL;
    }else{
        NO* ant;
        while(aux->prox != (*li)){
            ant = aux;//anterior
            aux = aux->prox;
        }  
        ant->prox = *li;
    }
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
    while(aux->prox != *li){
        printf("%d \n", aux->info);
        aux = aux->prox;
    }
    printf("%d ", aux->info);
    printf("\n");
}

void destroiLista(Lista *li){
    if(li != NULL && (*li) != NULL){
        NO* prim, *aux;
        prim = *li;
        *li = (*li)->prox;
        while((*li) != prim){
            aux = *li;
            *li = (*li)->prox;
            printf("Destruindo.. %d\n", aux->info);
            liberarNO(aux);
        }
        printf("Destruindo.. %d\n", prim->info);
        liberarNO(prim);
        free(li);
    }
}

int Tamanho(Lista *li){
    int tam = 1;
    NO *corrente = (*li)->prox; 

    if(corrente == NULL)
        return 0;
    
    do {
        tam++;
        corrente = corrente->prox;
    } while(corrente != *li);

    return tam;
}

int Procura(Lista *li, int x){
    int posicao = 0;
    NO *corrente = (*li)->prox; 

    do{
        posicao ++;
        if(corrente->info == x)
            return posicao;

        corrente = corrente->prox;
    } while(corrente != *li);

    return -1;
}