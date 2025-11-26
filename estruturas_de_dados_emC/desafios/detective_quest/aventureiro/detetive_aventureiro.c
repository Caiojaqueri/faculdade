// DETETIVE QUEST - NÍVEL AVENTUREIRO 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura das pistas das salas
typedef struct PistaNode {
    char conteudo[100];
    struct PistaNode* esq;
    struct PistaNode* dir;
} PistaNode;

//estrutura das sala
typedef struct Sala {
    char nome[50];
    char conteudoPista[100];
    int temPista;
    struct Sala* esq;
    struct Sala* dir;
} Sala;

//protótipos das funções
Sala* criarSala(char* nome, char* pista);
PistaNode* inserirPista(PistaNode* raiz, char* pista);
void exibirPistas(PistaNode* raiz);
void explorarSalasComPistas(Sala* mapa); 
void liberarMapa(Sala* raiz);
void liberarPistas(PistaNode* raiz);

int main() {
    
    //raiz
    Sala* mansao = criarSala("Hall de Entrada", "Um relogio parado marca 10:30.");

    //nível 1
    mansao->esq = criarSala("Sala de Estar", "Uma cartaqueimada na lareira.");
    mansao->dir = criarSala("Cozinha", NULL); //sem pista

    //nível 2 (lado Esquerdo)
    mansao->esq->esq = criarSala("Biblioteca", "Um livro faltando na estante 'H'.");
    mansao->esq->dir = criarSala("Jardim de Inverno", "Pegadas de barro no chao.");

    //nível 2 (lado Direito)
    mansao->dir->esq = criarSala("Despensa", NULL);
    mansao->dir->dir = criarSala("Sorao", "Uma chave dourada escondida.");

    //iniciar o Jogo
    printf("=========================================\n");
    printf("      DETECTIVE QUEST: A MANSÃO\n");
    printf("=========================================\n");
    printf("Bem-vindo, detetive. Explore a mansao e colete as pistas.\n\n");

    //inicia o loop de exploração
    explorarSalasComPistas(mansao);

    liberarMapa(mansao);

    return 0;
}

//funções
Sala* criarSala(char* nome, char* pista) {
    //alocação dinâmica da estrutura Sala
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    
    if (novaSala == NULL) {
        printf("Erro fatal: Memória insuficiente.\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    
    if (pista != NULL) {
        strcpy(novaSala->conteudoPista, pista);
        novaSala->temPista = 1; //pista disponível
    } else {
        novaSala->conteudoPista[0] = '\0'; //string vazia
        novaSala->temPista = 0;
    }

    novaSala->esq = NULL;
    novaSala->dir = NULL;

    return novaSala;
}

PistaNode* inserirPista(PistaNode* raiz, char* pista) {
    //caso base: se chegamos a um lugar vazio, criamos o nó aqui
    if (raiz == NULL) {
        PistaNode* novoNode = (PistaNode*)malloc(sizeof(PistaNode));
        strcpy(novoNode->conteudo, pista);
        novoNode->esq = NULL;
        novoNode->dir = NULL;
        return novoNode;
    }

    //se for "menor", vai para a esquerda
    if (strcmp(pista, raiz->conteudo) < 0) {
        raiz->esq = inserirPista(raiz->esq, pista);
    }
    //se for "maior", vai para a direita
    else if (strcmp(pista, raiz->conteudo) > 0) {
        raiz->dir = inserirPista(raiz->dir, pista);
    }
    //se for igual, não fazemos nada (evita duplicatas, opcional)

    return raiz;
}

void exibirPistas(PistaNode* raiz) {
    if (raiz != NULL) {
        exibirPistas(raiz->esq);              
        // visita subárvore esquerda

        printf("- %s\n", raiz->conteudo);     
        // imprime o nó atual

        exibirPistas(raiz->dir);              
        // visita subárvore direita
    }
}

void explorarSalasComPistas(Sala* mapa) {
    Sala* salaAtual = mapa;
    PistaNode* inventarioPistas = NULL; //raiz da árvore BST de pistas
    char opcao;

    //loop de navegação
    do {
        if (salaAtual == NULL) {
            printf("\n[!] Voce deu de cara com uma parede ou porta trancada.\n");
            printf("Retornando ao inicio para seguranca...\n");
            salaAtual = mapa; //reinicia posição para simplificar navegação em caso de erro
            continue;
        }

        printf("\n-----------------------------------------\n");
        printf("LOCAL ATUAL: %s\n", salaAtual->nome);
        
        //lógica de coleta de pista automática
        if (salaAtual->temPista) {
            printf(">> PISTA ENCONTRADA: \"%s\"\n", salaAtual->conteudoPista);
            printf(">> (Pista adicionada ao seu caderno de notas)\n");
            
            //adiciona na BST
            inventarioPistas = inserirPista(inventarioPistas, salaAtual->conteudoPista);
            
            // marca como coletada para não pegar novamente
            salaAtual->temPista = 0; 
        } else {
            printf("(Nenhuma pista nova neste local)\n");
        }

        // menu de Opções
        printf("\nPara onde deseja ir?\n");
        if (salaAtual->esq != NULL) printf(" [e] Esquerda: %s\n", salaAtual->esq->nome);
        else printf(" [e] Esquerda: (Sem passagem)\n");

        if (salaAtual->dir != NULL) printf(" [d] Direita: %s\n", salaAtual->dir->nome);
        else printf(" [d] Direita: (Sem passagem)\n");

        printf(" [s] Sair da Mansao (Encerrar)\n");
        printf("Opcao: ");
        scanf(" %c", &opcao); //espaço antes de %c ignora enter/espaços anteriores

        //processa a navegação
        switch(opcao) {
            case 'e':
            case 'E':
                if (salaAtual->esq != NULL) salaAtual = salaAtual->esq;
                else printf("\n>> Nao ha caminho para a esquerda!\n");
                break;
            case 'd':
            case 'D':
                if (salaAtual->dir != NULL) salaAtual = salaAtual->dir;
                else printf("\n>> Nao ha caminho para a direita!\n");
                break;
            case 's':
            case 'S':
                printf("\nSaindo da mansao...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 's' && opcao != 'S');

    // fim da exploração: Mostrar relatório
    printf("\n=========================================\n");
    printf("       RELATORIO FINAL DO DETETIVE\n");
    printf("=========================================\n");
    if (inventarioPistas == NULL) {
        printf("Nenhuma pista foi coletada.\n");
    } else {
        printf("Pistas coletadas (Ordem Alfabetica):\n");
        exibirPistas(inventarioPistas);
    }
    printf("=========================================\n");

    //limpa a memória das pistas antes de sair desta função
    liberarPistas(inventarioPistas);
}

//funções auxiliares para liberar memória (Recursivas)
void liberarMapa(Sala* raiz) {
    if (raiz == NULL) return;
    liberarMapa(raiz->esq);
    liberarMapa(raiz->dir);
    free(raiz);
}

void liberarPistas(PistaNode* raiz) {
    if (raiz == NULL) return;
    liberarPistas(raiz->esq);
    liberarPistas(raiz->dir);
    free(raiz);
}
