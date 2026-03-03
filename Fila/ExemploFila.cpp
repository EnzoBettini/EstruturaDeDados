//Para criar uma Fila (FIFO - First In, First Out), a l�gica muda: 
//inserimos sempre no fim e removemos sempre no in�cio. Para isso, usamos dois ponteiros auxiliares.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tp_produto {
    int codigo;
    char nome[100];    
    struct tp_produto *prox;
};

typedef struct tp_produto Produto;

// Ponteiros para controlar as extremidades da fila
Produto *inicio = NULL;
Produto *fim = NULL;

// Inser��o (Enqueue): Entra pelo fim
void inserir(int cod, const char n[]) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    novo->codigo = cod;
    strcpy(novo->nome, n);
    novo->prox = NULL; // O �ltimo elemento sempre aponta para NULL

    if (inicio == NULL) {
        inicio = novo; // Se for o primeiro, � in�cio e fim ao mesmo tempo
    } else {
        fim->prox = novo; // O antigo fim aponta para o novo
    }
    fim = novo; // Atualiza o ponteiro fim para o novo elemento
    printf("Inserido na fila: %s\n", n);
}

// Remo��o (Dequeue): Sai pelo in�cio
void remover() {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    Produto *aux = inicio; // Guarda o in�cio para liberar depois
    printf("Removendo da fila: %s\n", aux->nome);
    
    inicio = inicio->prox; // O in�cio agora � o segundo da fila
    
    if (inicio == NULL) {
        fim = NULL; // Se a fila esvaziou, o fim tamb�m fica nulo
    }
    
    free(aux); // Deleta o elemento que saiu
}

int main() {
    // Ilustra��o das opera��es
    inserir(10, "Sofa");
    inserir(20, "Mesa");
    inserir(30, "Cadeira");

    printf("\nEstado: O primeiro a sair ser� o Arroz (FIFO)\n\n");

    remover(); // Remove Arroz
    remover(); // Remove Feij�o

    return 0;
}

