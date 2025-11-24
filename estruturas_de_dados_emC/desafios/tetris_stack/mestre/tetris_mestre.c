// DESAFIO TERISNSTACK - NÍVEL MESTRE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5
#define TAM_PILHA 3

typedef struct {
    char nome;
    int id;
} peca;

//função para gerar peças aleatórias
peca gerarPeca(int *contador) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    peca nova;
    nova.nome = tipos[rand()% 4]; // rand() % 4 para escolher um dos 4 tipos de peças
    nova.id = (*contador)++;
    return nova;
}

// estrutura e funções da fila
typedef struct {
    peca itens[TAM_FILA];
    int frente;
    int tras;
    int qtd;
} fila;

void inicializarFila(fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->qtd = 0;
}

int filaVazia(fila *f) {
    return f->qtd == 0;
}

int filaCheia(fila *f) {
    return f->qtd == TAM_FILA;
}

void enfileirar(fila *f, peca p) {
    if (filaCheia(f)) {
        f->itens[f->tras] = p;
        f->tras = (f->tras + 1) % TAM_FILA;
        f->qtd++;
    }
}

peca desenfileirar(fila *f) {
    peca p = {'X', -1}; // peça inválida
    if (filaVazia(f)) return p;
    p = f->itens[f->frente];
    f->frente = (f->frente + 1) % TAM_FILA;
    f->qtd--;
    return p;
}

peca acessarFila(fila *f, int i) {
    int pos = (f->frente + i) % TAM_FILA;
    return f->itens[pos];
}

void alteratFila(fila *f, int i, peca p) {
    int pos = (f->frente + i) % TAM_FILA;
    f->itens[pos] = p;
}


//estrutura e funções da pilha 
typedef struct {
    peca itens[TAM_PILHA];
    int topo;
} pilha;

void inicializarPilha(pilha *p) {
    p->topo = -1;
}

int pilhaVazia(pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(pilha *p) {
    return p->topo == TAM_PILHA - 1;
}   

void push(pilha *p, peca x) {
    if (!pilhaCheia(p)) p->itens[++(p->topo)] = x;
}

peca pop(pilha *p) {
    peca x = {'X', -1}; // peça inválida
    if (pilhaVazia(p)) return x;
    return p->itens[(p->topo)--];
}

void exibirEstado(fila *f, pilha *p) {
    printf("============ ESTADO ATUAL ============\n");

    printf("fila: ");
    for (int i = 0; i < f->qtd; i++) {
        peca pecaAtual = acessarFila(f, i);
        printf("[%c%d] ", pecaAtual.nome, pecaAtual.id);
    }
    printf("\n");

    printf("pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        peca pecaAtual = p->itens[i];
        printf("[%c%d] ", pecaAtual.nome, pecaAtual.id);
    }
    printf("\n=====================================\n");
}

int main() {
    srand(time(NULL));

    fila fila;
    pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int contador = 0;

    //inicializa a fila com 5 peças
    for (int i = 0; i < TAM_FILA; i++) {
        enfileirar(&fila, gerarPeca(&contador));
    }

    int op;
    do {
        exibirEstado(&fila, &pilha);
        printf("============ MENU ============\n");
        printf("1 - Jogar peça da fila\n");
        printf("2 - Reservar peça\n");
        printf("3 - Usar peça da pilhan\n");
        printf("4 - Trocar peça da frente com o topo da pilha\n");
        printf("5 - Trocar múltipla (3 da fila com 3 da pilha)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                //jogar peça (remove da fila e gera nova peça)
                desenfileirar(&fila);
                enfileirar(&fila, gerarPeca(&contador));
                break;
            }

            case 2: {
                //reservar peça 
                if (!pilhaCheia(&pilha)) {
                    push(&pilha, desenfileirar(&fila));
                    enfileirar(&fila, gerarPeca(&contador));
                }
            }

            case 3: {
                //usar peça da pilha
                pop(&pilha);
                break;
            }

            case 4: {
                //trocar peça da pilha com frende da fila 
                if (!pilhaVazia(&pilha)) {
                    peca temp = acessarFila(&fila, 0);
                    alteratFila(&fila, 0, pilha.itens[pilha.topo]);
                    pilha.itens[pilha.topo] = temp;
                }
                break;
            }

            case 5: {
                //trocar múltipla (3 da fila com 3 da pilha)
                if (fila.qtd >= 3 && pilha.topo >= 2) {
                    for (int i = 0; i < 3; i++) {
                        peca temp = acessarFila(&fila, i);
                        alteratFila(&fila, i, pilha.itens[pilha.topo - i]);
                        pilha.itens[pilha.topo - i] = temp;
                    }
                }
                break;
            }

            case 0: 
                printf("Saindo do jogo...\n");
                break;

            default: 
                printf("Opção inválida!\n");
                break;
            
        }
    } while (op != 0);

    return 0;
}
