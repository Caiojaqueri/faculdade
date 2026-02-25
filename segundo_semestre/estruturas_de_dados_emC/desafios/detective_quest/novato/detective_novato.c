// DESAFIO NÍVEL NOVATO - DETECTIVE QUEST
// CRIAÇÃO DE UM AMBIENTE SIMPLES DE INVESTIGAÇÃO 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura das salas
typedef struct sala {
    char nome[50];
    struct sala* esquerda;
    struct sala* direita;
} sala;

//função criar sala
sala* criarSala(char* nome) {
    sala* nova = (sala*)malloc(sizeof(sala));
    if (!nova) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

//função de navegação das salas
void explorarSalas(sala* atual) {
    char escolha;

    while (1) {
        printf("Você está na sala: %s\n", atual->nome);
        printf("Para onde deseja ir? | e: esquerda | d: direita | s: sair | : ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Saindo da investigação.\n");
            break;
        } else {
            printf("Movimento inválido! Tente novamente.\n");
        }
    }
}

int main() {
    // Criando as salas
    sala* hall = criarSala("Hall de Entrada");
    sala* salaEstar = criarSala("Sala de Estar");
    sala* cozinha = criarSala("Cozinha");
    sala* quarto = criarSala("Quarto");
    sala* banheiro = criarSala("Banheiro");

    // Montando a árvore binária
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = quarto;
    salaEstar->direita = banheiro;

    // Cozinha é nó folha (não recebe filhos)

    printf("=== Detective Quest — Exploração da Mansão ===\n");
    explorarSalas(hall);

    return 0;
}
