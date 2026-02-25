//remoçao de elementos e nós em listas encadeadas

#include <stdio.h>

struct No {
    int dado;
    struct No* proximo;
};

void removerDoInicio(struct No** inicio) {
    //primeiro chequamos se a lista não esta vazia 
    if(inicio == NULL || *inicio == NULL ) {
        printf("A lista já está vazia. Nada a remover.\n");
        return;
    }

    //guardamos o endereço do nó que vamos remover 
    struct No* noParaRemover = *inicio;

    //o início da lista agora passa a ser o segundo nó 
    //o ponteiro inicio passa a apontar para o nó ao que será removido.
    *inicio = (*inicio)->proximo;

    //liberamos a memória do nó que foi removido da lista 
    free(noParaRemover);
}