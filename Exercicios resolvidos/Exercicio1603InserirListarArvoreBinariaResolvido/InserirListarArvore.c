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
	imprimir(n->dir);
	printf("\n Valor: %d\n",n->valor);
	imprimir(n->esq);
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

int existe(Nodo *n, int valor)
{
	if(n == NULL)
		return 0;
	if(valor == n->valor)
		return 1;
	if(valor < n->valor)
		return existe(n->esq, valor);
	return existe(n->dir, valor);
}

int quantidade(Nodo *n)
{
	if(n == NULL)
		return 0;
	return 1 + quantidade(n->esq) + quantidade(n->dir);
}

int maior(Nodo *n)
{
	if(n->dir == NULL)
		return n->valor;
	return maior(n->dir);
}

int soma(Nodo *n)
{
	if(n == NULL)
		return 0;
	return n->valor + soma(n->esq) + soma(n->dir);
}

int main(void) {
	Nodo *raiz = create(5);
	add(raiz,2);
	add(raiz,1);
	add(raiz,8);
	add(raiz,4);
	add(raiz,7);
	add(raiz,3);
	add(raiz,9);
	imprimir(raiz);
	return 0;
}
