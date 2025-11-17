// hora de codar - pilhas e filas - nível novato 

#include <stdio.h>
#include <stdlib.h>


//estrutura do elemento da fila
typedef struct {
    char nome[30];
    int idade;
} Pessoa;

//tamanho máximo da fila
#define MAX 5

//estrutura da fila
typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

//função inicializar 
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

//verificação se a fila está cheia 
int filaCheia(Fila *f) {
    //retorne f se o total for igual ao máximo 
    return f -> total == MAX;
}

//verificação se a fila está vazia 
int filaVazia(Fila *f) {
    //retorne f se o total for igual a 0 
    return f -> total == 0;
}

//inserção de elementos na fila
void inserir(Fila *f, Pessoa p) {
    if (filaCheia(f)) { //função de verificação se a fila está cheia
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
    printf("Pessoa inserida na fila: %s, %d anos\n", p.nome, p.idade);
}

//remoção de elementos da fila
void remover(Fila *f, Pessoa *p) {
    if (filaVazia(f)) {//função de verificação se a fila está vazia 
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }

    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX; //lógica circular 
    f->total--;
    printf("Pessoa removida da fila: %s, %d anos\n", p->nome, p->idade);
}

//função para mostrar os elementos da fila
void mostrarFila(Fila *f) {
    printf("Fila: ");

    //percorrer a fila de forma circular
    for (int i = 0, indice = f->inicio; i < f->total; i++, indice = (indice + 1) % MAX) {

        printf("[%s, %d anos] ", f->itens[indice].nome, f->itens[indice].idade);
    }
    printf("\n");
}

int main(){
    Fila f;
    inicializarFila(&f);//inicialização da fila


    //insereção de pessoas na fila
    Pessoa p1 = {"João", 25};
    Pessoa p2 = {"Maria", 30};

    inserir(&f, p1);
    inserir(&f, p2);

    //mostra a fila atual
    mostrarFila(&f);

    //remoção de uma pessoa da fila
    Pessoa removida;
    remover(&f, &removida);
    printf("Removida: %s, %d anos\n", removida.nome, removida.idade);

    //mostra a fila após a remoção
    mostrarFila(&f);

    return 0;
}