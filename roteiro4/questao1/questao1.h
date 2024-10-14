# ifndef LISTA_H
# define LISTA_H
// Bibliotecas ..

# define MAX 100

typedef struct {
    int dados [MAX ];
    int qtd;
} Lista ;


Lista * criaLista ();
void destroiLista (Lista *);
int tamanhoLista (Lista *);
int listaCheia (Lista *);
int listaVazia (Lista *);
int insereFim (Lista *, int);
int insereInicio (Lista *, int);
int removeFim (Lista *);
int removeInicio (Lista *);
int imprimeLista (Lista *);

int Procura(Lista *, int);
int insereOrdenado(Lista *, int);
int removeOrdenado(Lista *, int);
# endif