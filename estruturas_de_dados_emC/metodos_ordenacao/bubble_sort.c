// MÉTODOS DE ORDENAÇÃO DE ELEMENTOS DE VETORES 

void bubbleSort(int vetor[], int tamanho){
    //função com o vetor e o tamanho dos elementos 
    
    for (int i = 0; i < tamanho - 1; i++){
        //loop para percorrer o vetor mas não até o final dele(tamanho -1)

        for(int j = 0; j < tamanho - 1 - i; j ++){
            //loop para percorrer o vetor, mas diminuindo o tamanho a cada iteração (tamanho -1 -i)

            if(vetor[j] > vetor[j + 1]){
                //se o elemento atual for maior que o próximo elemento 

                troca(&vetor[j], &vetor[j + 1]);
                //chama a função de troca passando o endereço dos dois elementos
            }
        }
    }
    
}