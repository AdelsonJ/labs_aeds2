# ifndef LSE_H
# define LSE_H

typedef struct NO{
    int info ;
    struct NO* prox ;
}NO;

typedef struct NO* Lista ;

Lista* criaLista();
int listaVazia(Lista *);
NO* alocarNO();
void liberarNO(NO* );
int insereIni(Lista*, int);
int insereFim(Lista*, int);
int removeIni(Lista *);
int removeFim(Lista *);
void imprimeLista(Lista *);
void destroiLista(Lista *);

int Tamanho(Lista *);
int Procura(Lista *, int );

# endif