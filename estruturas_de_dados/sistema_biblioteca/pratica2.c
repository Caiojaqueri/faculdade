//===========================================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 2
// OBJETIVO:
// Adicionar a funcionalidade de empréstimo e introduxir alocação dinâmina.
// - os arrays de livros e emprestimos são alocados com malloc/calloc.
// - nova struct para empréstimo.
// - liberação de memória free.
//===========================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100 //capacidade de emprestimos

//definição das estruturas
//struct livro agora tem um campo 'disponivel' para controlar o status

struct livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; //1 para sim, 0 para não
};

//Nova struct pata armazenar os empréstimos
struct emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função Principal
int main(){
    //1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
    //agora em vez de arrays estáticos, usamos ponteiros.
    struct livro *biblioteca;
    struct emprestimo *emprestimos;

    //usamos calooc para o array de livro
    biblioteca = (struct livro *) calloc(MAX_LIVROS, sizeof(struct livro));
}
