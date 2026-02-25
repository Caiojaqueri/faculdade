#include <stdio.h>

int main(){                           //OPERADORES DE INCREMENTO E DECREMENTO

/*
Incremento (++)
Pré-Incremenro (++a) 
Pós-Incremento (a++)
Decremento (--a)
Pré-Decremento (--a)
Pós-Decremento (a--)

*/

int numero1 = 1;

printf("Antes incremento: %d\n", numero1);
// incremento: numero1 = numero1 + 1
//atribuições: numero1 += 1 
numero1 ++;
printf("Pós incremento: %d\n", numero1);
// decremento: numero1 = numero1 - 1
//atribuições: numero1 -= 1
numero1 --;
printf("Pós decremento: %d\n", numero1);


}