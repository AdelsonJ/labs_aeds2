#ifndef __QUESTAO_1_2__
#define __QUESTAO_1_2__

/* strcut cubo*/
typedef struct cubo{
    float ladoA;
    float ladoB;
    float ladoC;
}Cubo;

/* funcoes da questao*/
float tamanhoLadoA(Cubo *cubo);
float tamanhoLadoB(Cubo *cubo);
float tamanhoLadoC(Cubo *cubo);
float area(Cubo *cubo);
float volume(Cubo *cubo);

#endif