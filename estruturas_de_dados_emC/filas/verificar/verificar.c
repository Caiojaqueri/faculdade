// verificar sem remoção ou inserção de elementos na fila

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Define o tamanho máximo da fila

typedef int Elemento; // Define o tipo de elemento da fila
//estrutura da fila

typedef struct {
    Elemento itens[MAX]; // Array para armazenar os elementos
    int inicio;
    int fim;            // Índice do próximo espaço livre
    int total;          // Número atual de elementos na fila
} Fila;

Elemento espiar(Fila *f) {
    Elemento vazio = {-1};     
     // Valor padrão se a fila estiver vazia

    if (filaVazia(f))
        return vazio;     
    // Impede acesso indevido

    return f->itens[f->inicio];         
    // Retorna o elemento da frente
}