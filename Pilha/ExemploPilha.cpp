#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tp_produto {
    int codigo;
    char nome[100];    
    struct tp_produto *prox;
};

typedef struct tp_produto Produto;

// O topo da pilha sempre começa como NULL
Produto *topo = NULL;

// Inserção (Push): O novo elemento vira o novo topo
void empilhar(int cod, char n[]) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    novo->codigo = cod;
    strcpy(novo->nome, n);
    
    novo->prox = topo; // O novo aponta para quem era o topo antes
    topo = novo;       // O topo agora aponta para o novo elemento
    printf("Inserido: %s\n", n);
}

// Remoção (Pop): Remove sempre quem está no topo
void desempilhar() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    Produto *aux = topo; // Guarda o endereço do topo atual
    printf("Removendo: %s\n", aux->nome);
    
    topo = topo->prox;   // O topo passa a ser o elemento de baixo
    free(aux);           // Libera a memória do elemento removido
}

int main() {
    // Ilustração das operações
    empilhar(1, "Teclado");
    empilhar(2, "Mouse");
    empilhar(3, "Monitor");

    printf("\nEstado atual: O Monitor esta no topo (LIFO)\n\n");

    desempilhar(); // Remove o Monitor
    desempilhar(); // Remove o Mouse
    
    return 0;
}

//LIFO (Last In, First Out): Note que o "Monitor" foi o último a entrar e seria o primeiro a ser removido.
//novo->prox = topo: Esta linha é o "coração" da pilha; ela garante que o novo elemento segure a mão do elemento que estava abaixo dele.
//free(aux): Essencial para evitar que a memória do computador fique cheia de dados inúteis após a remoção.

