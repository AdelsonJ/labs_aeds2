#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct funcionario {
    char nome[30];
    double salario;
    int anoContratacao;
} Funcionario;

typedef struct no{
    Funcionario info; 
    int fb, alt;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct no* AVL;

NO* alocarFuncionario();
void liberarFuncionario(NO* q);
AVL* criaAVL();
void destroiRec(NO* NO);
void destroiAVL(AVL* raiz);
int estaVazia(AVL* raiz);
int altura(NO* raiz);
int FB(NO* raiz);
void avl_RotDir(NO** raiz);
void avl_RotEsq(NO** raiz);
void avl_RotEsqDir(NO** raiz);
void avl_RotDirEsq(NO** raiz);
void avl_RotEsqDir2(NO** raiz);
void avl_RotDirEsq2(NO** raiz);
void avl_AuxFE(NO **raiz);
void avl_AuxFD(NO **raiz);
int insereRec(NO** raiz, double salario, char *nome, int ano_contratacao);
int insereElem(AVL* raiz, double salario, char *nome, int ano_contratacao);
int pesquisaRec(NO** raiz, double salario);
int pesquisa(AVL* raiz, double salario);
int removeRec(NO** raiz, double salario);
int removeElem(AVL* raiz, double salario);
void em_ordem(NO* raiz, int nivel);
void pre_ordem(NO* raiz, int nivel);
void pos_ordem(NO* raiz, int nivel);
void imprime(AVL* raiz);
void aguardaLimpa();
Funcionario maior(AVL* raiz);
Funcionario menor(AVL* raiz);

#endif