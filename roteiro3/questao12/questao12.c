#include <stdio.h>
#include <stdlib.h>
#include "questao12.h"

/* Funcao que retorna o tamanho do lado A do cubo  */
float tamanhoLadoA(Cubo *cubo){
    return cubo->ladoA;
}

/* Funcao que retorna o tamanho do lado B do cubo  */
float tamanhoLadoB(Cubo *cubo){
    return cubo->ladoB;
}

/* Funcao que retorna o tamanho do lado C do cubo */
float tamanhoLadoC(Cubo *cubo){
    return cubo->ladoC;
}

/* Funcao que retorna a area da superficie do cubo */
float area(Cubo *cubo){
    float areaAB = cubo->ladoA * cubo->ladoB;
    float areaAC = cubo->ladoA * cubo->ladoC;
    float areaBC = cubo->ladoB * cubo->ladoC;
    return 2*areaAB + 2*areaAC + 2*areaBC; 
}

/* Funcao que retorna o volume do cubo */
float volume(Cubo *cubo){
    return cubo->ladoA * cubo->ladoB * cubo->ladoC;
}

void main(){
   Cubo *c = (Cubo*)malloc(sizeof(Cubo));
   printf("Digite os lados do cubo:\n");
   scanf("%f %f %f",&c->ladoA,&c->ladoB,&c->ladoC);
   printf("O tamanho do lado A eh: %f\n",tamanhoLadoA(c));
   printf("O tamanho do lado B eh: %f\n",tamanhoLadoB(c));
   printf("O tamanho do lado C eh: %f\n",tamanhoLadoC(c));
   printf("A area da superficie do cubo eh: %f\n",area(c));
   printf("O volume do cubo eh: %f\n",volume(c));
}