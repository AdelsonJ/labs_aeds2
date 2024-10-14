# include <stdio.h>
# include <stdlib.h>
# include "questao1.h"

Lista * criaLista () {
    Lista *li;
    li = ( Lista *) malloc ( sizeof ( Lista ));
    if(li != NULL )
    li ->qtd = 0;
    return li;
}

void destroiLista ( Lista * li){
    if(li != NULL )
    free (li);
}

int tamanhoLista ( Lista * li){
    if(li == NULL )
    return -1;
    return li -> qtd;
}

int listaCheia ( Lista * li){
    if(li == NULL )
    return -1;
    return (li -> qtd == MAX );
}

int listaVazia ( Lista * li){
    if(li == NULL )
    return -1;
    return (li -> qtd == 0) ;
}


int insereFim ( Lista *li , int elem ){
    if(li == NULL ) return 0;
    if (! listaCheia (li)){
        li -> dados [li ->qtd] = elem ;
        li ->qtd ++;
        printf ("Elemento inserido com sucesso !\n"); return 1;
    } else {
        printf ("Elemento nao inserido - Lista Cheia !\n"); return 0;
    }
}

int insereInicio ( Lista *li , int elem ){
    if(li == NULL ) return 0;

    if (! listaCheia (li)){
        int i;
        for(i=li ->qtd -1; i >=0; i --)
            li -> dados [i +1] = li -> dados [i];
        li -> dados [0] = elem ;
        li ->qtd ++;
        printf ("Elemento inserido com sucesso !\n"); return 1;
    } else {
        printf ("Elemento nao inserido - Lista Cheia !\n"); return 0;
    }
}

int removeFim ( Lista *li){
    if(li == NULL ) return 0;

    if (! listaVazia (li)){
    li ->qtd --;
        printf ("Elemento removido com sucesso !\n"); return 1;
    } else {
        printf (" Nenhumelemento removido - Lista Vazia !\n");
        return 0;
    }
}

int removeInicio ( Lista *li){
    if(li == NULL ) return 0;

    if (! listaVazia (li)){
        int i;
        for(i =0; i<li ->qtd -1; i++)
            li -> dados [i] = li -> dados [i +1];
        li ->qtd --;
        printf ("Elemento removido com sucesso !\n"); return 1;
    } else {
        printf (" Nenhumelemento removido - Lista Vazia !\n"); 
        return 0;
    }
}

int imprimeLista ( Lista * li){
    if(li == NULL ) return 0;

    if( listaVazia (li)){
        printf (" Lista vazia !\n"); return 0;
    }
    printf ("Elementos :\n");
    int i;

    for(i =0; i<li -> qtd; i ++) {
        printf ("%d ", li-> dados [i]) ;
    }

    printf ("\n");
    return 1;
}

int Procura(Lista *li, int  x){
    for(int i =0; i< li->qtd; i++){
        if(x == li->dados[i])
            return i;
    }
    return -1;
}

int insereOrdenado(Lista *li, int elem){
    if(li == NULL ) return 0;

    int i,j;

    if (! listaCheia (li)){
        if(li->qtd == 0){
            li->dados[0] = elem;
            li->qtd++;
            printf ("Elemento inserido com sucesso !\n"); return 1;
        }
        else{
            for(i = 0; i< li->qtd; i++){
                if(li->dados[i] > elem){
                    for(j = li->qtd-1; j >= i; j--)
                        li -> dados [j + 1] = li -> dados [j];
                    li->qtd++;
                    li->dados[i] = elem;

                    printf ("Elemento inserido com sucesso !\n"); return 1;
                }
            }
        }
    } else {
        printf ("Elemento nao inserido - Lista Cheia !\n"); return 0;
    }
}

int removeOrdenado(Lista *li, int elem){
    if(li == NULL ) return 0;

    int i,j,achou;

    if (! listaVazia (li)){
        achou = Procura(li,elem);
        if(achou != -1){
            for(i = achou; i<li ->qtd -1; i++)
                li -> dados [i] = li -> dados [i+1];
            li->qtd--;
            printf ("Elemento removido com sucesso !\n"); return 1;
        } else
            printf ("Elemento nao removido - Item nao encontrado !\n"); return 0;
        
    } else 
        printf ("Elemento nao removido - Lista Vazia !\n"); return 0;
}