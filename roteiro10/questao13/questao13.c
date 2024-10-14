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
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void BubbleSort(int *v, int n){
    int i, j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
			 comp++;
             if (v[j]>v[j+1]) {
                 troca(&v[j], &v[j+1]);
				 mov++;
             }
        }
}

void BubbleSort2(int *v, int n){
    int j, continua, fim = n;
    do{
        continua = 0;
        for(j=0; j < fim-1; j++){
			 comp++;
             if (v[j]>v[j+1]) {
                 troca(&v[j], &v[j+1]);
				 mov++;
                 continua = j;
             }
        }
        fim--;
    }while(continua != 0);
}

void InsertionSort(int *v, int n){
  int i, j, atual;
  for(i=1; i < n; i++){
    atual = v[i];
    comp++;
    for(j=i; (j>0) && (atual < v[j-1]); j--){
       v[j] = v[j-1];
       comp++;
       mov++;
    }
    v[j] = atual;
  }
}

void SelectionSort(int *v, int n){
  int i, j, menor;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
       comp++;
       if (v[j] < v[menor]) 
         menor = j;
    }
    if(i != menor){
      troca(&v[i], &v[menor]);
      mov++;
    }
  }
}