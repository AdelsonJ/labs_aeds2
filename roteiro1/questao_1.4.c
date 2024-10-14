#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Cabecalho */
double delta(float, float, float);
int raizes(float, float, float, float*, float *);

/* Funcao que retorna o delta*/
double delta(float A, float B, float C){
    return B*B - (4*A*C);
}

/* Funcao que retorna as raizes caso elas existam*/
int raizes(float A, float B, float C, float* X1, float * X2){
    double delta_local = delta(A,B,C);

    if(delta_local > 0){
        delta_local = sqrt(delta_local);
        *X1 = (float)((-B + delta_local)/2*A);
        *X2 = (float)(-B - delta_local)/2*A;
        return 2;
    }
    else{
        delta_local = sqrt(delta_local);
        if(delta_local == 0){  
            *X1 =  (float)(-B + delta_local)/2*A;
            *X2 = *X1;
            return 1;
        }
        else 
            return 0;
    }
}

void main(){
    float A = 1;
    float B = 4;
    float C = 0;
    float *X1 = (float*)malloc(sizeof(float));
    float *X2 = (float*)malloc(sizeof(float));

    switch (raizes(A,B,C,X1,X2)){
    case 0:
        printf("Nao ha raizes reais, pois o delta eh menor que 0\n");
        break;
    
    case 1:
        printf("So ha uma raiz real: %f. Isso ocorre devido ao fato de que o delta eh zero e portanto as raizes sao iguais.\n",*X1);
        break;


    case 2:
        printf("As duas raizes reais sao: %f e %f\n",*X1,*X2);
        break;
    default:
        printf("Se chegou aqui deu errado XD\n");
        break;
    }
}