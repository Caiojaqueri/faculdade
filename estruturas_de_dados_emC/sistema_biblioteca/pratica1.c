//=========================================================================
// PRATICA: SISTEMA DE BIBLIOTECA - PARTE 1
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
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//função principal 
int main() {
    struct Livro biblioteca [ MAX_LIVROS ];
    int totallivros = 0;
    int opcao;

    //laço principal
    do {

        //exibe o menu
        printf("====================================\n");
        printf("        BIBLIOTECA - PARTE 1'       \n");
        printf("====================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("------------------------------------\n");
        printf("Escolha uma opcao: ");

        //lê a opção do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); //limpa o '\n' deixado pelo scanf

        //processamento da opção
        switch (opcao) {
            case 1: //CADASTRO DE LIVRO
                printf("---Cadastro de Novo Livro ---\n\n");

                if (totallivros < MAX_LIVROS) {
                    printf("Nome do Livro: ");
                    fgets(biblioteca[totallivros].nome, TAM_STRING, stdin);

                    printf("Autor do Livro: ");
                    fgets(biblioteca[totallivros].autor, TAM_STRING, stdin);

                    printf("Editora do Livro: ");
                    fgets(biblioteca[totallivros].editora, TAM_STRING, stdin);

                    biblioteca[totallivros].nome[strcspn(biblioteca[totallivros].nome, "\n")] = '\0';
                    biblioteca[totallivros].autor[strcspn(biblioteca[totallivros].autor, "\n")] = '\0';
                    biblioteca[totallivros].editora[strcspn(biblioteca[totallivros].editora, "\n")] = '\0';

                    printf("Edicao do Livro: ");
                    scanf("%d", &biblioteca[totallivros].edicao);
                    limparBufferEntrada();

                    totallivros++;
                    //totallivros = totallivros + 1;

                    printf("\nLivro Cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Nao e possivel cadastrar mais livros.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar(); //pausa para o usuário ler a mensagem antes de voltar
                break;

            case 2: //LISTAGEM DE LIVROS 
                printf("--- Lista de Livros Cadastrados ---\n\n");

                if(totallivros == 0) {
                    printf("Nenhum Livro cadastrado ainda.\n"); 
                } else {
                    for (int i = 0; i < totallivros; i++) {
                        printf("-----------------------------------\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                    }
                    printf("------------------------------------------\n");
                }
                //a pausa é crucial para que o usuário veja a lista anyes do proprio loop limpar a tela
                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0: //SAIR
                printf("\nSaindo do sistema...\n");
                break;

            default: //OPÇÃO INVÁLIDA
                printf("\nOpcao invalida! Tente novamente...\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcao != 0);

    return 0; //FIM DO PROGRAMA
};
