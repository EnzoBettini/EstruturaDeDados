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
	if(n==NULL){
		return;
	}
	printf("\n Valor: %d\n",n->valor);
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

int main(void) {
	Nodo *raiz = create(5);
	add(raiz,2);
	add(raiz,1);
	add(raiz,8);
	add(raiz,4);

	Nodo *nodo5 = raiz;
	Nodo *nodo8 = raiz->dir;

	nodo8->dir = create(10);

	printf("%d\n", nodo5->esq->dir->valor);

	imprimir(nodo5);

	if(nodo8->esq == NULL)
		printf("Vazio\n");

	return 0;
}
