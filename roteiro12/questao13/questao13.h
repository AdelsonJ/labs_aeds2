#ifndef _PESQUISA_ALUNO_
#define _PESQUISA_ALUNO_

typedef struct aluno{
    char nome[50];
    int matricula;
    float notas[3];
} Aluno;

int getComp();
void setComp(int valor);
Aluno* criaAluno(int n);
Aluno* copiaAluno(Aluno* a);
void imprimeAluno(Aluno* a);
void trocaAluno(Aluno* a, Aluno* b);
void QuickSortAluno(Aluno* v, int ini, int fim);
int particaoAluno(Aluno* v, int ini, int fim);// ...

int buscaSequencialPorNome(Aluno* v, int n, const char* nome);
int rec_buscaBinariaPorNome(Aluno* v, int ini, int fim, const char* nome);
int it_buscaBinariaPorNome(Aluno* v, int ini, int fim, const char* nome);

int buscaSequencialPorMatricula(Aluno* v, int n, int matricula);
int rec_buscaBinariaPorMatricula(Aluno* v, int ini, int fim, int matricula);
int it_buscaBinariaPorMatricula(Aluno* v, int ini, int fim, int matricula);

#endif