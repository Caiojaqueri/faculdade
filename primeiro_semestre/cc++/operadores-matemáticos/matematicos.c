#include <stdio.h>

int main(){                                     //OPERADORES MATEMÁTICOS

    /*
    Soma (+)
    Subtração (-)
    Multiplicação (*)
    Divisão(/)
    */


    int numero1, numero2;
    int soma, subtracao, multiplicacao, divisao;


    /*operação soma*/
    soma = numero1 + numero2;

    /*operação subtração*/
    subtracao = numero1 - numero2;

    /* operação multiplicação*/
    multiplicacao = numero1 * numero2;

    /*operação divisão*/
    divisao = numero1 / numero2;

    printf("Digite um número: \n");
    scanf("%d", numero1);
    printf("Digite outro número: \n");
    scanf("%d", numero2);

    printf("A Soma entre eles é: %d \n", soma);
    printf("A Subtração entre eles é: %d \n", subtracao);
    printf("A Multiplicação entre eles é: %d \n", multiplicacao);
    printf("A Divisão entre eles é: %d \n", divisao);
    




}