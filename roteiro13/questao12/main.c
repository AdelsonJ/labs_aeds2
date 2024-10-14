#include <stdio.h>
#include "Trie.h"
#include "ArvoreB.h"
#include "Patricia.h"


// Função principal
int main(){
	int escolha, i;

	printf("Digite qual das arvores deseja criar: \n1-ArvoreB \n2-Arvore Patricia \n3-Arvore Trie \n");
	scanf("%d",&escolha);

	switch (escolha){
	case 1:
		ArvoreB *B = criaArvoreB();
		int valores[21] = {20, 10, 40, 50, 30, 55, 3, 11, 4, 28, 36, 33, 52, 17, 25, 13, 45, 9, 43, 8, 48};
		int remover[17] = {45, 30, 28, 50, 8, 10, 4, 20, 40, 55, 17, 33, 11, 36, 3, 9, 52};

		Registro r;
		char c;

		printf("\n\n----Arvore B - INSERCAO:\n");
		for(i=0; i<21; i++){
			r.chave = valores[i];
			insereArvoreB(B, r);
		}  

		printf("\n\n----Arvore B - PESQUISA:\n");
		for(i=0; i<21; i++){
			r.chave = valores[i];
			pesquisaArvoreB(B, &r);
		}

		printf("\n\n----Arvore B - FINAL:\n");
		imprimeArvoreB(B);

		destroiArvoreB(B);
		break;
	
	case 2:
		int valoresLivro[7] = {18, 19, 24, 33, 40, 54, 34};
		//char valoresLivroChar[7] = {'B', 'C', 'H', 'J', 'Q', 'W', 'K'};

		ArvorePat P = NULL;
		int x;

		printf("----------Insercao:\n");
		
		for(i=0; i<7; i++){
			//printf("%d em binario: ", valoresLivro[i]); binary(valoresLivro[i]); printf("\n");
			P = Insere(valoresLivro[i], &P);
			//printf("\n");
		}


		printf("\n\n----------Busca:\n");
		x = 9;
		printf("%d em binario: ", x); binary(x); printf("\n");
		Pesquisa(x, P);
		
		x = 11;
		printf("%d em binario: ", x); binary(x); printf("\n");
		Pesquisa(x, P);


		printf("\n\n----------Impressao FINAL:\n");
		imprimePatricia(P);
		break;

	case 3:
		// Chaves de entrada (use apenas 'a' a 'z' em minusculas)
		char chaves[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
		char saida[][32] = {"Nao encontrada na TRIE", "Encontrada na TRIE"};

		NO *raiz = criaNO();
		// Construir a trie
		for (i = 0; i < 8; i++)
			inserir(raiz, chaves[i]);

		// Buscar por diferentes chaves
		printf("%s --- %s\n", "the", saida[buscar(raiz, "the")]);
		printf("%s --- %s\n", "these", saida[buscar(raiz, "these")]);
		printf("%s --- %s\n", "their", saida[buscar(raiz, "their")]);
		printf("%s --- %s\n", "thaw", saida[buscar(raiz, "thaw")]);

		imprimeTrie(raiz);
		break;

	default:
		printf("Algo de errado não está certo.\n");
		break;
	}

	return 0;
}
