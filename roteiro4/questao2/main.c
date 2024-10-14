#include <stdio.h>
#include "questao2.h"

int main(){
    Lista *L;
    L = criaLista();

    insereOrdenada(L, 20);
    insereOrdenada(L, 30);
    insereOrdenada(L, 10);
    insereOrdenada(L, 50);

    removeOrdenada(L,20);

    imprimeLista(L);

    printf("O tamanho da lista eh: %d\n", Tamanho(L));
    printf("A posicao do elemento na lista eh: %d\n", Procura(L,30));

    destroiLista(L);
    return 0;
}