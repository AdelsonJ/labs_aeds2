#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct do produto*/
typedef struct produto{
    char* nome;
    double preco;
    int quantidade;
}Produto;

/* Struct Catalogo */
typedef struct catalogo{
    Produto p[100];
    int quant_produtos;
} CatalogoProdutos;


/* Cabecalho */
void criarCatalogo(CatalogoProdutos *c);
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade);
int verificarEstoque(CatalogoProdutos *c, char *nome);
void imprimirCatalogo(CatalogoProdutos *c);

/* Funcao que cria um catalogo vazio, zerando o total de produtos. */
void criarCatalogo(CatalogoProdutos* c){
    for(int i = 0; i < 100;i++){
        c->p[i].nome = NULL;
        c->p[i].preco = 0;
        c->p[i].quantidade = 0;
    }
    c->quant_produtos = 0;
}

/* Funcao que adiciona um novo produto ao catalogo. */
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    int aux = c->quant_produtos;

    c->p[aux].nome = (char*)malloc(strlen(nome) + 1);

    strcpy(c->p[aux].nome, nome);
    c->p[aux].preco = preco;
    c->p[aux].quantidade = quantidade;
    c->quant_produtos ++;
}

/* Funcao que verifica a quantidade em estoque de um produto. */
int verificarEstoque(CatalogoProdutos *c, char *nome){
    for(int i = 0; i < c->quant_produtos;i++){
        if(!strcmp(nome,c->p[i].nome))
            return c->p[i].quantidade;
    }
    return -1;
}

/* Funcao que imprime todas as informacoes dos produtos no catalogo */
void imprimirCatalogo(CatalogoProdutos *c){
    for(int i = 0; i < c->quant_produtos;i++){
        printf("\nPRODUTO %d\nNome: %s\nPreco %lf\nQuantidade: %d\n",i+1,c->p[i].nome,c->p[i].preco,c->p[i].quantidade);
    }
}


/* Main */
void main(){
    /* Variaveis que serao usadas */
    int escolha, quantidade;
    char nome[50];
    double preco;

    /* Instancia o Catalogo*/
    CatalogoProdutos *c = (CatalogoProdutos*)malloc(sizeof(CatalogoProdutos));

    /* Deixa o usuario escolher o que fazer com a conta ate que deseja encerrar parar */
    do{
        /* Interacao com o usuario */
        printf("\nO que deseja fazer:\n1- Criar novo Produto\n2- Verificar Estoque\n3- Imprimir conta bancaria\n0- Sair\n");
        scanf("%d",&escolha);


        /* realiza acao de acordo com a escolha*/
        switch (escolha) {
        case 0:
            break;
        case 1:
            /* Interacao com o usuario */
            printf("\nDigite os dados para o nome, o preco e a quantidade do produto, respectivamente\n");
            scanf("%s %lf %d",nome,&preco,&quantidade);
            adicionarProduto(c,nome,preco,quantidade);
            break;

        case 2:
            printf("\nDigite o nome que deseja saber a quantidade em estoque\n");
            scanf("%s",nome);
            quantidade = verificarEstoque(c,nome);
            if(quantidade == -1)
                printf("\nProduto nao encontrado");
            else
                printf("\nA quantidade do produto %s em estoque eh: %d\n", nome, quantidade);
            break;

        case 3:
            imprimirCatalogo(c);
            break;
        
        default:
            printf("\nSem gracinhas, digite um numero valido.\n");
            break;
        }
    }while(escolha != 0);
}