//DESAFIO NÍVEL MESTRE
//WAR ESTRUTURADO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//ESTRUTURAS
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} territorio;

//FUNÇÕES
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

int verificarMissao(char *missao, territorio *mapa, int tamanho) {
    if (strstr(missao, "Verde")) {
        for (int i = 0; i < tamanho; i++) {
            if(strcmp(mapa[i].cor, "Verde") == 0 && mapa[i].tropas > 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void exibirMapa(territorio *mapa, int tamanho) {
    printf("\n========== MAPA DO MUNDO ============\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d. %s\t(Exercito: %s, Tropas: %d)\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("=========================================\n");
}

void atacar(territorio *atacante, territorio *defensor) {
    int dadoA = (rand() % 6) + 1;
    int dadoD = (rand() % 6) + 1;
    printf("\nRolagem de dados: %s (%d) n %s (%d)\n", atacante->cor, dadoA, defensor->cor, dadoD);

    if (dadoA > dadoD) {
        printf("VITÓRIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
        defensor->tropas--;
        if(defensor->tropas < 0) defensor->tropas = 0; 
    } else {
        printf("DEFESA BEM-SUCEDIDA! O atacante perdeu 1 tropa.\n");
        atacante->tropas--;
        if(atacante->tropas < 0) atacante->tropas = 0;
    }
    
}

void liberarMemoria(territorio *mapa, char *missao) {
    free(mapa);
    free(missao);
}

//FUNÇÃO PRINCIPAL
