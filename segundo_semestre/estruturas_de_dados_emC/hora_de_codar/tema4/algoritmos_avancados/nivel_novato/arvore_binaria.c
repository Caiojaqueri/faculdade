//implementação de árvore binária em c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(const char* valor) {
    No* novo = (No*)malloc(sizeof(No)); // aloca memória para um novo nó
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1); //encerra o programa caso a alocação falhe 
    }
    strcpy(novo->valor, valor); // copia o valor para o nó
    novo->esquerda = NULL; // inicializa o filho esquerdo como NULL
    novo->direita = NULL; // inicializa o filho direito como NULL
    return novo; // retorna o novo nó
}

No* inserir(No* raiz, const char* valor) {
    if (raiz == NULL) {
        return criarNo(valor); // se a árvore estiver vazia, cria um novo nó
    }
    if (strcmp(valor, raiz->valor) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere na subárvore esquerda
    } else {
        raiz->direita = inserir(raiz->direita, valor); // insere na subárvore direita
    }
    return raiz; // retorna a raiz da árvore
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->valor); // visita o nó raiz
        preOrdem(raiz->esquerda); // visita a subárvore esquerda
        preOrdem(raiz->direita); // visita a subárvore direita
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda); // visita a subárvore esquerda
        printf("%s ", raiz->valor); // visita o nó raiz
        emOrdem(raiz->direita); // visita a subárvore direita
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda); // visita a subárvore esquerda
        posOrdem(raiz->direita); // visita a subárvore direita
        printf("%s ", raiz->valor); // visita o nó raiz
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); // libera a subárvore esquerda
        liberarArvore(raiz->direita); // libera a subárvore direita
        free(raiz); // libera o nó atual
    }
}

int main() {
    No* raiz = NULL; // inicializa a árvore como vazia

    raiz = inserir(raiz, "Hall de Entrada");
    raiz = inserir(raiz, "Sala de Estar");
    raiz = inserir(raiz, "Cozinha");
    raiz = inserir(raiz, "Quarto");

    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    liberarArvore(raiz); // libera a memória alocada pela árvore

    return 0;

}
