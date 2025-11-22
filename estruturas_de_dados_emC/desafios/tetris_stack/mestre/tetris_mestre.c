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
peca gerarPEca(int *contador) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    peca nova;
    nova.nome = tipos[rand()% 4]; // rand() % 4 para escolher um dos 4 tipos de peças
    nova.id = (*contador)++;
    return nova;
}

// Definição da estrutura da fila
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

int filaVAzia(fila *f) {
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