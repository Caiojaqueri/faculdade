// FREEFIRE - NÍVEL MESTRE 
// Ordenação dos componentes por nome, tipo e prioridade usando Selection Sort
// Busca binária para localizar componente-chave por nome


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

typedef struct {
    char nome[30];
    char tipo[30];
    int prioridade;
} Componente;

// Variáveis globais para medir desempenho
long comparacoes = 0;
double tempo_execucao = 0;

// -------------------- FUNÇÕES DE ORDENAÇÃO --------------------

void SelectionSortNome(Componente v[], int n) {
    comparacoes = 0;
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (strcmp(v[j].nome, v[menor].nome) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            Componente tmp = v[i];
            v[i] = v[menor];
            v[menor] = tmp;
        }
    }

    clock_t fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void SelectionSortTipo(Componente v[], int n) {
    comparacoes = 0;
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (strcmp(v[j].tipo, v[menor].tipo) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            Componente tmp = v[i];
            v[i] = v[menor];
            v[menor] = tmp;
        }
    }

    clock_t fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void SelectionSortPrioridade(Componente v[], int n) {
    comparacoes = 0;
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j].prioridade < v[menor].prioridade) {
                menor = j;
            }
        }
        if (menor != i) {
            Componente tmp = v[i];
            v[i] = v[menor];
            v[menor] = tmp;
        }
    }

    clock_t fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// -------------------- BUSCA BINÁRIA (por nome) --------------------

int BuscaBinaria(Componente v[], int n, char chave[]) {
    int baixo = 0, alto = n - 1;

    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int cmp = strcmp(chave, v[meio].nome);

        if (cmp == 0) return meio;
        else if (cmp > 0) baixo = meio + 1;
        else alto = meio - 1;
    }

    return -1;
}

// -------------------- FUNÇÕES DE INTERFACE --------------------

void ExibirComponentes(Componente v[], int n) {
    printf("\n=== COMPONENTES ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d) Nome: %s | Tipo: %s | Prioridade: %d\n",
               i + 1, v[i].nome, v[i].tipo, v[i].prioridade);
    }
    printf("\n");
}

int main() {
    Componente lista[MAX];
    int n = 0;
    int opcao;
    int ordenado = 0;

    while (1) {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Cadastrar componentes\n");
        printf("2. Ordenar por nome\n");
        printf("3. Ordenar por tipo\n");
        printf("4. Ordenar por prioridade\n");
        printf("5. Buscar componente-chave (por nome)\n");
        printf("6. Exibir montagem final\n");
        printf("7. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

        case 1: {
            printf("\nQuantos componentes deseja cadastrar (1-20)? ");
            scanf("%d", &n);
            getchar();

            if (n < 1 || n > MAX) {
                printf("Quantidade inválida!\n");
                n = 0;
                break;
            }

            for (int i = 0; i < n; i++) {
                printf("\n--- Componente %d ---\n", i + 1);
                printf("Nome: ");
                fgets(lista[i].nome, 30, stdin);
                lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;

                printf("Tipo: ");
                fgets(lista[i].tipo, 30, stdin);
                lista[i].tipo[strcspn(lista[i].tipo, "\n")] = 0;

                printf("Prioridade (1-10): ");
                scanf("%d", &lista[i].prioridade);
                getchar();
            }

            ordenado = 0;
        }
        break;

        case 2:
            SelectionSortNome(lista, n);
            printf("\nOrdenado por nome!\nComparações: %ld\nTempo: %.6f s\n",
                   comparacoes, tempo_execucao);
            ordenado = 1;
            break;

        case 3:
            SelectionSortTipo(lista, n);
            printf("\nOrdenado por tipo!\nComparações: %ld\nTempo: %.6f s\n",
                   comparacoes, tempo_execucao);
            ordenado = 2;
            break;

        case 4:
            SelectionSortPrioridade(lista, n);
            printf("\nOrdenado por prioridade!\nComparações: %ld\nTempo: %.6f s\n",
                   comparacoes, tempo_execucao);
            ordenado = 3;
            break;

        case 5: {
            if (ordenado != 1) {
                printf("\nAtenção: a busca binária só funciona se estiver ordenado por NOME!\n");
                printf("Ordene por nome primeiro.\n");
                break;
            }

            char chave[30];
            printf("\nNome do componente a buscar: ");
            fgets(chave, 30, stdin);
            chave[strcspn(chave, "\n")] = 0;

            int pos = BuscaBinaria(lista, n, chave);

            if (pos == -1) {
                printf("\nComponente não encontrado!\n");
            } else {
                printf("\n*** COMPONENTE-CHAVE ENCONTRADO ***\n");
                printf("Nome: %s\nTipo: %s\nPrioridade: %d\n",
                       lista[pos].nome, lista[pos].tipo, lista[pos].prioridade);
            }
        }
        break;

        case 6:
            ExibirComponentes(lista, n);
            break;

        case 7:
            printf("Saindo...\n");
            return 0;

        default:
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
