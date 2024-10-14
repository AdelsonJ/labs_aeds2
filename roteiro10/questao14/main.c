#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "questao14.h"

int main(){
    srand(time(NULL));
    setComp(0);
    setMov(0);
    clock_t t;

    Pessoa *v1, *v2, *v3, *v4;
    Pessoa *p1, *p2, *p3;
    int n = 3;

    v1 = (Pessoa*) malloc(n * sizeof(Pessoa));
    
    p1 = criaPessoa();
    p1->idade = 20;
    p1->nome = strdup("Fulano");
    v1[0] = *p1;

    p2 = criaPessoa();
    p2->idade = 50;
    p2->nome = strdup("Fulano");
    v1[1] = *p2;

    p3 = criaPessoa();
    p3->idade = 30;
    p3->nome = strdup("Beltrano");
    v1[2] = *p3;

    imprimeVetor(v1, n);
    
    v2 = copiaVetor(v1, n);
    v3 = copiaVetor(v1, n);
    v4 = copiaVetor(v1, n);

    /* InsertionSort */
    setComp(0);
    setMov(0);
    t = clock();
    InsertionSort(v1, n);
    t = clock() - t;
    printf("\nInformacoes da ordenacao por InsertionSort crescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n * sizeof(Pessoa));

    imprimeVetor(v1, n);

    /* SelectionSort */
    setComp(0);
    setMov(0);
    t = clock();
    SelectionSort(v2, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por SelectionSort crescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n * sizeof(Pessoa));

    imprimeVetor(v2, n);

    /* InsertionSort Descrescente*/
    setComp(0);
    setMov(0);
    t = clock();
    InsertionDecres(v1, n);
    t = clock() - t;
    printf("\nInformacoes da ordenacao por InsertionSort decrescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n * sizeof(Pessoa));

    imprimeVetor(v1, n);

    /* SelectionSort Descrescente*/
    setComp(0);
    setMov(0);
    t = clock();
    SelectionDecres(v2, n);
    t = clock() - t;
    printf("\nInformacoes da Ordenacao por SelectionSort decrescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());
    printf("Movimentacoes: %d\n", getMov());
    printf("Memoria (bytes): %ld\n", n * sizeof(Pessoa));

    imprimeVetor(v2, n);

    free(v1);
    free(v2);
    free(v3);
    free(v4);

    // Certifique-se de liberar a memoria alocada para cada Pessoa
    liberaPessoa(p1);
    liberaPessoa(p2);
    liberaPessoa(p3);

    return 0;
}
