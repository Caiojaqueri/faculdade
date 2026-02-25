#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char nome[30];
    int idade;
} pessoa;

typedef struct {
    pessoa itens[MAX];
    int topo;
} pilha;

//iniciar pilha = -1 topo
void inicializaPilha(pilha *p) {
    p->topo = -1;
}

//pilha vazia 
int pilhaVazia(pilha *p) {
    return p->topo == -1;
}

//pilha cheia
int pilhaCheia(pilha *p) {
    return p->topo == MAX - 1;
}

//push s adiciona elemento no topo da pilha
void push(pilha *p, pessoa novo) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia! Nao e possivel adicionar mais elementos.\n");
        return;
    }

    p->itens[++(p->topo)] = novo;
}

//pop remove elemento do topo da pilha
void pop(pilha *p, pessoa *removido) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Nao ha elementos para remover.\n");
        return;
    }

    *removido = p->itens[(p->topo)--];
}

//peek visualiza elemento do topo da pilha sem remover
void peek(pilha *p, pessoa *vizualizada) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Nao ha elementos para vizualizar.\n");
        return;
    }

    *vizualizada = p->itens[p->topo];
}

void mostrarPilha(pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Elementos na pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("Nome: %s, Idade: %d\n", p->itens[i].nome, p->itens[i].idade);
    }
}

int main() {
    //variável da pilha
    pilha p;
    inicializaPilha(&p);

    //pessoas na pilha
    pessoa a = {"Ana", 20};
    pessoa b = {"Bruno", 25};
    pessoa c = {"Carla", 30};

    //adicionando pessoas na pilha 
    push(&p, a);
    push(&p, b);    
    push(&p, c);

    mostrarPilha(&p);

    //variável para pessoa removida 
    pessoa removido;

    //removendo pessoa do topo da pilha
    pop(&p, &removido);
    printf("Removido: Nome: %s, Idade: %d\n", removido.nome, removido.idade);

    mostrarPilha(&p);

    //variável para pessoa no topo da pilha
    pessoa topo;

    //visualizando pessoa no topo da pilha
    peek(&p, &topo);
    printf("Topo da pilha: Nome: %s, Idade: %d\n", topo.nome, topo.idade);

    return 0;
}