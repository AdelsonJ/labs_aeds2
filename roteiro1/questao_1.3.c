#include <stdio.h>

/* Struct */
typedef struct aluno{
    char* nome;
    int matricula;
    int nota;
}Aluno;

/* Cabecalho*/
Aluno criaAluno(Aluno);
void maiorNota(Aluno *, int);
void menorNota(Aluno *, int);

/* Funcao que cria um Aluno */
Aluno criaAluno(Aluno aluno){
    aluno.nome = "";
    aluno.matricula = 0;
    aluno.nota = 0;
    return aluno;
}

/* Funcao que imprime os dados do aluno de maior nota*/
void maiorNota(Aluno *aluno, int tamanho){
    Aluno maior = criaAluno(maior);
    for(int i = 0; i < tamanho; i++){
        if(aluno[i].nota > maior.nota)
            maior = aluno[i];
    }
    printf("O aluno %s, de matricula %d, tem a maior nota: %d\n", maior.nome, maior.matricula, maior.nota);
}

/* Funcao que imprime os dados do aluno de menor nota*/
void menorNota(Aluno *aluno, int tamanho){
    Aluno menor = criaAluno(menor);
    menor.nota = 1000000;
    for(int i = 0; i < tamanho; i++){
        if(aluno[i].nota < menor.nota)
            menor = aluno[i];
    }
    printf("O aluno %s, de matricula %d, tem a menor nota: %d\n", menor.nome, menor.matricula, menor.nota);
}

void main(){
    /* Cria alunos*/
    Aluno aluno1 = criaAluno(aluno1);
    aluno1.nome = "Fulano";
    aluno1.matricula = 1;
    aluno1.nota = 9;

    Aluno aluno2 = criaAluno(aluno1);
    aluno2.nome = "Beltrano";
    aluno2.matricula = 2;
    aluno2.nota = 4; 

    Aluno aluno3 = criaAluno(aluno1);
    aluno3.nome = "Ciclano";
    aluno3.matricula = 3;
    aluno3.nota = 10;  

    /* Cria um vetor de alunos*/
    Aluno aluno[3] = {aluno1,aluno2, aluno3};

    maiorNota(aluno,3);
    menorNota(aluno,3);
}
