#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "questao13.h"

//Medidas de Complexidade
int comp; //Num. de comparacoes

int getComp(){
    return comp;
}

void setComp(int valor){
    comp = valor;
}

Aluno* criaAluno(int n){
    Aluno *aluno = (Aluno*) malloc (n * sizeof(Aluno));
    for(int i=0; i<n; i++){
        aluno[i].matricula = 0;
        strcpy(aluno[i].nome, "");
        aluno[i].notas[0] = 0;
        aluno[i].notas[1] = 0;
        aluno[i].notas[2] = 0;
    }
    return aluno;
}

Aluno* copiaAluno(Aluno* a) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novo->nome, a->nome);
    novo->matricula = a->matricula;
    memcpy(novo->notas, a->notas, sizeof(float) * 3);
    return novo;
}

void imprimeAluno(Aluno* a) {
    printf("Nome: %s, Matricula: %d, Notas: %.2f, %.2f, %.2f\n",
           a->nome, a->matricula, a->notas[0], a->notas[1], a->notas[2]);
}

void trocaAluno(Aluno* a, Aluno* b) {
    Aluno temp;
    memcpy(&temp, a, sizeof(Aluno));
    memcpy(a, b, sizeof(Aluno));
    memcpy(b, &temp, sizeof(Aluno));
}

void QuickSortAluno(Aluno* v, int ini, int fim) {
    if (ini < fim) {
        int q = particaoAluno(v, ini, fim);
        QuickSortAluno(v, ini, q);
        QuickSortAluno(v, q + 1, fim);
    }
}

int particaoAluno(Aluno* v, int ini, int fim) {
    Aluno pivo = v[(ini + fim) / 2];
    int i = ini, j = fim;
    while (1) {
        while (strcmp(v[i].nome, pivo.nome) < 0) {
            i++;
        }
        while (strcmp(v[j].nome, pivo.nome) > 0) {
            j--;
        }
        if (i < j) {
            trocaAluno(&v[i], &v[j]);
            i++;
            j--;
        } else {
            return j;
        }
    }
}

int buscaSequencialPorNome(Aluno* v, int n, const char* nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].nome, nome) == 0) {
            return i; 
        }
    }
    return -1;
}

int rec_buscaBinariaPorNome(Aluno* v, int ini, int fim, const char* nome) {
    if (ini > fim) return -1;

    int meio = (ini + fim) / 2;
    int comparacao = strcmp(v[meio].nome, nome);

    if (comparacao == 0) {
        return meio; 
    } else if (comparacao > 0) {
        return rec_buscaBinariaPorNome(v, ini, meio - 1, nome);
    } else {
        return rec_buscaBinariaPorNome(v, meio + 1, fim, nome);
    }
}

int it_buscaBinariaPorNome(Aluno* v, int ini, int fim, const char* nome) {
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int comparacao = strcmp(v[meio].nome, nome);

        if (comparacao == 0) {
            return meio; 
        } else if (comparacao > 0) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return -1;
}

int buscaSequencialPorMatricula(Aluno* v, int n, int matricula) {
    int i;
    for(i = 0; i < n; i++) {
        comp++;
        if(v[i].matricula == matricula) {
            return i;
        }
    }
    return -1; 
}

int rec_buscaBinariaPorMatricula(Aluno* v, int ini, int fim, int matricula) {
    if(ini > fim) return -1;
    int meio = (ini + fim) / 2;
    comp++;
    if(v[meio].matricula == matricula) {
        return meio;
    } else if(v[meio].matricula > matricula) {
        return rec_buscaBinariaPorMatricula(v, ini, meio - 1, matricula);
    } else {
        return rec_buscaBinariaPorMatricula(v, meio + 1, fim, matricula);
    }
}

int it_buscaBinariaPorMatricula(Aluno* v, int ini, int fim, int matricula) {
    int meio;
    while(ini <= fim) {
        meio = (ini + fim) / 2;
        comp++;
        if(v[meio].matricula == matricula) {
            return meio;
        } else if(v[meio].matricula > matricula) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return -1;
}