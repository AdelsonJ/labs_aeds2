#include <stdio.h>

/* Cabecalho */
int multiplica(int, int);

/* Funcao que multiplica um valor m, n vezes */
int multiplica(int n, int m){
    int multiplicacao = m;
    if(n!=1)
        multiplicacao = multiplicacao * multiplica(n-1, m);
    return multiplicacao;
}

void main(){
    int m = 2;
    int n = 5;

    printf("Soma do vetor: %d\n", multiplica(n,m));
}