#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Cabecalho */
float* preencheVetor(float *,int);
float maiorElemento(float *, int);
float menorElemento(float *, int);
float media(float *, int);
void imprimeVetor(float *, int);

/* Funcao que preenche o vetor recursivamente*/
float* preencheVetor(float *vetor, int tamanho){
    srand((time_t)time(NULL));
    if(tamanho!=0)
        vetor = preencheVetor(vetor, tamanho-1);
    vetor[tamanho]= rand() %100;
    return vetor;
}

/* a) Funcao que retorna o maior elemento */
float maiorElemento(float *vet, int N){
    float maior = 0;
    for(int i = 0; i < N; i++){
        if(vet[i] > maior)
            maior = vet[i];
    }
    return maior;
}

/* b) Funcao que retorna o menor elemento */
float menorElemento(float *vet, int N){
    float menor = 10000000000;
    for(int i = 0; i < N; i++){
        if(vet[i] < menor)
            menor = vet[i];
    }
    return menor;
}


/* c) Funcao que retorna o media entre os elementos do vetor */
float media(float *vet, int N){
    float soma = 0;
    for(int i = 0; i < N; i++)
        soma = soma + vet[i];
    return soma/N;
}

/* Imprime vetor */
void imprimeVetor(float *vetor, int tamanho){
    for(int i = 0; i<tamanho; i++)
        printf("vetor[%d] = %.3f\n", i, vetor[i]);
}


void main(){
    int tamanho = 5;
    float *vetor = (float*)malloc(sizeof(float)*tamanho);

    vetor = preencheVetor(vetor,tamanho);
    imprimeVetor(vetor, tamanho);

    printf("O menor elemento eh: %.3f\n",menorElemento(vetor,5));
    printf("O maior elemento eh: %.3f\n",maiorElemento(vetor,5));
    printf("A media dos elementos eh: %.3f\n",media(vetor,5));
}