//EXEMPLO DE VARIAVEIS COM ESCOPO LOCAL E GLOBAL NO MESMO PROGRAMA

#include <stdio.h>

int global = 10; //variável com escopo global

void mostrarGlobal(){
    printf("Na funcao mostraGlobal: %d\n", global);
}

int main(){
    int local = 5;//variável com escolo local

    printf("Na funcao main (local): %d\n", local);
    printf("Na funcao main (global): %d\n", global);

    mostrarGlobal();

    return 0;
}