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

typedef No* ListaEncadeada;//atalho  

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

//============================================================================================================
//implementação das funções - lista estatica

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
    strcpy(lista->dados[lista->quantidade], texto); //se o dado fosse do tipo inteiro utilizariamos =

    //adiciona o item a lista 
    lista->quantidade++;
    printf("Texto \"%s\" inset=rido com sucesso.\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
    int i, pos = -1;
    for (i = 0; i < lista->quantidade; i++) {//navega item po ritem da lista 
        if (strcpy(lista->dados[i], texto) == 0){ //compara o texto que ira ser retirado com os itens da lista, se forem iguais remove 
            pos = i;
            break;
        }
    }

    //se caso não for encontrado o texto que desejamos remover 
    if (pos == -1) {
        printf("Erro: Texto \"%s\" não encontrado na lista.\n", texto);
        return;
    }

    //preenche o espaço do item que removemos deixou, deslocando os elementos para a esquerda
    for (i = pos; i < lista->quantidade - 1; i++) {
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    //atualizando o contador e a lista
    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n");
}

void listarListaEstatica(const ListaEstatica *lista) {
    if (lista->quantidade == 0) {
        printf("Lista estatica esta vazia, nao ha nada para listar");
        return;
    }
    printf("Itens da Lista Estatica: [");
    for (int i = 0; i < lista->quantidade; i ++) {//desde o indice 0 da lista de um a um ++ 
        printf("\"%s\" ", lista->dados[i]);//printe os itens 
    }
    printf("]\n");
}

//===========================================================================================================
//Implementação das funções - Lista encadeada

void inicializarListaEncadeada(ListaEncadeada *lista) {
    //lista aponta para o valor null
    *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto) {
    //pedindo memória para o novo nó
    No* novoNo = (No*) malloc(sizeof(No));

    //se caso falhar a alocacao de memória 
    if (novoNo = NULL) {
        printf("Erro: Falha na alocacao de memoria\n");
        return;
    }

    //reserva espaço na memória para guardar uma cópia da string texto, dentro do novoNo
    novoNo->dado = (char*) malloc(strlen(texto) + 1);

    //verificação se deu certo 
    if (novoNo->dado == NULL) {
        printf("Erro: Falha na alocacao de memoria para o texo.\n");
        free(novoNo); //libera o nó que já foi alocado
        return;
    }

    //copia o texto novo que ira ser inserido
    strcpy(novoNo->dado, texto);

    //liga o novo nó a lista
    novoNo->proximo = *lista;

    //atualização da lista com o novo nó
    *lista = novoNo;

    printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto) {
    //dois ponteiros para percorrer a lista
    No *atual = *lista;
    No *anterior = NULL;

    //enquanto o atual for igual a null compare as string com o texto a ser removido 
    while (atual != NULL && strcpy(atual->dado, texto) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) {
        printf("Erro: Texto \"%s\" ao encontrado.\n", texto);
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    //liberamos primeiro a string dentro do nó
    free(atual->dado);

    //ai sim liberamos o nó
    free(atual);
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEncadeada(const ListaEncadeada *lista) {
    No *temp = *lista;
    if(temp == NULL) {
        printf("A lista encadeada esta vazia.\n");
        return;
    }
    printf("Itens da lista Encadeada: [ ");
    while (temp != NULL) {
        printf("\"%s\" ", temp->dado);
        temp = temp->proximo;// printa os itens da lista
    }
    printf("]\n");
}

void liberarListaEncadeada(ListaEncadeada *lista) {
    No *atual = *lista;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual->dado);
        free(atual);
    }
}
