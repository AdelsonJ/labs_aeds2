#include <stdio.h>
#include <stdlib.h>
#include "questao12.h"
#include <string.h>

int main() {
    int *cont = (int*)malloc(sizeof(int));
    int escolha, ano_contratacao, busca;
    double salario;    
    char* nome = (char*)malloc(30 * sizeof(char));
    AVL avl = NULL;

    do {
        printf("O que deseja fazer?\n1 - Criar AVL\n2 - Inserir um salario do funcionario\n"
               "3 - Buscar um funcionario\n4 - Remover um funcionario\n5 - Imprimir a AVL em ordem"
               "\n6 - Imprimir as informacoes do Funcionario com o maior salario\n"
               "7 - Imprimir as informacoes do Funcionario com o menor salario\n8 - Destruir a AVL\n9 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 9:
                break;

            case 1:
                if (avl == NULL) {
                    avl = criaAVL();
                    printf("Arvore criada!\n");
                } else {
                    printf("A arvore ja foi criada!\n");
                }
                aguardaLimpa();
                break;

            case 2:
                if (avl == NULL) {
                    printf("Crie a arvore AVL antes de inserir um funcionario!\n");
                } else {
                    printf("Digite o salario, o nome e o ano de contratacao do Funcionario que deseja inserir: ");
                    scanf("%lf", &salario);
                    getchar();
                    fgets(nome, 30, stdin);
                    nome[strcspn(nome, "\n")] = '\0'; 
                    scanf("%d", &ano_contratacao);
                    
                    insereElem(avl, salario, nome, ano_contratacao);
                    aguardaLimpa();
                }
                break;

            case 3:
                if (avl == NULL) {
                    printf("Crie a arvore AVL antes de buscar um funcionario!\n");
                } else {
                    printf("Digite o salario do funcionario que deseja consultar: ");
                    scanf("%lf", &salario);
                    busca = pesquisa(avl, salario);
                    if (busca == 1)
                        printf("O funcionario esta na arvore!\n");
                    else
                        printf("O funcionario nao esta na arvore!\n"); 
                    aguardaLimpa();
                }
                break;

            case 4:
                if (avl == NULL) {
                    printf("Crie a arvore AVL antes de remover um funcionario!\n");
                } else {
                    printf("Digite o salario do funcionario que deseja remover: ");
                    scanf("%lf", &salario);
                    removeElem(avl, salario);
                    aguardaLimpa();
                }
                break;

            case 5:
                if (avl == NULL) {
                    printf("Crie a arvore AVL antes de imprimir!\n");
                } else {
                    imprime(avl);
                    aguardaLimpa();
                }
                break;

            case 6:
                if (avl == NULL) {
                    printf("Crie a arvore AVL antes de imprimir!\n");
                } else {
                    Funcionario func = maior(avl);
                    printf("O funcionario de maior salario eh:%s\nSeu salario eh de %.2lf\n"
                    "Ele entrou no ano %d\n", func.nome,func.salario,func.anoContratacao);
                    aguardaLimpa();
                }
                break;

            case 7:
                if (avl == NULL) {
                    printf("Crie a arvore AVL antes de imprimir!\n");
                } else {
                    Funcionario func = menor(avl);
                    printf("O funcionario de menor salario eh:%s\nSeu salario eh de %.2lf\n"
                    "Ele entrou no ano %d", func.nome,func.salario,func.anoContratacao);
                    aguardaLimpa();
                }
                break;

            case 8:
                if (avl != NULL) {
                    destroiAVL(avl);
                    printf("arvore destruida!\n");
                } else {
                    printf("A arvore ja foi destruida ou ainda nao foi criada!\n");
                }
                aguardaLimpa();
                break;
                
            default:
                printf("\nOpcao invalida!\n\n");
                break;
        }
    } while (escolha != 9);

    free(cont);
    free(nome);
    
    return 0;
}
