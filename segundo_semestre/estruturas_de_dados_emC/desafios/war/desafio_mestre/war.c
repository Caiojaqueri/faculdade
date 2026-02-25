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
int main() {
    srand(time(NULL));

    //missões
    char *missoes[] = {
        "Conquistar 3 territórios seguidos.",
        "Eliminar todas as tropas da cor Vermelha.",
        "Destruir o exercito Verde.",
        "Dominar Ameria e Europa.",
        "Conquistar todos os terriorios Azuis."
    };
    int totalMissoes = 5;

    //territorios
    int qtdTerritorios = 5;
    territorio *mapa = (territorio *) calloc(qtdTerritorios, sizeof(territorio));
    strcpy(mapa[0].nome, "America");
    strcpy(mapa[0].cor, "Verde");
    mapa[0].tropas = 3;

    strcpy(mapa[1].nome, "Europa");
    strcpy(mapa[1].cor, "Azul");
    mapa[1].tropas = 3;

    strcpy(mapa[2].nome, "Asia");
    strcpy(mapa[2].cor, "Vermelho");
    mapa[2].tropas = 3;

    strcpy(mapa[3].nome, "Africa");
    strcpy(mapa[3].cor, "Amarelo");
    mapa[3].tropas = 3;

    strcpy(mapa[4].nome, "Oceania");
    strcpy(mapa[4].cor, "Branco");
    mapa[4].tropas = 3;

    //sorteio da missao 
    char *missaoJogador = (char *) malloc(100 * sizeof(char));
    atribuirMissao(missaoJogador, missoes, totalMissoes);

    printf("\n---SUA MISSAO (Exercito Azul)---\n%s\n", missaoJogador);

    int opcao;
    do {
        printf("\n--- MENU DE ACOES ---\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Escolha sua acao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            int ataque, defesa;
            exibirMapa(mapa, qtdTerritorios);
            printf("Escolha territorio atacante (numero): ");
            scanf("%d", ataque);
            printf("Escolha territorio defensor (numero): ");
            scanf("%d", defesa);

            if(ataque >= 1 && ataque <= qtdTerritorios && defesa>= 1 && defesa <= qtdTerritorios) {
                atacar(&mapa[ataque - 1], &mapa[defesa - 1]);
            }
            else if (opcao == 2) {
                if (verificarMissao(missaoJogador, mapa, qtdTerritorios))
                    printf("\n*** MISSAO CUMPRIDA! VOCE VENCEU! ***\n");
                    break;
            } else {
                printf("\n Missai ainda nao cumprida. \n");
            }

        }

        printf("\nPressione Enter para continuar...");
        getchar(); getchar();
    } while (opcao != 0);
    liberarMemoria(mapa, missaoJogador);
    printf("\nJogo encerrado.\n");
    return 0;
}
