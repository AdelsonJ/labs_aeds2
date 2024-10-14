#include <stdio.h>
#include <stdlib.h>
#include "questao_21.h"

int main(){
    int escolha_inicial, item;
    int *topo = (int*)malloc(sizeof(int));
    Pilha *pilha;

    do{
        printf("O que deseja fazer?\n1 - Criar pilha\n2 - Empilha um item\n3 - Ver o topo da pilha\n"
        "4 - Desempilha um item;\n5 - Imprimir a pilha;\n6 - Destruir a pilha\n7 - Sair\n");
        scanf("%d",&escolha_inicial);
        switch (escolha_inicial){

        case 7:
            break;

        case 1:
            pilha = criaPilha();
            printf("Pilha criada!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o numero que deseja enfilerar");
            scanf("%d",&item);
            if(empilhar(pilha,item) == 1)
                printf("Elemento enfilerado!");
            else
                printf("Pilha cheia ou nao existente!");
            aguardaLimpa();
            break;

        case 3:
            if(verTopo(pilha, topo) == 1)
                printf("O valor do topo da pilha eh: %d", *topo);
            else
                printf("Pilha Vazia");
            aguardaLimpa();
            break;

        case 4:
            if(desempilhar(pilha) == 1)
                printf("Ultimo elemento da pilha desempilhado!");
            else
                printf("Pilha Vazia!");
            aguardaLimpa();
            break;
        
        case 5:
            imprime(pilha);
            aguardaLimpa();
            break;
        
        case 6:
            destroiPilha(pilha);
            printf("Pilha destruida");
            aguardaLimpa();
            break;
        
        default:            
            printf("Valor invalido");
            break;
        }
    }while(escolha_inicial != 7);

    free(topo);

    return 0;
}