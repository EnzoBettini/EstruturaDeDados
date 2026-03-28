#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
};

typedef struct nodo Nodo;

Nodo* create(int valor)
{
	Nodo *n = malloc(sizeof *n);
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n)
{
	if(n==NULL)
		return;
	imprimir(n->esq);
	printf("\n%d",n->valor);
	imprimir(n->dir);
}

void add(Nodo *n, int valor)
{
	if(valor < n->valor)
	{
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
	}
	else
	{
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

void rem(Nodo *n, int valor)
{
	Nodo *filho = n;
	Nodo *pai;
	do{
		pai = filho;
		if(valor < filho->valor)
			filho = filho->esq;
		else if(valor > filho->valor)
			filho = filho->dir;
	}while(filho!=NULL && filho->valor != valor);

	if(filho != NULL){
		if(filho->esq == NULL && filho->dir == NULL){
			printf("%d e nodo folha\n",valor);
			if(pai->esq == filho) pai->esq = NULL;
			if(pai->dir == filho) pai->dir = NULL;
			free(filho);
		}
		else if(filho->esq != NULL && filho->dir == NULL){
			printf("%d tem um filho a esquerda\n",valor);
			if(pai->esq == filho) pai->esq = filho->esq;
			if(pai->dir == filho) pai->dir = filho->esq;
			free(filho);
		}
		else if(filho->esq == NULL && filho->dir != NULL){
			printf("%d tem um filho a direita\n",valor);
			if(pai->esq == filho) pai->esq = filho->dir;
			if(pai->dir == filho) pai->dir = filho->dir;
			free(filho);
		}
		else if(filho->esq != NULL && filho->dir != NULL){
			printf("%d tem dois filhos, usando sucessor\n", valor);

			Nodo *paiSucessor = filho;
			Nodo *sucessor = filho->dir;

			while(sucessor->esq != NULL) {
				paiSucessor = sucessor;
				sucessor = sucessor->esq;
			}

			filho->valor = sucessor->valor;

			if (paiSucessor == filho) {
				filho->dir = sucessor->dir;
			}
			else {
				paiSucessor->esq = sucessor->dir;
			}
			free(sucessor);
		}
	}
}

int main(void) {

	Nodo *root = create(5);

	add(root,2);
	add(root,0);
	add(root,1);
	add(root,8);
	add(root,4);

	rem(root,2);
	rem(root,1);
	rem(root,0);
	rem(root,5);

	imprimir(root);

	return 0;
}
