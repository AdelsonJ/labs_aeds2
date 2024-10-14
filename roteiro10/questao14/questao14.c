#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "questao14.h"

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes


int getComp(){
    return comp;
}

int getMov(){
    return mov;
}

void setComp(int valor){
    comp = valor;
}

void setMov(int valor){
    mov = valor;
}

Pessoa* criaPessoa(){
    Pessoa *pessoa = (Pessoa*) malloc (sizeof(Pessoa));
    pessoa->idade = 0;
    pessoa->nome = "";
    return pessoa;
}


Pessoa* copiaVetor(Pessoa* v, int n){
    int i;
    Pessoa* v2 = (Pessoa*)malloc(n * sizeof(Pessoa));

    if (v2 == NULL){
        fprintf(stderr, "Erro ao alocar memoria para o vetor de copia.\n");
        exit(1);
    }

    for (i = 0; i < n; i++){
        v2[i].idade = v[i].idade;
        v2[i].nome = strdup(v[i].nome);
        if (v2[i].nome == NULL){
            fprintf(stderr, "Erro ao alocar memoria para a copia do nome.\n");
            exit(1);
        }
    }
    return v2;
}

void liberaPessoa(Pessoa* pessoa){
    if (pessoa != NULL){
        free(pessoa->nome);
        free(pessoa);
    }
}

void imprimeVetor(Pessoa* v, int n){
    int i, prim = 1;
    printf("[");
    for (i = 0; i < n; i++){
        if (prim){
            printf("{idade: %d, nome: %s}", v[i].idade, v[i].nome);
            prim = 0;
        } else {
            printf(", {idade: %d, nome: %s}", v[i].idade, v[i].nome);
        }
    }
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void troca(Pessoa* a, Pessoa* b){
    Pessoa aux = *a;
    *a = *b;
    *b = aux;
    mov++;
}

void BubbleSort(Pessoa* v, int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            comp++;
            // Compara primeiro os nomes, em caso de empate compara as idades
            if (strcmp(v[j].nome, v[j + 1].nome) > 0 || (strcmp(v[j].nome, v[j + 1].nome) == 0 && v[j].idade > v[j + 1].idade)){
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}

void InsertionSort(Pessoa* v, int n){
    int i, j;
    Pessoa atual;
    for(i = 1; i < n; i++){
        atual = v[i];
        comp++;
        for(j = i; (j > 0) && (strcmp(atual.nome, v[j - 1].nome) < 0 || (strcmp(atual.nome, v[j - 1].nome) == 0 && atual.idade < v[j - 1].idade)); j--){
            v[j] = v[j - 1];
            comp++;
            mov++;
        }
        v[j] = atual;
    }
}

void SelectionSort(Pessoa* v, int n){
    int i, j, menor;
    for(i = 0; i < n - 1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            comp++;
            // Compara primeiro os nomes, em caso de empate compara as idades
            if (strcmp(v[j].nome, v[menor].nome) < 0 || (strcmp(v[j].nome, v[menor].nome) == 0 && v[j].idade < v[menor].idade)){
                menor = j;
            }
        }
        if(i != menor){
            troca(&v[i], &v[menor]);
        }
    }
}

void InsertionDecres(Pessoa* v, int n){
    int i, j;
    Pessoa atual;
    for(i = 1; i < n; i++){
        atual = v[i];
        comp++;
        for(j = i; (j > 0) && (strcmp(atual.nome, v[j - 1].nome) > 0 || (strcmp(atual.nome, v[j - 1].nome) == 0 && atual.idade > v[j - 1].idade)); j--){
            v[j] = v[j - 1];
            comp++;
            mov++;
        }
        v[j] = atual;
    }
}

void SelectionDecres(Pessoa* v, int n){
    int i, j, menor;
    for(i = 0; i < n - 1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            comp++;
            // Compara primeiro os nomes, em caso de empate compara as idades
            if (strcmp(v[j].nome, v[menor].nome) > 0 || (strcmp(v[j].nome, v[menor].nome) == 0 && v[j].idade > v[menor].idade)){
                menor = j;
            }
        }
        if(i != menor){
            troca(&v[i], &v[menor]);
        }
    }
}