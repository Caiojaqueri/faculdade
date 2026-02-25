// VARIAVÉIS DE ESCOPO LOCAL 
#include <stdio.h>

void minhaFuncao() {
    int x = 10; //variável de escolpo local, nasce dentro de uma função e morre quando ela finaliza.
    printf("Dentro da minha funcao x = %d\n", x);
}
