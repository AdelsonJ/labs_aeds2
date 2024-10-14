#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao11.h"

int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    setComp(0);
    setMov(0);
    clock_t t;

    int *v1, *v2, *v3;
    int n;

    /* Recebe valores e preenche */
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    v1 = (int*) malloc (n*sizeof(int));

    preencheAleatorio(v1, n, 1, 100);
    imprimeVetor(v1, n);
    
    v2 = copiaVetor(v1, n);
    v3 = copiaVetor(v1, n);
    
    /* MergeSort */
    t = clock();
    MergeSort(v1, 0, n-1);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por MergeSort:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v1, n);

    /* HeapSort */
    setComp(0);
    setMov(0);
    t = clock();
    HeapSort(v2, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por HeapSort:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v2, n);

    /* QuickSort */
    setComp(0);
    setMov(0);
    t = clock();
    QuickSort(v3, 0, n-1, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por QuickSort:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v3, n);

    free(v1);
    free(v2);
    free(v3);

    return 0;
}