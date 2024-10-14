#include <stdio.h>

/* Cabecalho */
void ordena(char[], int );
void imprimeVetor(char[], int);


/* Funcao que ordena o vetor de forma descrescente*/
void ordena(char vetor[], int tamanho){
    int posicao_do_maior = 0;
    char aux = 0; 
    for(int i = 0; i < tamanho; i++){
        posicao_do_maior = i;

        for (int j= i+1; j < tamanho;j++){
            if(vetor[j] > vetor[posicao_do_maior])
                posicao_do_maior = j;
        }

        if(i != posicao_do_maior){
            aux = vetor[i];
            vetor[i] = vetor[posicao_do_maior];
            vetor[posicao_do_maior] = aux; 
        }

    }    
}

/* Funcao que imprime o vetor */
void imprimeVetor(char vetor[], int tamanho){
    if(tamanho != 0)
        imprimeVetor(vetor, tamanho-1);
    printf("%c  ", vetor[tamanho-1]);
}

void main(){
    char vetor[5] = {'a','f','r','d','e'};
    
    printf("Vetor de letras:");
    imprimeVetor(vetor, 5);
    printf("\n");

    ordena(vetor, 5);
    
    printf("Vetor de letras do maior para o menor:");
    imprimeVetor(vetor, 5);
    printf("\n");
}