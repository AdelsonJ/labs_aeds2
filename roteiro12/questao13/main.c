#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "questao13.h"

int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    setComp(0);
    clock_t t;

    Aluno *alunos;
    char nome[50];
    int n, matricula, indice;

    n = 3;

    alunos = criaAluno(n);

    strcpy(alunos[0].nome, "Fulano");
    alunos[0].matricula = 1;
    alunos[0].notas[0] = 10;
    alunos[0].notas[1] = 9;
    alunos[0].notas[2] = 8;

    strcpy(alunos[1].nome, "Beltrano");
    alunos[1].matricula = 2;
    alunos[1].notas[0] = 7;
    alunos[1].notas[1] = 7;
    alunos[1].notas[2] = 6;

    strcpy(alunos[2].nome, "Ciclano");
    alunos[2].matricula = 3;
    alunos[2].notas[0] = 10;
    alunos[2].notas[1] = 10;
    alunos[2].notas[2] = 5;
    

    QuickSortAluno(alunos, 0, n - 1);
    printf("Vetor Ordenado por Nome:\n");
    for (int i = 0; i < n; i++) {
        imprimeAluno(&alunos[i]);
    }
    
    printf("Digite a matricula de um aluno para busca:\n");
    scanf("%d", &matricula);

    /* Pesquisa Binaria Iterativa por Matricula */
    t = clock();
    indice = it_buscaBinariaPorMatricula(alunos, 0, n - 1, matricula);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Binaria Iterativa por Matricula:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if (indice != -1) {
        printf("O aluno com a matricula %d foi encontrado na posicao %d.\n", matricula, indice);
        imprimeAluno(&alunos[indice]);
    } else {
        printf("O aluno com a matricula %d NAO foi encontrado!\n", matricula);
    }

    /* Pesquisa Binaria Recursiva por Matricula */
    t = clock();
    indice = rec_buscaBinariaPorMatricula(alunos, 0, n - 1, matricula);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Binaria Recursiva por Matricula:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if (indice != -1) {
        printf("O aluno com a matricula %d foi encontrado na posicao %d.\n", matricula, indice);
        imprimeAluno(&alunos[indice]);
    } else {
        printf("O aluno com a matricula %d NAO foi encontrado!\n", matricula);
    }

    /* Pesquisa Sequencial por Matricula */
    t = clock();
    indice = buscaSequencialPorMatricula(alunos, n, matricula);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Sequencial por Matricula:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if (indice != -1) {
        printf("O aluno com a matricula %d foi encontrado na posicao %d.\n", matricula, indice);
        imprimeAluno(&alunos[indice]);
    } else {
        printf("O aluno com a matricula %d NAO foi encontrado!\n", matricula);
    }

    getchar();
    printf("\n\nDigite o nome de um aluno para busca:\n");
    fgets(nome, sizeof(nome), stdin);

    int len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }

    /* Pesquisa Binaria Iterativa por Nome */
    t = clock();
    indice = it_buscaBinariaPorNome(alunos, 0, n - 1, nome);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Binaria Iterativa por Nome:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if (indice != -1) {
        printf("O aluno com a nome %s foi encontrado na posicao %d.\n", nome, indice);
        imprimeAluno(&alunos[indice]);
    } else {
        printf("O aluno com a nome %s NAO foi encontrado!\n", nome);
    }

    /* Pesquisa Binaria Recursiva por Nome */
    t = clock();
    indice = rec_buscaBinariaPorNome(alunos, 0, n - 1, nome);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Binaria Recursiva por Nome:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if (indice != -1) {
        printf("O aluno com a nome %s foi encontrado na posicao %d.\n", nome, indice);
        imprimeAluno(&alunos[indice]);
    } else {
        printf("O aluno com a nome %s NAO foi encontrado!\n", nome);
    }

    /* Pesquisa Sequencial por Nome */
    t = clock();
    indice = buscaSequencialPorNome(alunos, n, nome);
    t = clock() - t;
    printf("\nInformacoes da Pesquisa Sequencial por Nome:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", getComp());

    if (indice != -1) {
        printf("O aluno com a nome %s foi encontrado na posicao %d.\n", nome, indice);
        imprimeAluno(&alunos[indice]);
    } else {
        printf("O aluno com a nome %s NAO foi encontrado!\n", nome);
    }
    
    free(alunos);

    return 0;
}
