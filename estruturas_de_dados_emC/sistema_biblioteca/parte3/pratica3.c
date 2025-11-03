//=====================================================================
//SISTEMA DE BIBLIOTECA - PARTE 3
//Modularizar o código, passagem por valor e referência.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes globais
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

//estruturas
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo {
    int indieLivro;
    char nomeUsuario[TAM_STRING];
};

//funções definidas aqui para serem chamadas no main
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLiros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

//Função principal main
//onde chamamos as funções que cadastramos, deixando o código mais limpo e organizado 
int main() {
    struct Livro *biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    struct Emprestimo *emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("ERRO: falha ao alocar memoria.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                cadastrarLivro(biblioteca, &totalLivros);
                break;
            
            case 2:
                listarLivros(biblioteca, totalLivros);
                break;

            case 3:
                realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
                break;

            case 4:
                listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
                break;
            
            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
            printf("\nOpcap invalida! Pressione Enter para tentar novamente.");
            getchar();
            break;
        }
    } while (opcao != 0);

    //chama função para liberar memoria
    liberarMemoria(biblioteca, emprestimos);

    return 0;
}

//IMplementação das Funções 

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
    printf("==========================================\n");
    printf("    BIBLIOTECA - PARTE 3 (MESTRE)   \n");
    printf("1 - Cadastrar novo Livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar emprestimo\n");
    printf("4 - Listar emprestimos\n");
    printf("0 - Sair\n");
    printf("------------------------------------------\n");
    printf("Ecolha uma opcao: ");       
}

