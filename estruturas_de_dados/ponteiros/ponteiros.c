#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x; //o ponteiro 'p' recebe o endereco de x


    *p = 20;//podendo alterar o valor em qualquer momento 

    printf("O valor do x é: %d\n", x);
    printf("O endereco do x é: %p\n", &x);
    printf("O conteudo do p é: %p\n", p);
    printf("O valor apontado para o p é: %d\n", *p);

}
