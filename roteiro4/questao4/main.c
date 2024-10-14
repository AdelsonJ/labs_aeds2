#include <stdio.h>
#include "questao4.h"

int main () {
    Lista *L;
    L = criaLista ();

    insereFim(L,2);
    insereFim(L,1);
    insereFim(L,9);

    imprimeLista(L);
    printf("O tamanho eh: %d\n", Tamanho(L));
    printf("A posicao eh: %d\n", Procura(L,1));

    return 0;
}