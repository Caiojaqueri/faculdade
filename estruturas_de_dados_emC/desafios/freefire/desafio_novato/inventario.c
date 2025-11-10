// criação de um sistema de inventario para melhor estratégia para o jogo freefire

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

//Vetor global de itens e variávem para controlar o número total de itens
struct Item mochila[MAX_ITENS];
int totalItens = 0;

//função para cadastrar um novo item
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila está cheia!\n");
        return;
    }

    struct Item novoItem;
    printf("\n--- Cadastro de Item ---\n");
    printf("Nome: ");
    scanf("%s", novoItem.nome);

    printf("Tipo: ");
    scanf("%s", novoItem.tipo);

    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);

    mochila[totalItens] = novoItem;
    totalItens++;
    
}