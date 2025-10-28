//=========================================================================
// PRATICA: SISTEMA DE BIBLIOTECA - PARTE 
//
//OBJETIVO: 
// IMplementar o cadastro e a listagem de livros usando um array estático.
// Foco em structs, entrada/saída de dados e organização básica.
//
//=========================================================================


//bibliotecas necessárias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100

//definição da struct Livro
struct Livro {
    char nome [ TAM_STRING ];
    char autor [ TAM_STRING ];
    char editora [ TAM_STRING ];
    int edicao;
};

//Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//função principal 
int main() {
    struct Livro biblioteca [ MAX_LIVROS ];
    int totallivros = 0;
    int opcao;
}