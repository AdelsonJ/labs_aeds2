#ifndef HASH_H
#define HASH_H

typedef struct{
    int **tabela;
    int tam, qtd;
}Hash;


Hash* criaHash(int t);
void destroiHash(Hash *h);
void preencheAleatorio(int* v, int n, int ini, int fim);
int chaveDivisao(int chave, int tam);
int chaveMultiplicacao(int chave, int tam);
int chaveDobra(int chave, int tam);
int valorString(char *str);
int insereHash_semTratar(Hash* h, int elem);
int buscaHash_semTratar(Hash* h, int elem, int *p);
int sondagemLinear(int pos, int i, int tam);
int sondagemQuadratica(int pos, int i, int tam);
int sondagemDuploHash(int H1, int chave, int i, int tam);
int escolheSondagem(int pos, int i, int tam, int opcao);
int insereHash_EnderAberto(Hash *h, int elem, int opcaoSondagem);
int buscaHash_EnderAberto(Hash *h, int elem, int *p, int opcaoSondagem);
void imprimeHash(Hash *h);

#endif