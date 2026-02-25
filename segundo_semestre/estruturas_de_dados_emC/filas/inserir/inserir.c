//inserir elementos, significa coloca-lo ao final da fila.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Define o tamanho máximo da fila

typedef int Elemento; // Define o tipo de elemento da fila
//estrutura da fila

typedef struct {
    Elemento itens[MAX]; // Array para armazenar os elementos
    int fim;            // Índice do próximo espaço livre
    int total;          // Número atual de elementos na fila
} Fila;

//função para inserir um novo nó no final da fila
void inserir(Fila *f, Elemento e) {
    if (filaCheia(f)) // Impede inserção se estiver cheia
        return;

    f->itens[f->fim] = e;            // Insere no final
    f->fim = (f->fim + 1) % MAX;     // Atualiza circularmente o índice
    f->total++;                      // Incrementa a contagem de elementos
}
