#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao12.h"

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


Aluno* criaAluno(){
    Aluno* aluno = (Aluno*) malloc (sizeof(Aluno));
    if(aluno != NULL){
        aluno->nome = (char*)malloc(30 * sizeof(char));
        aluno->matricula = 0;
        aluno->nota = 0.0;
    }
    return aluno;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}


int insereRec(NO** raiz, Aluno *aluno){
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->aluno = aluno;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo;
    }else{
        int cmp = strcmp(aluno->nome, (*raiz)->aluno->nome);
        if(cmp == 0){
            printf("Aluno Existente!\n"); 
            return 0;
        }
        if(cmp < 0)
            return insereRec(&(*raiz)->esq, aluno);
        else if(cmp > 0)
            return insereRec(&(*raiz)->dir, aluno);
    }
    return 1;
}

int insereIte(NO** raiz, Aluno *aluno){
    NO *aux = *raiz, *ant = NULL;
    while (aux != NULL){
        ant = aux;
        if(aux->aluno->nome == aluno->nome){
            printf("Aluno Existente!\n"); 
            return 0;
        }
        if(aluno->nome < aux->aluno->nome) aux = aux->esq;
        else aux = aux->dir;
    }
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->aluno = aluno;
    novo->esq = NULL; novo->dir = NULL;
    if(ant == NULL){
        *raiz = novo;
    }else{
        if(aluno->nome < ant->aluno->nome) ant->esq = novo;
        else ant->dir = novo;
    }
    return 1;
}

int insereElem(ABP* raiz, Aluno *aluno){
    if(raiz == NULL) return 0;

    Aluno* novoAluno = criaAluno();
    if(novoAluno == NULL) return 0;
    
    strcpy(novoAluno->nome, aluno->nome);
    novoAluno->matricula = aluno->matricula;
    novoAluno->nota = aluno->nota;

    return insereRec(raiz, novoAluno);
}


int pesquisaRec(NO** raiz, Aluno *aluno){
    if(*raiz == NULL) return 0;
    int cmp = strcmp(aluno->nome, (*raiz)->aluno->nome);
    if(cmp == 0){
        printf("O nome do aluno eh: %s\nA matricula do aluno eh: %d"
                "\nA nota do aluno eh: %lf\n", (*raiz)->aluno->nome, 
                (*raiz)->aluno->matricula, (*raiz)->aluno->nota);
        return 1;
    }
    if(cmp < 0)
        return pesquisaRec(&(*raiz)->esq, aluno);
    else 
        return pesquisaRec(&(*raiz)->dir, aluno);
}


int pesquisaIte(NO** raiz, Aluno *aluno){
    NO* aux = *raiz;
    while(aux != NULL){
        if(aux->aluno->nome == aluno->nome) return 1;
        if(aluno->nome < aux->aluno->nome)
            aux = aux->esq;
        else 
            aux = aux->dir;
    }
    return 0;
}

int pesquisa(ABP* raiz, Aluno *aluno){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, aluno);
    //return pesquisaIte(raiz, aluno);
}


int removeRec(NO** raiz, Aluno *aluno){
    if(*raiz == NULL) return 0;
    if(strcmp(aluno->nome, (*raiz)->aluno->nome) == 0){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            printf("Caso 1: Liberando %s..\n", (*raiz)->aluno->nome);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            printf("Caso 2.1: Liberando %s..\n", (*raiz)->aluno->nome);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            printf("Caso 2.2: Liberando %s..\n", (*raiz)->aluno->nome);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            printf("Caso 3: Liberando %s..\n", (*raiz)->aluno->nome);
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->aluno = Filho->aluno;
            Filho->aluno = aluno;
            return removeRec(&(*raiz)->esq, aluno);
        }
        return 1;
    }else if(aluno->nome < (*raiz)->aluno->nome)
        return removeRec(&(*raiz)->esq, aluno);
    else 
        return removeRec(&(*raiz)->dir, aluno);
}

NO* removeAtual(NO* atual){
    NO* no1, *no2;
    //Ambos casos no if(atual->esq == NULL)
    //Caso 1 - NO sem filhos
    //Caso 2.1 - Possui apenas uma subarvore direita
    if(atual->esq == NULL){
        no2 = atual->dir;
        liberarNO(atual);
        return no2;
    }
    //Caso 3 - Possui as duas subarvores (esq e dir)
    //Estrategia: 

    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    liberarNO(atual);
    return no2;
}

int removeIte(NO** raiz, Aluno *aluno){
    if(*raiz == NULL) return 0;
    NO* atual = *raiz, *ant = NULL;
    while(atual != NULL){
        if(strcmp(aluno->nome, atual->aluno->nome) == 0){
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = removeAtual(atual);
                else
                    ant->esq = removeAtual(atual);
            }
            return 1;
        }
        ant = atual;
        if(strcmp(aluno->nome, atual->aluno->nome) < 0)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}


int removeElem(ABP* raiz, Aluno *aluno){
    if(pesquisa(raiz, aluno) == 0){
        printf("Aluno inexistente!\n");
        return 0;
    }
    //return removeRec(raiz, aluno);
    return removeIte(raiz, aluno);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[(%s,%d,%lf), %d] ", raiz->aluno->nome, 
            raiz->aluno->matricula, raiz->aluno->nota,nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        printf("[(%s,%d,%lf), %d] ", raiz->aluno->nome, 
            raiz->aluno->matricula, raiz->aluno->nota,nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("[(%s,%d,%lf), %d] ", raiz->aluno->nome, 
            raiz->aluno->matricula, raiz->aluno->nota,nivel);
    }
}

void imprime(ABP* raiz, int tipo){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    switch (tipo){
    case 0:
        printf("\nEm Ordem: "); em_ordem(*raiz, 0);
        break;

    case 1:
        printf("\nPre Ordem: "); pre_ordem(*raiz, 0);
        break;

    case 2:
        printf("\nPos Ordem: "); pos_ordem(*raiz, 0);
        break;
    default:
        break;
    }
    printf("\n");
}

/* Funcao para esperar resposta do usuario e depois limpar*/
void aguardaLimpa(){
    getchar();
    printf("\n\nAperte qualquer tecla para continuar\n");
    getchar();
    system("clear");
}


char* maior_nt(NO* raiz, int nivel, int *maior, char* aluno_maior){
    if(raiz != NULL){
        maior_nt(raiz->esq, nivel+1, maior, aluno_maior);
        if(*maior < raiz->aluno->nota){
            *maior = raiz->aluno->nota;
            strcpy(aluno_maior, raiz->aluno->nome);
        } 
        maior_nt(raiz->dir, nivel+1, maior, aluno_maior);
    }
    return aluno_maior;
}


char* menor_nt(NO* raiz, int nivel, int *menor, char* aluno_menor){
    if(raiz != NULL){
        menor_nt(raiz->esq, nivel+1, menor, aluno_menor);
        if(*menor > raiz->aluno->nota){
            *menor = raiz->aluno->nota;
            strcpy(aluno_menor, raiz->aluno->nome);
        } 
        menor_nt(raiz->dir, nivel+1, menor, aluno_menor);
    }
    return aluno_menor;
}
