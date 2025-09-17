#include <stdio.h>

int main(){                         //OPERADORES DE ATRIBUIÇÃO

/*
Atribuição Simples (=) 
Atribuição com Soma (+=)
Atribuição com Subtração (-=)
Atribuição com Multiplicação (*=)
Atribuição com Divisão (/=)
*/

int numero1 = 10, numero2, resultado;

resultado = 10;
printf("Resultado: %d\n", resultado); //10

//resultado = resultado + 20
resultado += 20;
printf("Resultado: %d\n", resultado); //30

//resultado = resultado  - numero1
resultado -= numero1;
printf("Resultado; %d\n", resultado); //20

//resultado = resultato * 5
resultado *= 5;
printf("Resultado; %d\n", resultado); //100

//resultado = resultado / 2
resultado /= 2;
printf("Resultado; %d\n", resultado); //100

/*
Resultado: 10
Resultado: 30
Resultado: 20
Resultado: 100
Resultado: 50


*/




}