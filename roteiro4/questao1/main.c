#include <stdio.h>
#include "questao1.h"

int main () {
    Lista *L;
    L = criaLista () ;
    insereOrdenado(L,9);
    insereOrdenado(L,4);
    insereOrdenado(L,7);
    insereOrdenado(L,1);
    imprimeLista(L);
    printf("o numero ta na posicao %d\n",Procura(L,7));

    removeOrdenado(L,2);
    imprimeLista(L);

    destroiLista(L);
    return 0;
}