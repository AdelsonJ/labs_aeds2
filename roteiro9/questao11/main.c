#include <stdio.h>
#include <stdlib.h>
#include "questao11.h"

int main(){
    int *cont = (int*)malloc(sizeof(int));
    int escolha, elem, busca;
    AVL *avl;
    do{
        printf("O que deseja fazer?\n1 - Criar AVL\n2 - Inserir um elemento\n"
        "3 - Buscar um elemento\n4 - Remover um elemento\n5 - Imprimir a AVL em ordem"
        "\n6 - Mostrar a quantidade de nos na AVL\n7 - Destruir a AVL\n8 - Sair\n");
        scanf("%d",&escolha);

        switch (escolha){
        case 8:
            break;

        case 1:
            avl = criaAVL();
            printf("Arvore criada!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d",&elem);
            insereElem(avl,elem);
            aguardaLimpa();
            break;

        case 3:
            printf("Digite o elemento que deseja consultar: ");
            scanf("%d",&elem);
            busca = pesquisa(avl,elem);
            if(busca == 1)
                printf("O numero esta na arvore!");
            else
                printf("O numero nao esta na arvore!"); 
            aguardaLimpa();
            break;

        case 4:
            printf("Digite o elemento que deseja remover: ");
            scanf("%d",&elem);
            removeElem(avl,elem);
            aguardaLimpa();
            break;

        case 5:
            imprime(avl);
            aguardaLimpa();
            break;

        case 6:
            *cont = 0;
            contador(*avl,0,cont);
            printf("O numero de nos eh: %d!", *cont);
            aguardaLimpa();
            break;

        case 7:
            destroiAVL(avl);
            printf("Arvore destruida!");
            aguardaLimpa();
            break;
            
        default:
            printf("\nAlgo de errado nao esta certo!\n\n");
            break;
        }
    }while(escolha!=8);



    return 0;
}