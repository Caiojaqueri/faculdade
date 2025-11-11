//busca binária e sequencial 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funções da busca sequencial 
int buscaSequencialInterativa(const char* lista[], int tamanho, const char* item);
int buscarSequenciaRecursiva(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice);

//funcoes da busca binaria
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

    //testando busca sequencial
    printf("--- 1. BUSCA SEQUENCIAL ---\n");

    //sequencial interativa 
    int res1 = buscaSequencialInterativa(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Sequencial Interativa ", itemExistente, res1);

    //sequencial recursiva
    

    
}