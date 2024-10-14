#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao13.h"

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes

int getComp(){
    return comp;
}

int getMov(){
    return mov;
}

void setComp(int valor){
    comp = valor;
}

void setMov(int valor){
    mov = valor;
}

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}

void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++){
        v[i] = ini + rand() % (fim-ini + 1); 
        //v[i] = (n-i); //Para o pior caso
    }
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        if(filho < fim)
            if(v[filho] < v[filho+1])
                filho++;
        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
        }else filho = fim + 1;
    }
    v[pai] = aux;
}

void HeapSort(int *v, int n){
    int i;
    for(i=(n-1)/2; i>=0; i--)
        criaHeap(v, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        criaHeap(v, 0, i-1);
    }
}

void Merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    //Vetor Auxiliar - A
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] < v[j]){ A[k] = v[i]; i++; }
        else { A[k] = v[j]; j++; }
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++) v[i] = A[k];
    free(A);
}

void MergeSort(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        comp++;
        while(v[i] < pivo){ i++; comp++; } //procura algum >= pivo do lado esquerdo
        
        comp++;
        while(v[j] > pivo){ j--; comp++;} //procura algum <= pivo do lado direito
        
        if(i<j){
            troca(&v[i], &v[j]); //troca os elementos encontrados
            mov++;
            i++;
            j--;
        }else
            return j; //retorna o local onde foi feita a particao
    }    
}

void QuickSort(int *v, int ini, int fim, int n){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        //printf("Parts: (%d, %d) e (%d, %d): ", ini, q, q+1, fim);
        //imprimeVetor(v, n);
        QuickSort(v, ini, q, n);
        QuickSort(v, q+1, fim, n);
    }
}