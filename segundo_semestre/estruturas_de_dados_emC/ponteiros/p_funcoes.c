#include <stdio.h>

void saudacao() {
    printf("Olá Mundo!!\n");
}

int main() {
    //declarando um ponteiro 'ptr' para uma função
    //que não retorna nada (void) e não tem parâmetros()
    void (*ptr)() = saudacao;

    //chamando a função através do ponteiro
    ptr();

    return 0;
}
