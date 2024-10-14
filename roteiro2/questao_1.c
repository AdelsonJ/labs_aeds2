#include <stdio.h>
#include <stdlib.h>

/* Struct da conta bancaria*/
typedef struct conta{
    int numero;
    char* titular;
    double saldo;
}ContaBancaria;


/* Cabecalho */
void criarConta(ContaBancaria* c, int numero, char *titular);
void depositar(ContaBancaria *c, double valor);
void sacar(ContaBancaria *c, double valor);
double consultarSaldo(ContaBancaria *c);
void imprimirInfo(ContaBancaria *c);

/* Funcao que cria uma nova conta bancaria com o numero e titular especificados e inicializa o saldo como zero */
void criarConta(ContaBancaria* c, int numero, char *titular){
    c->numero = numero;
    c->titular = titular;
    c->saldo = 0;
}

/* Funcao que deposita o valor especificado na conta */
void depositar(ContaBancaria *c, double valor){
    c->saldo = c->saldo + valor;
}

/* Funcao que realiza um saque da conta, desde que haja saldo suficiente */
void sacar(ContaBancaria *c, double valor){
    if(c->saldo < valor)
        printf("Saldo insuficiente.\n\n");
    else
        c->saldo = c->saldo - valor;
}

/* Funcao que retorna o saldo atual da conta */
double consultarSaldo(ContaBancaria *c){
    return c->saldo;
}

/* Funcao que imprime as informacoes da conta, incluindo numero, titular e saldo */
void imprimirInfo(ContaBancaria *c){
    printf("\nCONTA BANCARIA\nNumero: %d\nNome do titular: %s\nSaldo: %lf\n",c->numero,c->titular,c->saldo);
}

/* Main */
void main(){
    /* Variaveis que serao usadas */
    int numero, escolha;
    char titular[50];
    double valor;

    /* Interacao com o usuario */
    printf("Digite os dados para o numero da conta e nome do titular, respectivamente\n");
    scanf("%d %s",&numero,titular);

    /* Cria uma conta bancaria e chama a funcao para instanciar seus valores */
    ContaBancaria *c = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    criarConta(c,numero,titular);

    /* Deixa o usuario escolher o que fazer com a conta ate que deseja encerrar parar */
    do{
        /* Interacao com o usuario */
        printf("\nO que deseja fazer:\n1- Realizar Deposito\n2- Realizar Saldo\n3- Consultar Saldo\n4- Imprimir conta bancaria\n0- Sair\n");
        scanf("%d",&escolha);

        /* realiza acao de acordo com a escolha*/
        switch (escolha) {
        case 0:
            break;
        case 1:
            printf("\nDigite o valor do deposito: \n");
            scanf("%lf",&valor);
            depositar(c,valor);
            break;

        case 2:
            printf("\nDigite o valor do saldo: \n");
            scanf("%lf",&valor);
            sacar(c,valor);
            break;

        case 3:
            printf("\nO valor do saldo eh: %f\n", consultarSaldo(c));
            break;

        case 4:
            imprimirInfo(c);
            break;
        
        default:
            printf("Sem gracinhas, digite um numero valido.\n");
            break;
        }
    }while(escolha != 0);
}