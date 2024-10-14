#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao22.h"
#include "questao12.h"

int main(){
    MEsparsaCSR *matriz_csr, *t_matriz_csr;
    Matriz *matriz;
    int escolha, elemento, linhas, colunas, x, y;

    do{
        printf("Digite o que deseja fazer:\n1- Criar matriz_csr\n2- Imprime os vetores\n"
            "3- Inserir elemento\n4- Remover elemento\n5- Transformar em CSR\n"
            "6- Consultar elemento\n7- Imprimir a matriz_csr\n8- Destruir a matriz_csr\n0- Sair\n");
        scanf("%d",&escolha);

        switch (escolha){
        case 0:
            break;

        case 1:
            printf("Digite as linha e colunas da matriz_csr\n");
            scanf("%d %d", &linhas, &colunas);
            matriz_csr = criaMatrizEsparsa(linhas, colunas, 0);
            printf("Matriz criada!");
            aguardaLimpa();
            break;

        case 2:
            imprimeEsparsaVetores(matriz_csr);
            aguardaLimpa();
            break;

        case 3:
            printf("Digite o elemento que deseja inserir, assim como sua posicao\n");
            scanf("%d %d %d", &elemento, &x, &y);
            insereElemEsparsa(matriz_csr, elemento, x, y);
            aguardaLimpa();
            break;
        
        case 4:
            printf("Digite as posicoes do elemento que deseja remover\n");
            scanf("%d %d", &x, &y);
            removeElemEsparsa(matriz_csr, x, y);
            aguardaLimpa();
            break;

        case 5:
            matriz = criaMatriz(4,4);
            preencheAleatorio(matriz, 0, 9);
            imprime(matriz);
            t_matriz_csr = transformarEmCSR(matriz);
            imprimeEsparsa(t_matriz_csr);
            aguardaLimpa();
            destroiMatriz(matriz);
            destroiMatrizEsparsa(t_matriz_csr);
            break;

        case 6:
            printf("O elemento na posicao [0][2] da matriz_csr eh: %d", consultaElemEsparsa(matriz_csr, 0, 2));
            aguardaLimpa();
            break;

        case 7:
            imprimeEsparsa(matriz_csr);
            aguardaLimpa();
            break;

        case 8:
            destroiMatrizEsparsa(matriz_csr);
            printf("Matriz destruida!");
            aguardaLimpa();
            break;
            
        default:
            printf("Algo de errado nao esta certo!");
            break;
        }
    }while(escolha!=0);

    return 0;
}