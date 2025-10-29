#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
} pessoa;

int main() {
    //p é um ponteiro para uma pessoa
    pessoa* p = (pessoa*)malloc(sizeof(pessoa));

    printf("Digite seu nome: ");
    scanf("%s", p -> nome); //antes usavamos o ponto

    printf("Digite sua idade: ");
    scanf("%d", &p -> idade);//agora usamos a seta

    printf("%s tem %d anos,\n", p->nome, p->idade);

    free(p);

    return 0;

}
