#ifndef _ORDENACAO_EXTERNA_
#define _ORDENACAO_EXTERNA_

#define N 100

typedef struct sArq{
	FILE *f;
	int pos, max, *buffer;
}Arquivo;

void criaArquivoTeste(char* nome, int ini, int fim);
void troca(int* a, int *b);
int particao(int *v, int ini, int fim);
void QuickSort(int *v, int ini, int fim);
void salvaArquivo(char *nome, int *v, int tam, int mudaLinhaFinal);
int criaArquivosOrdenados(char *nome);
void preencheBuffer(Arquivo* arq, int T);
int procuraMenor(Arquivo* arq, int K, int T, int* menor);
void multiWayMerge(char *nome, int K, int T);
void MergeSortExterno(char* nome);

#endif