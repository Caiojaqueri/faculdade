//busca binária e sequencial 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNÇÕES DA BUSCA SEQUENCIAL
int buscaSequencialInterativa(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice);

//FUNÇÕES DA BUSCA BINÁRIA
int buscaBinariaInterativa(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim);

void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado);

int main() {
    const char* listaDeCompras[] = {
        "arroz",
        "batata",
        "cebola",
        "detergente",
        "feijao",
        "leite",
        "macarrao",
        "oleo",
        "sal",
        "tomate"
    };
    //calcula o númedo de itens da lista 
    int tamanhoDaLista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);

    //itens que vamos procurar para demonstrar os lagoritmos.
    const char* itemExistente = "leite";
    const char* itemInexistente = "queijo";

    printf("--- DEMONSTRACAO DE ALGORITMOS DE BUSCA EM LISTA DE TEXTO ---\n");
    printf("Lista utilizada: [arroz, batata, cebola, detergente, feijao, leite, macarrao, oleo, sal, tomate]\n");
    printf("--------------------------------------------------------------\n\n");

    //BUSCA SEQUENCIAL
    printf("--- 1. BUSCA SEQUENCIAL ---\n");

    //sequencial INTERATIVA 
    int res1 = buscaSequencialInterativa(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Sequencial Interativa ", itemExistente, res1);//item existente

    int res2 = buscaSequencialInterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimirResultado("Sequencial Interativa ", itemInexistente, res2);//item inesistente


    //sequencial RECURSIVA
    int res3 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Sequencial Recursiva ", itemExistente, res3);

    int res4= buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimirResultado("Sequencial Recursiva ", itemInexistente, res4);
    printf("-----------------------------------------------------------------------\n\n");

    //BUSCA BINÁRIA
    printf(" --- 2. BUSCA BINARIA (requer lista ordenada) ---\n");

    //binária INTERATIVA
    int res5 = buscaBinariaInterativa(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Binária Interativa ", itemExistente, res5);

    int res6 = buscaBinariaInterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimirResultado("Binária Intertiva ", itemInexistente, res6);


    //binária RECURSIVA
    int res7 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Binária Recursiva ", itemExistente, res7);

    int res8 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimirResultado("Binária Recursiva ", itemInexistente, res8);
    printf("-------------------------------------------------------------------------\n\n");

    return 0;
}

//FUNÇÕES 
int buscaSequencialInterativa(const char*lista[], int tamanho, const char* item){
    for(int i = 0; i < tamanho; i++){
        //se as strings da lista forem iguais, retorna o indice atual
        if(strcmp(lista[i], item) == 0){
            return i;
        }
    }
    //se não, significa q o item não está na lista
    return -1;
}

int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item){
    //a lógica da recursiva real está da função auxiliar
    //começando no indice 0
    return buscaSequencialRecursiva_aux(lista, tamanho, item, 0);
}

int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice){
    //se o indice atual for maior ou igual ao tamanho da lista
    if(indice >= tamanho){
        return -1;//item não encontrado
    }

    if(strcmp(lista[indice], item) == 0){
        return indice;
    }

    return buscaSequencialRecursiva_aux(lista, tamanho, item, indice + 1);
}

int buscaBinariaInterativa(const char* lista[], int tamanho, const char* item){
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    //enquanto o inicio for menor ou igual ao fim 
    while (inicio <= fim){
        //ve o meio da lista
        meio = inicio + (fim - inicio) / 2;

        //compara o meio da lista com o item que vai ser encontrado
        int comparacao = strcmp(lista[meio], item);

        //se for igual a 0, se está no MEIO da lista
        if (comparacao == 0){
            return meio;
        }
        //se for maior que 0, está no FIM Da lista
        else if (comparacao > 0){
            //descarta metade da lista 
            fim = meio - 1;
        }
        else {//se nao está no INICIO da lista 
            inicio = meio + 1;
        }
    }
    return -1;
}

int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item){

    return buscaBinariaRecursiva_aux(lista, item, 0, tamanho - 1);
}

int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim){
    if (inicio > fim) {
        return - 1;
    }

    int meio = inicio + (fim - inicio) / 2;
    int comparacao = strcmp(lista[meio], item);

    if (comparacao == 0) {
        return meio;
    }
    else if (comparacao > 0) {
        return buscaBinariaRecursiva_aux(lista, item, inicio, meio - 1);
    }
    else {
        return buscaBinariaRecursiva_aux(lista, item, meio + 1, fim);
    }
}

void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado){
    printf("[%s] Buscando Por \"%s\"...\n", nomeDaBusca, item);
    if(resultado != -1){
        printf(" -> Resultado Item encontrado no indice %d.\n", resultado);
    } else {
        printf(" -> Resultado: Item nao encontrado na lista.\n");
    }
}