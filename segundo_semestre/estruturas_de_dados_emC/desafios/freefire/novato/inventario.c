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

    //se o total de idens for maior ou igual ao maximo de itens
    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila está cheia!\n");
        return;
    }

    //cadastre o novo item
    struct Item novoItem;
    printf("\n--- Cadastro de Item ---\n");
    printf("Nome: ");
    scanf("%s", novoItem.nome);

    printf("Tipo: ");
    scanf("%s", novoItem.tipo);

    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);

    //va adicionando na mochila
    mochila[totalItens] = novoItem;
    totalItens++;
    
    printf("\nItem cadastrado com sucesso!\n");
}

//remover um item 
void removerItem() {

    //se o total de itens for igual a zero
    if (totalItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    //qual item sera removido
    char nomeRemover[30];
    printf("\n --- Remocao de item --- \n");
    printf("Digite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    //procurar, comparar o item que sera removido com os itens que ja tem na mochila
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {

            //substitui o item removido pelo ultimo 
            mochila[i] = mochila[totalItens - 1];
            totalItens--;
            printf("\nItem removido com sucesso!\n", nomeRemover);
            return;
        }
    }
    printf("\nItem nao encontrado.\n");
}

//listar itens da mochila
void listarItens() {
    printf("\n --- Itens da mochila --- \n");
    if (totalItens == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    //para todos os itens de um a um ++, liste 
    for (int i = 0; i < totalItens; i ++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

//função principal main()
int main() {

    //opcao do usuário
    int opcao;

    //faça
    do {
        printf("\n==========================\n");
        printf("   SISTEMA DE INVENTÁRIO\n");
        printf("===========================\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", opcao);

        //troque opcao
        switch (opcao) {
            case 1://caso a opcao for 1 faça a função inserirItem()
                inserirItem();
                break;

            case 2:
                removerItem();
                break;

            case 3:
                listarItens();
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}