#include <stdio.h>

/* Cabecalho */
void ordena(int[], int );
int somaVetor(int[], int);

/* Funcao que ordena o vetor de forma crescente*/
void ordena(int vetor[], int tamanho){
    int posicao_do_menor = 0;
    int aux = 0; 
    for(int i = 0; i < tamanho; i++){
        posicao_do_menor = i;

        for (int j= i+1; j < tamanho;j++){
            if(vetor[j] < vetor[posicao_do_menor])
                posicao_do_menor = j;
        }

        if(i != posicao_do_menor){
            aux = vetor[i];
            vetor[i] = vetor[posicao_do_menor];
            vetor[posicao_do_menor] = aux; 
        }

    }    
}

/* Funcao que soma o vetor */
int somaVetor(int vetor[], int posicao){
    int soma = vetor[posicao];
    if(posicao != 0)
        soma = soma + somaVetor(vetor, posicao-1);
    return soma;
}

void main(){
    int vetor[5] = {5,4,3,2,1};

    ordena(vetor, 5);

    printf("Soma do vetor: %d\n", somaVetor(vetor, 4));
}