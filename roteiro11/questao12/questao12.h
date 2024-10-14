#ifndef ORDENACAO_PT2
#define ORDENACAO_PT2

int* copiaVetor(int* v, int n);
void imprimeVetor(int* v, int n);
void preencheAleatorio(int* v, int n, int ini, int fim);
void troca(int* a, int *b);
void criaHeap(int *v, int pai, int fim);
void HeapSort(int *v, int n);
void Merge(int *v, int ini, int meio, int fim);
void MergeSort(int *v, int ini, int fim);
int particao(int *v, int ini, int fim);
void QuickSort(int *v, int ini, int fim, int n);
int getComp();
int getMov();
void setComp(int valor);
void setMov(int valor);

#endif