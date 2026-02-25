#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5      // tamanho da fila de peças
#define TAM_PILHA 3     // tamanho da pilha reserva 


typedef struct {
    char nome;  
    int id;    
} Peca;

// Função para gerar uma nova peça aleatória
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = id;
    return p;
}

typedef struct {
    Peca itens[TAM_FILA];
    int ini, fim;
} Fila;

void inicializarFila(Fila *f) {
    f->ini = 0;
    f->fim = 0;
}

int filaCheia(Fila *f) {
    return (f->fim + 1) % TAM_FILA == f->ini;
}

int filaVazia(Fila *f) {
    return f->ini == f->fim;
}

void enfileirar(Fila *f, Peca p) {
    if (!filaCheia(f)) {
        f->itens[f->fim] = p;
        f->fim = (f->fim + 1) % TAM_FILA;
    }
}

Peca desenfileirar(Fila *f) {
    Peca p = f->itens[f->ini];
    f->ini = (f->ini + 1) % TAM_FILA;
    return p;
}

typedef struct {
    Peca itens[TAM_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == TAM_PILHA - 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, Peca x) {
    if (!pilhaCheia(p)) {
        p->itens[++p->topo] = x;
    }
}

Peca pop(Pilha *p) {
    return p->itens[p->topo--];
}

void exibirEstado(Fila *f, Pilha *p) {
    printf("\n====== ESTADO ATUAL ======\n");

    printf("Fila de peças: [");
    int i = f->ini;
    while (i != f->fim) {
        printf(" %c %d ", f->itens[i].nome, f->itens[i].id);
        i = (i + 1) % TAM_FILA;
        if (i != f->fim) printf("|");
    }
    printf(" ]\n");

    printf("\nPilha de reserva: (Topo -> Base): [");
    for (int i = p->topo; i >= 0; i--) {
        printf(" %c %d ", p->itens[i].nome, p->itens[i].id);
        if (i != 0) printf("|");
    }
    printf(" ]\n\n");
}

int main() {
    srand(time(NULL));

    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int contadorIDs = 1;

    // Preencher fila inicialmente
    while (!filaCheia(&fila)) {
        enfileirar(&fila, gerarPeca(contadorIDs++));
    }

    int opcao;

    do {
        exibirEstado(&fila, &pilha);

        printf("Opções:\n");
        printf("1 - Jogar peça\n");
        printf("2 - Reservar peça\n");
        printf("3 - Usar peça reservada\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:  // Jogar peça
                if (!filaVazia(&fila)) {
                    desenfileirar(&fila);
                    enfileirar(&fila, gerarPeca(contadorIDs++));
                }
                break;

            case 2:  // Reservar peça
                if (!filaVazia(&fila) && !pilhaCheia(&pilha)) {
                    Peca p = desenfileirar(&fila);
                    push(&pilha, p);
                    enfileirar(&fila, gerarPeca(contadorIDs++));
                }
                break;

            case 3:  // Usar reserva
                if (!pilhaVazia(&pilha)) {
                    pop(&pilha);
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
