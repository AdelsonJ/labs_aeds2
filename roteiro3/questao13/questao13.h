#ifndef __QUESTAO_1_3__
#define __QUESTAO_1_3__

/* struct do conjunto de inteiros*/
typedef struct conjunto_de_inteiros{
    int *elemento;
    int tamanho;
}Conjunto;

/* funcoes da questao*/
Conjunto* criaConjunto();
Conjunto* uniao(Conjunto *, Conjunto *);
void insereElemento(Conjunto *, int);
void removeElemento(Conjunto *, int);
Conjunto* interseccao(Conjunto *, Conjunto *); 
Conjunto* diferenca(Conjunto *, Conjunto *);
int pertence(Conjunto *, int);
int menor(Conjunto *);
int maior(Conjunto *);
int ehigual(Conjunto *, Conjunto *);
int tamanho(Conjunto *);
int ehvazio(Conjunto *);
/* funcao extra*/
void imprimeConjunto(Conjunto *);
void libera(Conjunto *);
int compara(const void *a, const void *b);
void aguardaLimpa();

#endif