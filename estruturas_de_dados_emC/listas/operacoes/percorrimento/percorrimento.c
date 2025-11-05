//percorrimento de listas encadeadas

#include <stdio.h>

struct No {
    int dado;
    struct No* proximo;
};

void listar(struct No* inicio) {
    //criamos um ponteiro viajante que começa no inicio 
    struct No* atual = inicio;

    //se a lista estiver vazia, informamos ao usuário.
    if(atual == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Elementos da lista: \n");

    //enquanto nosso viajante não chega ao fim (null)
    while(atual != NULL) {
        //mostramos o dado do nó onde ele está
        printf("%d\n", atual->dado);

        //e fazemos ele pular prar o proximo nó
        atual = atual->proximo;
    }
}