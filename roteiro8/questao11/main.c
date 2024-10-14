#include <stdio.h>
#include <stdlib.h>
#include "questao11.h"

int main(){
    int *cont = (int*)malloc(sizeof(int));
    int escolha, elem, busca;
    ABP *abt;
    do{
        printf("O que deseja fazer?\n1 - Criar ABP\n2 - Inserir um elemento\n"
        "3 - Buscar um elemento\n4 - Remover um elemento\n5 - Imprimir a ABP em ordem"
        "\n6 - Imprimir a ABP em pre-ordem\n7 - Imprimir a ABP em pos-ordem\n"
        "8 - Mostrar a quantidade de nos na ABP\n9 - Destruir a ABP\n10 - Sair\n");
        scanf("%d",&escolha);

        switch (escolha){
        case 10:
            break;

        case 1:
            abt = criaABP();
            printf("Arvore criada!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d",&elem);
            insereElem(abt,elem);
            aguardaLimpa();
            break;

        case 3:
            printf("Digite o elemento que deseja consultar: ");
            scanf("%d",&elem);
            busca = pesquisa(abt,elem);
            if(busca == 1)
                printf("O numero esta na arvore!");
            else
                printf("O numero nao esta na arvore!"); 
            aguardaLimpa();
            break;

        case 4:
            printf("Digite o elemento que deseja remover: ");
            scanf("%d",&elem);
            removeElem(abt,elem);
            aguardaLimpa();
            break;

        case 5:
            imprime(abt,0);
            aguardaLimpa();
            break;

        case 6:
            imprime(abt,1);
            aguardaLimpa();
            break;
            
        case 7:
            imprime(abt,2);
            aguardaLimpa();
            break;
            
        case 8:
            *cont = 0;
            contador(*abt,0,cont);
            printf("O numero de nos eh: %d!", *cont);
            aguardaLimpa();
            break;

        case 9:
            destroiABP(abt);
            printf("Arvore destruida!");
            aguardaLimpa();
            break;
            
        default:
            printf("\nAlgo de errado nao esta certo!\n\n");
            break;
        }
    }while(escolha!=10);



    return 0;
}