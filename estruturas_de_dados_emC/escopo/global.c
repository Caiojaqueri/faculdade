//VARIÁVEIS DE ESCOPO GLOBAL
#include <stdio.h>

int contador = 0; //variável declarada fora de funções, podendo ser usada em qualquer momento.

void contando() {
    contador++; //acessivel aqui 
}
