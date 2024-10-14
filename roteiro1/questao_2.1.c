#include <stdio.h>

/* Cabecalho */
void crescente(int, int);
void decrescente(int, int);

/* Funcao que imprime o vetor de forma crescente */
void crescente(int maximo, int minimo){
    if(maximo != minimo)
        crescente(maximo-1, minimo);
    printf("%d  ",maximo);
} 

/* Funcao que imprime o vetor de forma decrescente */
void decrescente(int maximo, int minimo){
    if(maximo != minimo)
        decrescente(maximo, minimo+1);
    printf("%d  ",minimo);
}

void main(){
    int maximo = 5;
    int minimo = 1;

    printf("Forma crescente: ");
    crescente(maximo, minimo);
    printf("\n");

    printf("Forma decrescente: ");
    decrescente(maximo, minimo);
    printf("\n");
}