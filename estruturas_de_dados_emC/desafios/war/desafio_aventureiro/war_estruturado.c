//============================================================
// INTERATIVIDADE NO WAR ESTRUTURADO


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
    int vitorias;// novo campo para contar vitorias.
};


//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função que simula uma batalha entre dois territórios
int batalha(struct territorio *t1, struct territorio *t2) {
    printf("\n=== BATALHA ===\n");
    printf("%s (%d tropas) VS %s (%d tropas)\n", 
           t1->nome, t1->tropas, 
           t2->nome, t2->tropas);
    
    // Fator de sorte (±20% de variação)
    float fator1 = (rand() % 40 + 80) / 100.0;  // 0.8 a 1.2
    float fator2 = (rand() % 40 + 80) / 100.0;  // 0.8 a 1.2
    
    float forca1 = t1->tropas * fator1;
    float forca2 = t2->tropas * fator2;
    
    if (forca1 > forca2) {
        printf("%s venceu!\n", t1->nome);
        t1->vitorias++;
        return 1;
    } else if (forca2 > forca1) {
        printf("%s venceu!\n", t2->nome);
        t2->vitorias++;
        return 2;
    } else {
        printf("Empate!\n");
        return 0;
    }
}

int main() {
    struct territorio lista[5];
    srand(time(NULL)); //inicializa gerador de números aleatórios

        
    //cadastramento dos territórios
    printf("=========================================\n");
    printf(" WAR ESTRUTURADO - CADASTRO INICIAR \n");
    printf("=========================================\n");

    for(int i = 0; i< 5; i++){
    printf("---- Cadastrando Territorio %d ----\n", i + 1);

    printf("Nome do territorio: \n");
    scanf("%s", lista[i].nome);
    limparBufferEntrada();

    printf("Cor do territorio: \n");
    scanf("%s", lista[i].cor);
    limparBufferEntrada();

    printf("Quantidade de tropas: \n");
    scanf("%d", &lista[i].tropas);
    limparBufferEntrada();

    lista[i].vitorias = 0; //inicializa contagem de vitorias
    }

    //Listagem dos territórios cadastrados
    printf("\n===============================================\n");
    printf("        MAPA DO MUNDO - ESTADO ATUAL        \n");
    printf("=================================================\n");

    for(int i = 0; i< 5; i++){
        printf("%d. %s (Exercito %s, Tropas %d)\n", i + 1, lista[i].nome, lista[i].cor, lista[i].tropas);

    }


    //Fase de ataque
    printf("==============================================\n");
    printf("                FASE DE ATAQUE               \n");
    printf("==============================================\n");

    int atacante, defensor;
    do {
        printf("\nEscolha o territorio ATACANTE (1-5, ou 0 para encerrar): ");
        scanf("%d", &atacante);
        limparBufferEntrada();

        if (atacante == 0) break;

        if (atacante < 1 || atacante > 5) {
            printf("Territorio invalido! Escolha entre 1 e 5.\n");
            continue;
        }

        printf("Escolha o territorio DEFENSOR (1-5): ");
        scanf("%d", &defensor);
        limparBufferEntrada();

        if (defensor < 1 || defensor > 5 || defensor == atacante) {
            printf("Territorio invalido! Escolha outro territorio entre 1 e 5.\n");
            continue;
        }

        // Realiza a batalha
        batalha(&lista[atacante-1], &lista[defensor-1]);

        // Mostra placar parcial
        printf("\n--- Placar Parcial ---\n");
        for(int i = 0; i < 5; i++) {
            printf("%s: %d vitorias\n", lista[i].nome, lista[i].vitorias);
        }

    } while (1);

    // Mostra placar final
    printf("\n==============================================\n");
    printf("              RESULTADO FINAL                \n");
    printf("==============================================\n");

    // Encontra o território com mais vitórias
    int max_vitorias = 0;
    for(int i = 0; i < 5; i++) {
        if (lista[i].vitorias > max_vitorias) {
            max_vitorias = lista[i].vitorias;
        }
    }

    // Mostra as estatísticas finais
    printf("\nEstatisticas finais:\n");
    for(int i = 0; i < 5; i++) {
        printf("%s: %d vitorias", lista[i].nome, lista[i].vitorias);
        if (lista[i].vitorias == max_vitorias && max_vitorias > 0) {
            printf(" [VENCEDOR]");
        }
        printf("\n");
    }

    return 0;
}

