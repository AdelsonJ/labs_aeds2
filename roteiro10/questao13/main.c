#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao13.h"

int main(int argc, char *argv[]){

    //Atribuicoes iniciais
    setComp(0);
    setMov(0);
    clock_t t;

    int n;

    /* Leitura de arquivo e verificacoes */
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", argv[1]);
        return 1; 
    }

    /* Pega o tamanho do arquivo e cria um vetor com esse tamanho */
    fscanf(arquivo, "%d", &n);

    int *v1 = (int*)malloc(n * sizeof(int));
    int *v2 = (int*)malloc(n * sizeof(int));
    int *v3 = (int*)malloc(n * sizeof(int));

    /* Confere  se o vetor nao esta vazio */
    if (v1 == NULL) {
        fprintf(stderr, "Erro ao alocar memoria para o vetor.\n");
        fclose(arquivo);
        return 1;
    }

    /* Copia os dados do arquivo para esse vetor */
    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%d", &v1[i]);
    }
    
    v2 = copiaVetor(v1, n);
    v3 = copiaVetor(v1, n);
    
    /* BubbleSort */
    t = clock();
    BubbleSort(v1, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por BubbleSort:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    /* InsertionSort */
    setComp(0);
    setMov(0);
    t = clock();
    InsertionSort(v2, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por InsertionSort:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    /* SelectionSort */
    setComp(0);
    setMov(0);
    t = clock();
    SelectionSort(v3, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por SelectionSort:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    free(v1);
    free(v2);
    free(v3);

    fclose(arquivo);

    return 0;
}