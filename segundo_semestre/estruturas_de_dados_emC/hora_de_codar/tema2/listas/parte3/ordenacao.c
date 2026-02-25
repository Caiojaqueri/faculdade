// HORA DE CODAR - TEMA 2 - NÍVEL MESTRE

#include <stdio.h>
#include <stdlib.h> //para funções rand() e srand()
#include <time.h> //para função time()

#define TAMANHO 10


//FUNÇÕES
void gerarListaOrdenada(int lista[], int n);
void gerarListaInversa(int lista[], int n);
void gerarListaAleatoria(int lista[], int n);

//funções de ordenação
void bubbleSort(int lista[], int n);
void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);

//funções auxiliares
void imprimirLista(const char* titulo, const int lista[], int n);
void copiarLista(int destino[], const int origem[], int n);

//FUNÇÃO PRINCIPAL 
int main() {
    srand(time(NULL)); //inicializa o gerador de números aleatórios

    int listaOrdenada[TAMANHO];
    int listaInversa[TAMANHO];
    int listaAleatoria[TAMANHO];

    printf("=== GERANDO LISTAS DE ENTRADA ===\n");
    gerarListaOrdenada(listaOrdenada, TAMANHO);
    gerarListaInversa(listaInversa, TAMANHO);
    gerarListaAleatoria(listaAleatoria, TAMANHO);
    printf("=================================\n\n");

    int listaTemp[TAMANHO];

    // Testando Bubble Sort
    printf("=== 1. BUBBLE SORT ===\n");

    //a) melhor caso (lista ja ordenada)
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort | Melhor caso (ja ordenada)", listaTemp, TAMANHO);

    //b) Pior cado (lista inversa)
    copiarLista(listaTemp, listaInversa, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort | Pior caso (inversa)", listaTemp, TAMANHO);

    //c) Caso Médio (lista aleatoria)
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort | Caso medio (aleatoria)", listaTemp, TAMANHO);
    printf("======================\n\n");


    // Testando Insertion Sort
    printf("=== 2. INSERTION SORT ===\n");

    //a) melhor caso (lista ja ordenada)
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort | Melhor caso (ja ordenada)", listaTemp, TAMANHO);

    //b) Pior cado (lista inversa)
    copiarLista(listaTemp, listaInversa, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort | Pior caso (inversa)", listaTemp, TAMANHO);

    //c) Caso Médio (lista aleatoria)
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort | Caso medio (aleatoria)", listaTemp, TAMANHO);
    printf("=========================\n\n");


    // Testando Selection Sort
    printf("=== 3. SELECTION SORT ===\n");

    //a) melhor caso (lista ja ordenada)
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort | Melhor caso (ja ordenada)", listaTemp, TAMANHO);

    //b) Pior cado (lista inversa)
    copiarLista(listaTemp, listaInversa, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort | Pior caso (inversa)", listaTemp, TAMANHO);

    //c) Caso Médio (lista aleatoria)
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort | Caso medio (aleatoria)", listaTemp, TAMANHO);
    printf("=========================\n\n");

    return 0;
}

//IMPLEMENTAÇÃO DAS FUNÇÕES
void bubbleSort(int lista[], int n) {
    int i, j, temp;
    int trocou;

    //a cada passagem, o maior elemento "borbulha" para o final da lista
    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - 1; j ++) {
            //se o elemento atual for maior que o próximo
            if (lista[j] > lista[j + 1]) {
                //troca os elementos de posição
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                trocou = 1; //indica que houve troca
            }
        }

        if (trocou == 0) {
            break; //a lista já está ordenada
        }
    }
}
    
void insertionSort(int lista[], int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = lista[i];
        j = i - 1;

        //move os elementos maiores que a chave para uma posição à frente
        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = chave; //insere a chave na posição correta
    }
}

void selectionSort(int lista[], int n) {
    int i, j, menor_indice, temp;

    for (i = 0; i < n - 1; i++) {
        menor_indice = i;

        //encontra o índice do menor elemento na sublista não ordenada
        for (j = i + 1; j < n; j++) {
            if (lista[j] < lista[menor_indice]) {
                menor_indice = j;
            }
        }

        //troca o menor elemento encontrado com o primeiro elemento da sublista
        if (menor_indice != i) {
            temp = lista[i];
            lista[i] = lista[menor_indice];
            lista[menor_indice] = temp;
        }
    }
}

//FUNÇÕES AUXILIARES
void gerarListaOrdenada(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = i + 1; //preenche a lista com valores de 1 a n
    }
    imprimirLista("Lista Ordenada", lista, n);
}

void gerarListaInversa(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = n - i; //preenche a lista com valores de n a 1
    }
    imprimirLista("Lista Inversa", lista, n);
}

void gerarListaAleatoria(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 100 + 1; //preenche a lista com valores aleatórios entre 1 e 100
    }
    imprimirLista("Lista Aleatoria", lista, n);
}

void imprimirLista(const char* titulo, const int lista[], int n) {
    printf("%s: ", titulo);
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void copiarLista(int destino[], const int origem[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

