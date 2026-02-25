//MÉTODOS DE ORDENAÇÃO DE VETORES 
// INSERTION SORT - ORDENAÇÃO POR INSERÇÃO
// percorre o vetor pegando um elemento por vez e o inserindo na posição correta em relação aos elementos já ordenados

void insertionSort(int vetor[], int tamanho){
    for(int i = 1; i < tamanho; i ++){
        //comeca do segundo elemento, enquanto o i for menor que tamanho, adicione a i + 1
        
        int chave = vetor[i];
        //a variável chave recebe o valor do elemento atual do vetor
        int j = i - 1;
        //a variável j recebe o índice do elemento anterior ao atual
        while(j >= 0 && vetor[j] > chave){
            //enquanto j for maior ou igual a 0 e o elemento na posição j for maior que a chave

            vetor[j + 1] = vetor[j];
            // o elemento na posição j + 1 recebe o valor do elemento na posição j (desloca o elemento para a direita)

            j--;
            //decrementa j para continuar verificando os elementos anteriores
        }
        vetor[j + 1] = chave;
        //insere a chave na posição correta
    }
}
