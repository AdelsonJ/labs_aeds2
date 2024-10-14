#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lse.h"
#include "questao23.h"

int main() {
    int buscaElem, x;
    int tam = 10;
    int numElementos = 15;

    /* Criacao da tabela hash */
    Hash *hashDivisao = criaHash(tam);
    Hash *hashMultiplicacao = criaHash(tam);
    Hash *hashDobra = criaHash(tam);

    /* Criacao de vetores com valores aleatorios */
    int elementos[numElementos];
    preencheAleatorio(elementos, numElementos, 1, 100);

    /* Insercao e teste de busca com funcao de hashing: Divisao */
    printf("Espalhamento com funcao de hashing: Divisao\n");
    for (int i = 0; i < numElementos; i++) {
        insereHashLSE(hashDivisao, elementos[i]);
    }
    imprimeHash(hashDivisao);

    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    if (buscaHashLSE(hashDivisao, x, &buscaElem)) {
        printf("Elemento %d encontrado na tabela\n", x);
    } else {
        printf("Elemento %d nao encontrado na tabela\n", x);
    }

    /* Insercao e teste de busca com funcao de hashing: Multiplicacao */
    printf("\nEspalhamento com funcao de hashing: Multiplicacao\n");
    for (int i = 0; i < numElementos; i++) {
        insereHashLSE(hashMultiplicacao, elementos[i]);
    }
    imprimeHash(hashMultiplicacao);

    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    if (buscaHashLSE(hashMultiplicacao, x, &buscaElem)) {
        printf("Elemento %d encontrado na tabela\n", x);
    } else {
        printf("Elemento %d nao encontrado na tabela\n", x);
    }

    /* Insercao e teste de busca com funcao de hashing: Dobra */
    printf("\nEspalhamento com funcao de hashing: Dobra\n");
    for (int i = 0; i < numElementos; i++) {
        insereHashLSE(hashDobra, elementos[i]);
    }
    imprimeHash(hashDobra);

    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    if (buscaHashLSE(hashDobra, x, &buscaElem)) {
        printf("Elemento %d encontrado na tabela\n", x);
    } else {
        printf("Elemento %d nao encontrado na tabela\n", x);
    }

    /* Libera a memoria alocada */
    destroiHash(hashDivisao);
    destroiHash(hashMultiplicacao);
    destroiHash(hashDobra);

    return 0;
}
