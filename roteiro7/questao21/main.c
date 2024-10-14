#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao21.h"

int main(){
    MFaixa *faixa;
    int escolha, elemento, tamanho, x, y;

    do{
        printf("Digite o que deseja fazer:\n1- Zerar a faixa\n2- Criar a faixa\n"
            "3- Destruir a faixa\n4- Prencher aleatoriamente\n5- Inserir elemento\n"
            "6- Consultar elemento\n7- Imprimir faixa vetores\n8- Imprimir faixa\n0- Sair\n");
        scanf("%d",&escolha);

        switch (escolha){
        case 0:
            break;

        case 1:
            zeraMatriz(faixa);
            printf("Faixa zerada!\n");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o tamanho da faixa\n");
            scanf("%d", &tamanho);
            faixa = criaMatriz(tamanho);
            printf("Faixa criada!");
            aguardaLimpa();
            break;

        case 3:
            destroiMatriz(faixa);
            printf("Faixa destruida!");
            aguardaLimpa();
            break;
        
        case 4:
            preencheAleatorio(faixa, 0, 9);
            printf("Faixa preenchida aleatoriamente!");
            aguardaLimpa();
            break;

        case 5:
            printf("Digite o elemento que deseja inserir, assim como sua posicao\n");
            scanf("%d %d %d", &elemento, &x, &y);
            insereElem(faixa, elemento, x, y);
            aguardaLimpa();
            break;

        case 6:
            printf("O elemento na posicao [2][3] da faixa eh: %d", consultaElem(faixa, 2, 3));
            aguardaLimpa();
            break;

        case 7:
            imprimeFaixaVetores(faixa);
            aguardaLimpa();
            break;

        case 8:
            imprimeFaixa(faixa);
            aguardaLimpa();
            break;
            
        default:
            printf("Algo de errado nao esta certo!");
            break;
        }
    }while(escolha!=0);

    return 0;
}