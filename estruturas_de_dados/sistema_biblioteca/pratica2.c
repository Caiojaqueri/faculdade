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

    //usamos malloc para o array emprestimo 
    emprestimos = (struct emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct emprestimo));

    //verificação se a alocação de memória deu certo 
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1; //retorna 1 para indicar um erro
    }

    int totallivros = 0;
    int totalemprestimos = 0;
    int opcao;

    do {
        printf("==========================================\n");
        printf("    BIBLIOTECA - PARTE 2    \n");
        printf("1 - Cadastrar novo Livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprestimo\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("===========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

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

            case 3: //REALIZAR EMPRESTIMO
                printf("-----Realizar Emprestimo-----\n\n");

                if (totalemprestimos > MAX_EMPRESTIMOS) {
                    printf("Limite de emprestimo atingido!\n");
                } else {
                    printf("Livros disponiveis: \n");
                    int disponiveis = 0;
                    for (int i = 0; i < totallivros; i++) {
                        if (biblioteca[i].disponivel) {
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            disponiveis++;
                        }  
                    }

                    if (disponiveis == 0) {
                        printf("Nenhum livro disponivel para emprestimo,\n");
                    } else {
                        printf("\nDigite o numero do livro que deseja emprestar: ");
                        int numLivro;
                        scanf("%d", &numLivro);
                        limparBufferEntrada();

                        int indice = numLivro - 1; //converte para o indice do array (0 a N-1)

                        //validação da escolha do usuário
                        if (indice >= 0 && indice < totallivros && biblioteca[indice].disponivel){
                            printf("Digite o nome do usuario que esta pegando o livro: ");
                            fgets(emprestimos[totalemprestimos].nomeUsuario, TAM_STRING, stdin);
                            /* remover '\n' final caso exista */
                            emprestimos[totalemprestimos].nomeUsuario[
                                strcspn(emprestimos[totalemprestimos].nomeUsuario, "\n")
                            ] = '\0';

                            /* registrar o empréstimo */
                            emprestimos[totalemprestimos].indiceLivro = indice;

                            /* marcar o livro como não disponível */
                            biblioteca[indice].disponivel = 0;

                            totalemprestimos++;
                            printf("\nEmprestimo realizado com sucesso!\n");
                        } else {
                            printf("Opcao invalida ou livro indisponivel.\n");
                        }
                    }
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
                
            case 4: //LISTAR EMPRESTIMOS
                printf("----- Listar emprestimos -----\n\n");
                if (totalemprestimos == 0) {
                    printf("Nehum emprestimo listado.\n");
                } else {
                    for (int i = 0; i < totalemprestimos; i++) {
                        //usa o indice armazenado no empresitmo para buscar o nome do livro
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("----------------------------------------------\n");
                        printf("EMPRESTIMOS %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                    }
                    printf("--------------------------------------------\n");
                }
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

    /* LIBERAÇÃO DA MEMÓRIA*/
    free(biblioteca);
    free(emprestimos);

    printf("Memoria liberada com sucesso.\n");

    return 0;
}

