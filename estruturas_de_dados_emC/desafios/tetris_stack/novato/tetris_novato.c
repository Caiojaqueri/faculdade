// TETRIS STACK - DESAFIO NÍVEL NOVATO 
//simular fila de peças futuras

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5   // tamanho fixo da fila


// Estrutura da peça
typedef struct {
    char nome;   
    int id; 
} Peca;

// Fila de peças
typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;


// Inicializar a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}


// Gerar peça automaticamente
Peca gerarPeca(int id) {
    char tipos[] = {'T', 'O', 'J', 'L', 'Z'};
    int r = rand() % 5;

    Peca p;
    p.nome = tipos[r];
    p.id = id;

    return p;
}


// Enfileirar peça (inserir no fim)
int inserirFila(Fila *f, Peca p) {
    if (f->tamanho == MAX) {
        printf("Fila cheia! Nao e possivel inserir nova peca.\n");
        return 0;
    }

    f->fim = (f->fim + 1) % MAX;
    f->itens[f->fim] = p;
    f->tamanho++;
    return 1;
}


// Desenfileirar peça (jogar peça)
int removerFila(Fila *f, Peca *removida) {
    if (f->tamanho == 0) {
        printf("Fila vazia! Nao ha peca para jogar.\n");
        return 0;
    }

    *removida = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}


// Exibir fila atual
void exibirFila(Fila *f) {
    printf("\nFila de pecas:\n[ ");

    if (f->tamanho == 0) {
        printf("vazia ");
    } else {
        int i = f->inicio;
        for (int c = 0; c < f->tamanho; c++) {
            printf("%c(%d) ", f->itens[i].nome, f->itens[i].id);
            i = (i + 1) % MAX;
        }
    }

    printf("]\n");
}


// Programa principal
int main() {
    Fila fila;
    inicializarFila(&fila);

    srand(time(NULL));

    int idGlobal = 1;
    int opcao;

    // preencher fila inicialmente
    for (int i = 0; i < MAX; i++) {
        inserirFila(&fila, gerarPeca(idGlobal++));
    }

    do {
        exibirFila(&fila);

        printf("\nOpcoes:\n");
        printf("1 - Jogar peca (desenfileirar)\n");
        printf("2 - Inserir nova peca (enfileirar)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Peca removida;
            if (removerFila(&fila, &removida)) {
                printf("Peca jogada: %c(%d)\n", removida.nome, removida.id);
            }
        } 
        else if (opcao == 2) {
            Peca nova = gerarPeca(idGlobal++);
            if (inserirFila(&fila, nova)) {
                printf("Nova peca inserida: %c(%d)\n", nova.nome, nova.id);
            }
        }

    } while (opcao != 0);

    printf("\nEncerrando...\n");
    return 0;
}

