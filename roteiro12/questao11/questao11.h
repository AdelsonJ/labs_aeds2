#ifndef _PESQUISA_
#define _PESQUISA_

int getComp();
void setComp(int valor);
int* copiaVetor(int* v, int n);
void imprimeVetor(int* v, int n);
void preencheAleatorio(int* v, int n, int ini, int fim);
void troca(int* a, int *b);
int buscaSequencial(int *v, int n, int elem);
int particao(int *v, int ini, int fim);
void QuickSort(int *v, int ini, int fim);
int rec_buscaBinaria(int *v, int ini, int fim, int elem);
int it_buscaBinaria(int *v, int ini, int fim, int elem);

#endif