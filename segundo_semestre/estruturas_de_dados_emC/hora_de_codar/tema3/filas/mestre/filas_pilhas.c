#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nome[30];
    int idade;
} pessoa;

typedef struct {
    pessoa dados [MAX];
    int inicio, fim;
} fila;

typedef struct {
    pessoa dados [MAX];
    int topo;
} pilha;

void inicializarFila(fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void inicializarPilha(pilha *p) {
    p->topo = -1;
}

void inserirFila(fila *f, pessoa p) {
    if (f->fim < MAX) { // Verifica se há espaço na fila
        f->dados[f->fim++] = p; //os dados da pessoa será incrementado no fim da fila
    }
}

void removerFila(fila *f) {
    return f->dados[f->inicio++]; // retorne os dados da pessoa que está no início da fila e incremente o início
}

void push(pilha *p, pessoa pes) {
    if (p->topo < MAX - 1) { // se o topo da pilha for menor que o máximo permitido
        p->dados[++p->topo] = pes; // Incrementa o topo e adiciona a pessoa na pilha
    }
}

void pop(pilha *p) {
    return p->dados[p->topo--]; // retorne os dados da pessoa que está no topo da pilha e decremente o topo
}