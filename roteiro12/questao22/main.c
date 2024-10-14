#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "questao22.h"

int main() {
    int buscaElem, x;
    int tam = 10;
    int numElementos = 15;

    /* Criacao da tabela hash */
    Hash *hashDivisao = criaHash(tam);
    Hash *hashMultiplicacao = criaHash(tam);
    Hash *hashDobra = criaHash(tam);

    /*  Criacao de vetores com valores aleatorios */
    int elementos[numElementos];
    preencheAleatorio(elementos, numElementos, 1, 100);

    /* Insercao e teste de busca com funcao de hashing: Divisao */
    printf("Espalhamento com funcao de hashing: Divisao\n");
    for (int i = 0; i < numElementos; i++) {
        insereHash_EnderAberto(hashDivisao, elementos[i], 1); 
    }
    imprimeHash(hashDivisao);

    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    if (buscaHash_EnderAberto(hashDivisao, x, &buscaElem, 1)) { 
        printf("Elemento %d encontrado na tabela\n", x);
    } else {
        printf("Elemento %d nao encontrado na tabela\n", x);
    }

    /* Insercao e teste de busca com funcao de hashing: Multiplicacao */
    printf("\nEspalhamento com funcao de hashing: Multiplicacao\n");
    for (int i = 0; i < numElementos; i++) {
        insereHash_EnderAberto(hashMultiplicacao, elementos[i], 2); 
    }
    imprimeHash(hashMultiplicacao);

    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    if (buscaHash_EnderAberto(hashMultiplicacao, x, &buscaElem, 2)) { 
        printf("Elemento %d encontrado na tabela\n", x);
    } else {
        printf("Elemento %d nao encontrado na tabela\n", x);
    }

    /* Insercao e teste de busca com funcao de hashing: Dobra */
    printf("\nEspalhamento com funcao de hashing: Dobra\n");
    for (int i = 0; i < numElementos; i++) {
        insereHash_EnderAberto(hashDobra, elementos[i], 3); // 3: Sondagem Duplo Hash
    }
    imprimeHash(hashDobra);

    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    if (buscaHash_EnderAberto(hashDobra, x, &buscaElem, 3)) { // 3: Sondagem Duplo Hash
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
