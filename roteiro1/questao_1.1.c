#include <stdio.h>

/* Cabecalho */
int negativos(float *vet, int N);

/* Funcao que confere a quantidade de numeros negativos em um vetor e a retorna*/
int negativos(float *vet, int N){
    int contador = 0;
    /* Percorre o vetor e quando acha um negativo adiciona no contador local*/
    for(int i = 0; i < N; i++){
        if(vet[i] < 0)
            contador++;
    }
    /* Devolve o valor do contador local, que contem a quantidade de numeros negativos*/
    return contador;
}

void main(){
    float vetor[5] = {1,-2,-3,4-5};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    
    printf("A quantidade de numeros negativos no vetor eh: %d\n",negativos(vetor,tamanho));
}

