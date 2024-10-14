#include <stdio.h>
#include <stdlib.h>
#include "questao13.h"

int main(){
    int escolha_repeticao, escolha_conjunto, numero;
    int quantidade = 0; 
    
    Conjunto *conjuntoA = criaConjunto();
    Conjunto *conjuntoB = criaConjunto();
    Conjunto *conjuntoC;

    do{
        printf("\nDigite o que deseja fazer: \n1- Inserir um numero no conjunto"
        "\n2- Remover um numero no conjunto \n3- Ver o tamanho do conjunto"
        "\n4- Ver se um numero pertence ao conjunto \n5- Ver qual o maior numero do conjunto"
        "\n6- Ver qual o menor numero do conjunto \n7- Ver a uniao entre dois conjuntos"
        "\n8- Ver a interseccao entre dois conjuntos \n9- Ver a diferenca entre dois conjuntos "
        "\n10- Ver se os conjuntos sao iguais \n11- Ver se um conjunto eh vazio"
        "\n12- Imprimir conjunto \n0- Sair\n");
        scanf("%d",&escolha_repeticao);

        switch (escolha_repeticao){

        /* FINALIZA*/
        case 0:
            libera(conjuntoA);
            libera(conjuntoB);
            break;

        /* INSERCAO */
        case 1:
            printf("\nEscolha qual conjunto deseja fazer a insercao:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    printf("\nDigite o numero que deseja inserir no conjunto A: ");
                    scanf("%d", &numero);
                    insereElemento(conjuntoA,numero);
                    qsort(conjuntoA->elemento,tamanho(conjuntoA),sizeof(int),compara);
                    system("clear");
                    break;
                case 2:
                    printf("\nDigite o numero que deseja inserir no conjunto B: ");
                    scanf("%d", &numero);
                    insereElemento(conjuntoB,numero);
                    qsort(conjuntoB->elemento,tamanho(conjuntoB),sizeof(int),compara);
                    system("clear");
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        /* REMOCAO*/
        case 2:
            printf("\nEscolha qual conjunto deseja fazer a remocao:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    printf("\nDigite o numero que deseja remover do conjunto A: ");
                    scanf("%d", &numero);
                    removeElemento(conjuntoA,numero);
                    qsort(conjuntoA->elemento,tamanho(conjuntoA),sizeof(int),compara);
                    system("clear");
                    break;
                case 2:
                    printf("\nDigite o numero que deseja remover do conjunto B: ");
                    scanf("%d", &numero);
                    removeElemento(conjuntoB,numero);
                    qsort(conjuntoB->elemento,tamanho(conjuntoB),sizeof(int),compara);
                    system("clear");
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        /* TAMANHO*/
        case 3:
            printf("\nEscolha qual conjunto deseja fazer ver o tamanho:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    printf("\nO tamanho do conjunto A eh: %d", tamanho(conjuntoA));
                    aguardaLimpa();
                    break;
                case 2:
                    printf("\nO tamanho do conjunto B eh: %d", tamanho(conjuntoB));
                    aguardaLimpa();
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        /* PERTENCE */
        case 4:
            printf("\nEscolha qual conjunto deseja ver se o numero pertence:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    printf("\nDigite o numero que deseja ver se pertence ao conjunto A: ");
                    scanf("%d", &numero);
                    if(pertence(conjuntoA, numero) == 1)
                        printf("\nO numero %d pertence ao conjunto A", numero);
                    else
                        printf("\nO numero %d nao pertence ao conjunto A", numero);
                    aguardaLimpa();
                    break;
                case 2:
                    printf("\nDigite o numero que deseja ver se pertence ao conjunto B: ");
                    scanf("%d", &numero);
                    if(pertence(conjuntoB, numero) == 1)
                        printf("\nO numero %d pertence ao conjunto B", numero);
                    else
                        printf("\nO numero %d nao pertence ao conjunto B", numero);
                    aguardaLimpa();
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;


        /* MAIOR */
        case 5:
            printf("\nEscolha qual conjunto deseja saber o maior elemento:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    printf("\nO maior elemento do conjunto A eh: %d", maior(conjuntoA));
                    aguardaLimpa();
                    break;
                case 2:
                    printf("\nO maior elemento do conjunto B eh: %d", maior(conjuntoB));
                    aguardaLimpa();
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        /* MENOR */
        case 6:
            printf("\nEscolha qual conjunto deseja saber o menor elemento:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    printf("\nO menor elemento do conjunto A eh: %d", menor(conjuntoA));
                    aguardaLimpa();
                    break;
                case 2:
                    printf("\nO menor elemento do conjunto B eh: %d", menor(conjuntoB));
                    aguardaLimpa();
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        /* UNIAO */
        case 7:            
            conjuntoC = uniao(conjuntoA,conjuntoB);
            imprimeConjunto(conjuntoC);
            aguardaLimpa();
            libera(conjuntoC);
            break;

        /* INTERSECCAO*/
        case 8:            
            conjuntoC = interseccao(conjuntoA,conjuntoB);
            imprimeConjunto(conjuntoC);
            aguardaLimpa();
            libera(conjuntoC);
            break;

        /* DIFERENCA*/
        case 9:            
            conjuntoC = diferenca(conjuntoA,conjuntoB);
            imprimeConjunto(conjuntoC);
            aguardaLimpa();
            libera(conjuntoC);
            break;

        /* EH IGUAL*/
        case 10:            
            if(ehigual(conjuntoA, conjuntoB) == 1)
                printf("\nOs conjuntos sao iguais");
            else
                printf("\nOs conjuntos nao sao iguais");
            aguardaLimpa();
            break;
            
        /* EH IGUAL*/
        case 11:            
            printf("\nEscolha qual conjunto deseja saber se eh vazio:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    if(ehvazio(conjuntoA) == 1)
                        printf("\nO conjunto A eh vazio");
                    else
                        printf("\nO conjunto A nao eh vazio");
                    aguardaLimpa();                        
                    break;
                case 2:
                    if(ehvazio(conjuntoB) == 1)
                        printf("\nO conjunto B eh vazio");
                    else
                        printf("\nO conjunto B nao eh vazio");
                    aguardaLimpa();
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        /* TAMANHO*/
        case 12:
            printf("\nEscolha qual conjunto deseja imprimir:\n1- Conjunto A\n2- Conjunto B\n");
            scanf("%d",&escolha_conjunto);
            switch (escolha_conjunto){
                case 1:
                    imprimeConjunto(conjuntoA);
                    aguardaLimpa();
                    break;
                case 2:
                    imprimeConjunto(conjuntoB);
                    aguardaLimpa();
                    break;
                default:
                    printf("Valor invalido");
                    system("clear");
                    break;
            }
            break;

        default:
            printf("Valor invalido");
            system("clear");
            break;
        }
        
    }while(escolha_repeticao != 0);
    return 1;
}