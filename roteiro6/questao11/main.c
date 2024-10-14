#include <stdio.h>
#include <stdlib.h>
#include "questao11.h"

int main(){
    int escolha_inicial, item;
    int *inicio = (int*)malloc(sizeof(int));
    Deque *deque;

    do{
        printf("O que deseja fazer?\n1 - Criar deque\n2 - Inserir um item no fim\n"
        "3 - Inserir um item no inicio\n4 - Ver o inicio do Deque;\n5 - Ver o fim do Deque;"
        "\n6 - Remover um item do fim\n7 - Remover um item do inicio\n"
        "8 - Imprimir o Deque \n9 - Destruir o Deque \n10 - Sair\n");
        scanf("%d",&escolha_inicial);

        switch (escolha_inicial){
        case 10:
            break;

        case 1:
            deque = criaDeque();
            printf("Deque criado!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o numero que deseja adicionar no fim\n");
            scanf("%d",&item);
            if(insereFim(deque,item) == 1)
                printf("Item inserido no fim!");
            else
                printf("Deque cheio ou inexistente!");
            aguardaLimpa();
            break;

        case 3:
            printf("Digite o numero que deseja adicionar no inicio\n");
            scanf("%d",&item);
            if(insereIni(deque,item) == 1)
                printf("Item inserido no inicio!");
            else
                printf("Deque cheio ou inexistente!");
            aguardaLimpa();
            break;

        case 4:
            if(verInicio(deque, inicio) == 1)
                printf("O valor inicial do deque eh: %d", *inicio);
            else
                printf("Deque vazio");
            aguardaLimpa();
            break;

        case 5:
            if(verFim(deque, inicio) == 1)
                printf("O ultimo valor do deque eh: %d", *inicio);
            else
                printf("Deque vazio");
            aguardaLimpa();
            break;

        case 6:
            if(removeFim(deque) == 1)
                printf("Ultimo elemento do deque removido!");
            else
                printf("Deque vazio");
            aguardaLimpa();
            break;
        
        case 7:
            if(removeIni(deque) == 1)
                printf("Primeiro elemento do deque removido!");
            else
                printf("Deque vazio");
            aguardaLimpa();
            break;
        
        case 8:
            imprime(deque);
            aguardaLimpa();
            break;
        
        case 9:
            destroiDeque(deque);
            printf("Deque destruido");
            aguardaLimpa();
            break;
        
        default:            
            printf("Valor invalido");
            break;
        }
    }while(escolha_inicial != 10);

    free(inicio);
    
    return 0;
}