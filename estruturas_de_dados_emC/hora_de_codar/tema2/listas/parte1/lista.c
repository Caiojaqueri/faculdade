//Hora de codar - tema 2 - parte 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //(strcpy)

#define MAX_STR_LEN 50 //tamanho maximo da strings
#define TAM_MAX 10 //tamanho maximo dos elementos da lista


//lista estática
typedef struct {
    char dados [TAM_MAX][MAX_STR_LEN];
    int quantidade; //contador
}ListaEstatica;

//funçoes da lista estatica 
void inicializarListaEstatica(ListaEstatica *lista);
void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);


//lista encadeada
typedef struct No {
    char* dado;
    struct No *proximo;
} No;

typedef No* ListaEncadeada;

//funções da lista encadeada
void inicializarListaEncadeada(ListaEncadeada *lista);
void inserirListaEncadeada(ListaEncadeada *lista, const char* texto);
void removerListaEncadeada(ListaEncadeada *lista, const char* texto);
void listarListaEncadeada(const ListaEncadeada *lista);
void liberarListaEncadeada(ListaEncadeada *lista); //função para limpar a memória

//função principal (main)
void menuListaEstatica();
void menuListaEncadeada();

int main(){
    int opcao;
    do {
        printf("\n---- MANIPULACAO DE LISTAS ----\n");
        printf("1. Lista Estatica\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", opcao);

        switch (opcao) {
            case 1:
                menuListaEstatica();
                break;
            case 2:
                menuListaEncadeada();
                break;
            case 0:
                printf("Saindo ...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}

//implementação das funções - lista estatico 

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto){
    //verifica se a lista ja atingiu o tamanho max (TAM_MAX)
    if (lista->quantidade == TAM_MAX) {
        printf("Erro: lista cheia! Nao é possivel inserir mais nada.\n");
        return;
    }
    //comparação  de strings entre os dados, quantidades de itens e o texto que ira ser inserido 
    strcpy(lista->dados[lista->quantidade], texto);

    //adiciona o item a lista 
    lista->quantidade++;
    printf("Texto \"%s\" inset=rido com sucesso.\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
    int i, pos = -1;
    
    
}
