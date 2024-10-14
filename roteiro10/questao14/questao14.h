#ifndef ORDENACAO_PT1
#define ORDENACAO_PT1

typedef struct pessoa{
    int idade;
    char* nome;
}Pessoa;


int getComp();
int getMov();
void setComp(int);
void setMov(int);
Pessoa* criaPessoa();
void liberaPessoa(Pessoa*);
Pessoa* copiaVetor(Pessoa*, int);
void imprimeVetor(Pessoa*, int);
void preencheAleatorio(int*, int, int, int);
void troca(Pessoa*, Pessoa*);
void BubbleSort(Pessoa*, int);
void InsertionSort(Pessoa*, int);
void SelectionSort(Pessoa*, int);
void InsertionDecres(Pessoa*, int);
void SelectionDecres(Pessoa*, int);


#endif