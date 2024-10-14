#include <stdio.h>
#include <stdlib.h>
#include "questao13.h"

/* Funcao que criar um conjunto vazio */
Conjunto* criaConjunto(){
    Conjunto *conjunto = (Conjunto*)malloc(sizeof(Conjunto));
    conjunto->tamanho = 0;
    conjunto->elemento = (int*)malloc(sizeof(int)*1);
    conjunto->elemento[0] = 999999999;
    return conjunto;
}

/* Funcao que faz uniao de dois conjuntos */
Conjunto* uniao(Conjunto *conjuntoA, Conjunto *conjuntoB){
    int tamanhoA = tamanho(conjuntoA);
    int tamanhoB = tamanho(conjuntoB);

    Conjunto *conjuntoC = criaConjunto();

    /* Percorre o conjunto A adicionando seus elementos no conjunto C*/
    for(int i = 0; i <tamanhoA; i++)
        insereElemento(conjuntoC,conjuntoA->elemento[i]);

    /* Percorre o conjunto B adicionando seus elementos no conjunto C*/
    for(int i=0; i < tamanhoB; i++){
        if(!pertence(conjuntoA,conjuntoB->elemento[i]))
            insereElemento(conjuntoC,conjuntoB->elemento[i]);
    }
    return conjuntoC;
}

/* Funcao que insere um elemento no conjunto*/
void insereElemento(Conjunto *conjunto, int numero){
    int tamanho_local = tamanho(conjunto);

    if(tamanho_local== 0){
        conjunto->elemento[tamanho_local] = numero;
        conjunto->tamanho ++;
    }
    else{
        if(pertence(conjunto,numero) == 1)
            return;
        conjunto->elemento = (int *)realloc(conjunto->elemento, (tamanho_local + 1) * sizeof(int));
        conjunto->elemento[tamanho_local] = numero;
        conjunto->tamanho ++;
    }
    return;
}

/* Funcao que remove um elemento do conjunto */
void removeElemento(Conjunto *conjunto, int numero){
    int tamanho_local = tamanho(conjunto);
    int aux;
    /* Loop for para percorrer o conjunto*/
    for(int i=0; i < tamanho_local; i++){
        /* Comparacao para conferir se o numero naquela posicao eh igual 
            ao buscado*/
        if(conjunto->elemento[i]==numero){
            /* Se o elemento a ser excluido nao estiver na ultima posicao
                troca-o de lugar com o ultimo*/
            if(i < tamanho_local-1){
                aux = conjunto->elemento[tamanho_local-1];
                conjunto->elemento[tamanho_local-1] = conjunto->elemento[i];
                conjunto->elemento[i] = aux;
            }

            /*diminui o tamanho do vetor e retorna*/
            conjunto->tamanho --;
            conjunto->elemento = (int *)realloc(conjunto->elemento, (tamanho_local -1) * sizeof(int));
            return;
        }
    }
}

/* Funcao que faz a interseccao entre dois conjuntos */
Conjunto* interseccao(Conjunto *conjuntoA, Conjunto *conjuntoB){
    int tamanhoA = tamanho(conjuntoA);
    int tamanhoB = tamanho(conjuntoB);

    Conjunto *conjuntoC = criaConjunto();

    /* Loops for para percorrer os conjuntos A e B*/
    for(int i=0; i < tamanhoA; i++){
        for(int j=0; j<tamanhoB; j++){
            /* Comparacao para conferir se os numeros dos elementos sao iguais*/
            if(conjuntoA->elemento[i] == conjuntoB->elemento[j])
                insereElemento(conjuntoC,conjuntoA->elemento[i]);
        }
    }

    return conjuntoC;
}

/* Funcao que faz a diferenca de dois conjuntos */
Conjunto* diferenca(Conjunto *conjuntoA, Conjunto *conjuntoB){
    int tamanhoB = tamanho(conjuntoB);

    Conjunto *conjuntoC = criaConjunto();

    /* Loops for para percorrer os conjuntos A e B*/
    for(int i=0; i < tamanhoB; i++){
        if(!pertence(conjuntoA,conjuntoB->elemento[i]))
            insereElemento(conjuntoC,conjuntoB->elemento[i]);
    }

    return conjuntoC;
}

/* Funcao que testa se um numero pertence ao conjunto */
int pertence(Conjunto *conjunto, int numero){
    int tamanho_local = tamanho(conjunto);

    /*Loop for para percorrer o vetor */
    for(int i=0; i < tamanho_local; i++){
        /* Retorna 1 se o numero estiver no conjunto*/
        if(conjunto->elemento[i] == numero)
            return 1;
    }

    return 0;
}

/* Funcao que retorna o menor valor do conjunto */
int menor(Conjunto *conjunto){
    int tamanho_local = tamanho(conjunto);
    int menor = 100000000;

    /*Loop for para percorrer o vetor */
    for(int i=0; i < tamanho_local; i++){
        /* Retorna 1 se o numero estiver no conjunto*/
        if(conjunto->elemento[i] < menor)
            menor = conjunto->elemento[i];
    }

    return menor;
}

/* Funcao que retorna o maior valor do conjunto */
int maior(Conjunto *conjunto){
    int tamanho_local = tamanho(conjunto);
    int maior = -100000000;

    /*Loop for para percorrer o vetor */
    for(int i=0; i < tamanho_local; i++){
        /* Retorna 1 se o numero estiver no conjunto*/
        if(conjunto->elemento[i] > maior)
            maior = conjunto->elemento[i];
    }

    return maior;
}

/* Funcao que testa se dois conjuntos sao iguais */
int ehigual(Conjunto *conjuntoA, Conjunto *conjuntoB){
    int tamanhoA = tamanho(conjuntoA);
    int tamanhoB = tamanho(conjuntoB);

    /* Se os tamanhos sao diferentes, entao eles nao sao iguais */
    if(tamanhoA != tamanhoB)
        return 0;
    
    /* compara cada elemento para ver se sao iguais, caso nao sejam, retorna 0*/
    for(int i = 0; i < tamanhoA; i++){
        if(conjuntoA->elemento[i] != conjuntoB->elemento[i])
            return 0;
    }

    /* retorna 1 se tds os elementos forem iguais*/
    return 1;
}

/* Funcao que retorna o tamanho do conjunto */
int tamanho(Conjunto *conjunto){
    return conjunto->tamanho;
}

/* Funcao que testa se o conjunto é vazio */
int ehvazio(Conjunto *conjunto){
    if(tamanho(conjunto) == 0)
        return 1;
    else
        return 0;
}

/* funcao que imprime o conjunto */
void imprimeConjunto(Conjunto *conjunto){
    int tamanho_local = tamanho(conjunto);

    printf("Conjunto: (");
    for(int i = 0; i < tamanho_local;i++){
        if(i != 0)
            printf(",");    
        printf("%d",conjunto->elemento[i]);
    }
    printf(")\n");
}

/* Funcao que desaloca um conjunto*/
void libera(Conjunto *conjunto){
    free(conjunto->elemento);
    free(conjunto);
}

/* Parte da funcao do quick sort */
int compara(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

/* Funcao para esperar resposta do usuario e depois limpar*/
void aguardaLimpa(){
    getchar();
    printf("\n\nAperte qualquer tecla para continuar\n");
    getchar();
    system("clear");
}