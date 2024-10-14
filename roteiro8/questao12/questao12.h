#ifndef ABP_H_ALUNO_
#define ABP_H_ALUNO_

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char* nome;
    int matricula;
    double nota;
}Aluno;

typedef struct NO{
    Aluno *aluno;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO();
void liberarNO(NO* q);
ABP* criaABP();
Aluno* criaAluno();
void destroiRec(NO* no);
void destroiABP(ABP* raiz);
int estaVazia(ABP* raiz);
int insereRec(NO** raiz, Aluno *aluno);
int insereIte(NO** raiz, Aluno *aluno);
int insereElem(ABP* raiz, Aluno *aluno);
int pesquisaRec(NO** raiz, Aluno *aluno);
int pesquisaIte(NO** raiz, Aluno *aluno);
int pesquisa(ABP* raiz, Aluno *aluno);
int removeRec(NO** raiz, Aluno *aluno);
NO* removeAtual(NO* atual);
int removeIte(NO** raiz, Aluno *aluno);
int removeElem(ABP* raiz, Aluno *aluno);
void em_ordem(NO* raiz, int nivel);
void pre_ordem(NO* raiz, int nivel);
void pos_ordem(NO* raiz, int nivel);
void imprime(ABP* raiz, int tipo);

void aguardaLimpa();
void contador(NO* raiz, int nivel, int *cont);
char* maior_nt(NO* raiz, int nivel, int *maior, char* aluno_maior);
char* menor_nt(NO* raiz, int nivel, int *menor, char* aluno_menor);

#endif