//=======================================================================================================
//DESAFIO NÍVEL NOVATO 
//Construir uma base de dados de territórios utilizando uma estrutura de dados composta.
//o sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento 
//=======================================================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
};


//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    //lista de 5 territórios
    struct territorio lista[5];


    //cadastramento dos territórios
    printf("=========================================\n");
    printf("Vamos cadastrar 5 territorios iniciais do nosso mundo\n");

    for(int i = 0; i< 5; i++){
    printf("---- Cadastranto Territorio %d ----\n", i + 1);

    printf("Nome do territorio: \n");
    scanf("%s", lista[i].nome);

    printf("Cor do territorio: \n");
    scanf("%s", lista[i].cor);

    printf("Quantidade de tropas: \n");
    scanf("%d", &lista[i].tropas);
    }


    //Listagem dos territórios cadastrados
    printf("\n===============================================\n");
    printf("Lista de Territorios cadastrados: \n");
    printf("=================================================\n");

    for(int i = 0; i< 5; i++){
    printf("\n---Territorio %d ---\n", i + 1);
    printf("Nome: %s\n", lista[i].nome);
    printf("Cor: %s\n", lista[i].cor);
    printf("Tropas: %d\n", lista[i].tropas);

    }

    return 0;
    
};

