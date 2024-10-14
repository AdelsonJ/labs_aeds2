#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao12.h"

int main(){
    int *menor = (int*)malloc(sizeof(int));
    int *maior = (int*)malloc(sizeof(int));
    double nota;
    int escolha, matricula, busca;
    char* nome = (char*)malloc(30 * sizeof(char));
    ABP *abt;
    Aluno *aluno = criaAluno();

    do{
        printf("O que deseja fazer?\n1 - Criar ABP\n2 - Inserir um Aluno\n"
        "3 - Buscar um Aluno pelo nome e imprimir suas informacoes\n"
        "4 - Remover um Aluno pelo nome\n5 - Imprimir a ABP em ordem"
        "\n6 - Imprimir as informacoes do aluno com a maior nota"
        "\n7 - Imprimir as informacoes do aluno com a menor nota\n"
        "8 - Destruir a ABP\n9 - Sair\n");
        scanf("%d",&escolha);

        switch (escolha){
        case 9:
            break;

        case 1:
            abt = criaABP();
            printf("Arvore criada!");
            aguardaLimpa();
            break;

        case 2:
            printf("Digite o elemento que deseja inserir: ");
            scanf("%s %d %lf", nome, &matricula, &nota);
            strcpy(aluno->nome, nome);
            aluno->matricula = matricula;
            aluno->nota = nota;
            insereElem(abt,aluno);
            aguardaLimpa();
            break;

        case 3:
            printf("Digite o nome do aluno que deseja consultar: ");
            scanf("%s",nome);
            strcpy(aluno->nome, nome);
            busca = pesquisa(abt,aluno);
            if(busca == 0)
                printf("O aluno nao esta na arvore!"); 
            aguardaLimpa();
            break;

        case 4:
            printf("Digite o nome do aluno que deseja remover: ");
            scanf("%s",nome);
            strcpy(aluno->nome, nome);
            removeElem(abt,aluno);
            aguardaLimpa();
            break;

        case 5:
            imprime(abt,0);
            aguardaLimpa();
            break;

        case 6:
            *maior = 0;
            strcpy(aluno->nome, maior_nt(*abt, 0, maior, nome));
            busca = pesquisa(abt,aluno);
            aguardaLimpa();
            break;
            
        case 7:
            *menor = 100000.0;
            strcpy(aluno->nome, menor_nt(*abt, 0, menor, nome));
            busca = pesquisa(abt,aluno);
            aguardaLimpa();
            break;

        case 8:
            destroiABP(abt);
            printf("Arvore destruida!");
            aguardaLimpa();
            break;
            
        default:
            printf("\nAlgo de errado nao esta certo!\n\n");
            break;
        }
    }while(escolha!=9);



    return 0;
}