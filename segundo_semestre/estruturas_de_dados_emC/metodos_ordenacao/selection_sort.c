// MÉTODO DE ORDENAÇÃO DE VETORES
// SELECTION SORT - ORDENAÇÃO POR SELEÇÃO
// percorre o vetor selecionando o menor elemento e trocando-o com o elemento na posição atual

void trocar(int* a, int* b) {
    // Função auxiliar para trocar dois elementos
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int vetor[], int tamanho) {
    // Percorre todo o vetor
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;

        // Encontra o índice do menor elemento no restante do vetor
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }// Troca o menor elemento encontrado com o elemento na posição atual
        if (indiceMenor != i) {
            trocar(&vetor[i], &vetor[indiceMenor]);
        }
    }
} 