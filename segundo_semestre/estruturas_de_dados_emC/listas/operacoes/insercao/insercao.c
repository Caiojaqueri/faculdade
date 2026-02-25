//inserção de dados em uma lista encadeada

#include <stdio.h>

//criação da estrutura do nosso nó
struct No {
    int dado;
    struct No* proximo;
};

//função principal 
void inserirNoInicio(struct No** inicio, int valor){

    //criamos nosso nó e alocamos mémoria para ele 
    struct No* novo = (struct No*) malloc(sizeof(struct No)); 

    //verifica de a alocação de memória funcionou
    if (novo == NULL) {
        printf("Erro: Falha ao realocar memoria.\n");
        return;
    }

    //colocamos o valor dentro do nó
    novo->dado = valor;

    //o proximo do nosso nó será o início da lista
    novo->proximo = *inicio;

    //agora o início da lista passa ser o nosso novo nó 
    *inicio = novo;
}