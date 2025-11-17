//retirando um elemento da fila
//remoção ocorre no início da fila

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Define o tamanho máximo da fila

typedef int Elemento; // Define o tipo de elemento da fila

//estrutura da fila
typedef struct {
    Elemento itens[MAX]; // Array para armazenar os elementos
    int inicio;         // Índice do início da fila
    int fim;            // Índice do próximo espaço livre
    int total;          // Número atual de elementos na fila
} Fila;


Elemento retirar(Fila *f) {
    Elemento vazio = {-1};           
    // Valor padrão caso a fila esteja vazia

    if (filaVazia(f)) 
        return vazio;      
    // Evita remoção se estiver vazia

    Elemento e = f->itens[f->inicio];    
    // Armazena o item a ser removido

    f->inicio = (f->inicio + 1) % MAX; 
    // Atualiza o índice de início

    f->total--;                          
    // Diminui o total

    return e;                            
    // Retorna o item removido
}