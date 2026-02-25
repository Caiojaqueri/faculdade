#include <stdio.h>              //ENTRADA DE DADOS//

int main(){
    int idade;
    float altura;
    char opcao;
    char nome[20];
    

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("A sua idade é: %d\n", idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("A sua altura é: %f\n", altura);

    printf("Digite seu nome: ");
    scanf("%s", &nome);
    printf("Seu nome é: %s\n", nome);

    print("Digite sua opção: ");
    scanf(" %c", &opcao);
    printf("Sua opção é: %c", opcao);


    /* scanf("formato1 formato2", &variavel1, &variavel2);  */

    /*
    %d - imprime um número inteiro no formato decimal
    %i - equivalente a %d
    %f - imprime um número decimal no formato padrão 
    %e - imprime um número decimal na notação científica
    %c - imprime um único caractere, uma letra 
    %s imprime uma cadeia de caracteres (string)
    
    
    */


}