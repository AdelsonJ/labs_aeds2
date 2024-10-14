#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Cabecalho */
int* preencheVetor(int *, int );
void ordena(int*, int );
void imprimeCrescente(int *, int , int );
void imprimeDecrescente(int *, int );

/* a) Funcao que preenche o vetor recursivamente*/
int* preencheVetor(int *vetor, int tamanho){
    srand((time_t)time(NULL));
    if(tamanho!=0)
        vetor = preencheVetor(vetor, tamanho-1);
    vetor[tamanho]= rand() %100;

    return vetor;
}

/* Funcao que ordena o vetor de forma descrescente*/
void ordena(int *vetor, int tamanho){
    int posicao_do_maior = 0;
    int aux = 0; 
    for(int i = 0; i < tamanho; i++){
        posicao_do_maior = i;

        for (int j= i+1; j < tamanho;j++){
            if(vetor[j] > vetor[posicao_do_maior])
                posicao_do_maior = j;
        }

        if(i != posicao_do_maior){
            aux = vetor[i];
            vetor[i] = vetor[posicao_do_maior];
            vetor[posicao_do_maior] = aux; 
        }

    }    
}


/* b) Funcao que imprime o vetor */
void imprimeCrescente(int *vetor, int tamanho, int posicao){
    if(posicao != tamanho-1)
        imprimeCrescente(vetor, tamanho, posicao+1);
    printf("%d  ", vetor[posicao]);
}

/* b) Funcao que imprime o vetor */
void imprimeDecrescente(int *vetor, int tamanho){
    if(tamanho != 1)
        imprimeDecrescente(vetor, tamanho-1);
    printf("%d  ", vetor[tamanho-1]);
}


/* c) Funcao que busca o maior elemento no vetor e retorna-o*/
int devolveMaior(int *vetor, int tamanho, int maior){
    if(tamanho != 0)
        maior = devolveMaior(vetor, tamanho-1, maior);
    if(vetor[tamanho]> maior)
        maior = vetor[tamanho];
    return maior;
}


void main(){
    int tamanho = 5;
    int *vetor = (int*)malloc(sizeof(int)*tamanho);
    
    vetor = preencheVetor(vetor, tamanho);
    
    printf("Vetor: ");
    imprimeDecrescente(vetor, tamanho);
    printf("\n");

    ordena(vetor, tamanho);
    
    printf("Vetor crescente:");
    imprimeCrescente(vetor, tamanho, 0);
    printf("\nVetor decrescente:");
    imprimeDecrescente(vetor, tamanho);
    printf("\nMaior elemento do vetor: %d\n", devolveMaior(vetor, tamanho, 0));
}