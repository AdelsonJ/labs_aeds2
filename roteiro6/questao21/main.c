#include <stdio.h>
#include <stdlib.h>
#include "questao21.h"

int main(){
    int escolha_inicial, item, prioridade;
    int *inicio = (int*)malloc(sizeof(int));
    FilaP *filap;

    do{
        printf("O que deseja fazer?\n1 - Criar Fila\n2 - Inserir um item pela prioridade\n"
        "3 - Ver o inicio da Fila\n4 - Remover um item;\n5 - Imprimir a Fila;"
        "\n6 - Mostrar o tamanho da Fila\n7 - Destruir a Fila\n8 - Sair\n");
        scanf("%d",&escolha_inicial);

        switch (escolha_inicial){
        case 8:
            break;

        case 1:
            filap = criaFila();
            printf("Fila criada!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o numero que deseja adicionar, junto a sua prioridade\n");
            scanf("%d %d",&item,&prioridade);
            if(inserirPrio(filap,item, prioridade) == 1)
                printf("Item inserido na sua prioridade!");
            else
                printf("Fila cheia ou inexistente!");
            aguardaLimpa();
            break;

        case 3:
            if(verIni(filap, inicio) == 1)
                printf("O valor inicial da fila eh: %d", *inicio);
            else
                printf("Fila vazia");
            aguardaLimpa();
            break;

        case 4:
            if(removeIni(filap) == 1)
                printf("Elemento de maior prioridade da fila foi removido!");
            else
                printf("Fila vazio");
            aguardaLimpa();
            break;
        
        case 5:
            imprime(filap);
            aguardaLimpa();
            break;

        case 6:
            printf("O tamanho da Fila de Prioridade eh  %d", conta(filap));
            aguardaLimpa();
            break;
        
        case 7:
            destroiFila(filap);
            printf("Fila destruido");
            aguardaLimpa();
            break;
        
        default:            
            printf("Valor invalido");
            break;
        }
    }while(escolha_inicial != 8);

    free(inicio);
    
    return 0;
}