#include <stdio.h>
#include "questao3.h"

int main(){
    Lista *L;
    L = criaLista();


    insereOrdenada(L, 40);
    insereOrdenada(L, 10);
    insereOrdenada(L, 20);
    insereOrdenada(L, 70);
    insereOrdenada(L, 90);
    insereOrdenada(L, 30);
    insereOrdenada(L, 50);
    insereOrdenada(L, 80);
    insereOrdenada(L, 60);

    removeOrdenada(L,60);
    removeOrdenada(L,30);

    imprimeLista(L);

    printf("O tamanho da lista eh: %d\n", Tamanho(L));
    printf("A posicao do elemento na lista eh: %d\n", Procura(L,40));

    destroiLista(L);
    return 0;
}