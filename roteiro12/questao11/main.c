#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao11.h"

int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    setComp(0);
    clock_t t;

    int *v1;
    int n, x, ind;

    /* Recebe valores e preenche */
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    v1 = (int*) malloc (n*sizeof(int));

    preencheAleatorio(v1, n, 1, 100);
    QuickSort(v1,0,n-1);
    imprimeVetor(v1, n);
    
    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    /* Pesquisa Binaria Recursiva */
    t = clock();
    ind = rec_buscaBinaria(v1,0,n-1,x);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Binaria Recursiva:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);

    /* Pesquisa Binaria iterativa */
    t = clock();
    ind = it_buscaBinaria(v1,0,n-1,x);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Binaria iterativa:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);

    /* Pesquisa Sequencial */
    t = clock();
    ind = buscaSequencial(v1,n,x);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Sequencial:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);

    free(v1);

    return 0;
}