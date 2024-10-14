#include <stdio.h>
#include <stdlib.h>
#include "questao_12.h"

int main(){
    int escolha_inicial, item;
    int *inicio = (int*)malloc(sizeof(int));
    Fila *fila;
    do{
        printf("O que deseja fazer?\n1 - Criar fila\n2 - Enfileirar um item\n3 - Ver o inicio da fila\n"
        "4 - Desenfileirar um item;\n5 - Imprimir a fila;\n6 - Destruir a fila\n7 - Sair\n");
        scanf("%d",&escolha_inicial);
        switch (escolha_inicial){

        case 7:
            break;

        case 1:
            fila = criaFila();
            printf("Fila criada!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o numero que deseja enfilerar");
            scanf("%d",&item);
            if(enfileirar(fila,item) == 1)
                printf("Elemento enfilerado!");
            else
                printf("Fila cheia ou nao existente!");
            aguardaLimpa();
            break;

        case 3:
            if(verInicio(fila, inicio) == 1)
                printf("O valor inicial da fila eh: %d", *inicio);
            else
                printf("Fila Vazia");
            aguardaLimpa();
            break;

        case 4:
            if(desenfileirar(fila) == 1)
                printf("Primeiro elemento da fila desenfilerado!");
            else
                printf("Fila Vazia!");
            aguardaLimpa();
            break;
        
        case 5:
            imprime(fila);
            aguardaLimpa();
            break;
        
        case 6:
            destroiFila(fila);
            printf("Fila destruida");
            aguardaLimpa();
            break;
        
        default:            
            printf("Valor invalido");
            break;
        }
    }while(escolha_inicial != 7);

    free(inicio);

    return 0;
}