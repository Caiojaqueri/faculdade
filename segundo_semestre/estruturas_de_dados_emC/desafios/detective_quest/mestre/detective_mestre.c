// DETECTIVE QUEST - NÍVEL MESTRE 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_TABLE_SIZE 101  /* tamanho da tabela hash (primo razoável) */
#define MAX_NAME 100
#define MAX_PISTA 256
#define TRUE 1
#define FALSE 0


typedef struct Sala {
    char *nome;
    char *pista;        /* pista associada à sala (NULL se não houver) */
    struct Sala *esq;
    struct Sala *dir;
} Sala;

typedef struct BSTNode {
    char *pista;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct HashEntry {
    char *pista;
    char *suspeito;
    struct HashEntry *next;
} HashEntry;

typedef struct HashTable {
    HashEntry *buckets[HASH_TABLE_SIZE];
} HashTable;


/* Cria dinamicamente um cômodo (sala) */
Sala* criarSala(const char *nome, const char *pista);

/* Navega pela árvore de salas e ativa o sistema de pistas */
void explorarSalas(Sala *raiz, BSTNode **pistasColetadas, HashTable *ht);

/* Inserir uma pista coletada na BST (ordenada) */
void inserirPista(BSTNode **root, const char *pista);

/* Alias solicitado: adicionarPista */
void adicionarPista(BSTNode **root, const char *pista);

/* Operações para a hash: inicializar, inserir associação pista->suspeito, buscar suspeito pela pista */
void inicializarHash(HashTable *ht);
void inserirNaHash(HashTable *ht, const char *pista, const char *suspeito);
char* encontrarSuspeito(HashTable *ht, const char *pista);

/* Verificar a acusação final comparando pistas coletadas com o acusado */
int verificarSuspeitoFinal(BSTNode *pistasColetadas, HashTable *ht, const char *acusado);

/* Funções auxiliares: impressões, busca BST, destruir estruturas */
void imprimirPistasInOrder(BSTNode *root);
int bstContem(BSTNode *root, const char *pista);
void liberarBST(BSTNode *root);
void liberarSala(Sala *r);
unsigned long hashString(const char *str);


Sala* criarSala(const char *nome, const char *pista) {
    Sala *s = (Sala*) malloc(sizeof(Sala));
    if (!s) {
        fprintf(stderr, "Erro de alocação (criarSala)\n");
        exit(EXIT_FAILURE);
    }
    s->nome = strdup(nome);
    s->pista = (pista ? strdup(pista) : NULL);
    s->esq = s->dir = NULL;
    return s;
}

void explorarSalas(Sala *raiz, BSTNode **pistasColetadas, HashTable *ht) {
    Sala *atual = raiz;
    char comando[10];
    printf("\n--- INÍCIO DA EXPLORAÇÃO ---\n");
    printf("Comandos: esquerda (e), direita (d), sair (s), ajuda (h)\n");
    while (atual) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        if (atual->pista) {
            printf("Há uma pista nesta sala: \"%s\"\n", atual->pista);
            if (!bstContem(*pistasColetadas, atual->pista)) {
                /* Pergunta para coletar; simplificação: coleta automática se jogador quiser */
                printf("Deseja coletar esta pista? (s/n): ");
                if (!fgets(comando, sizeof(comando), stdin)) break;
                if (tolower((unsigned char)comando[0]) == 's') {
                    /* Inserir na BST e garantir que a pista esteja associada na hash (se já existir na hash, não duplicar) */
                    inserirPista(pistasColetadas, atual->pista);
                    /* Nota: a associação pista->suspeito deve ter sido criada em main (mapa fixo) */
                    printf("Pista coletada e armazenada.\n");
                } else {
                    printf("Pista descartada por enquanto.\n");
                }
            } else {
                printf("Você já coletou esta pista anteriormente.\n");
            }
        } else {
            printf("Não há pistas nesta sala.\n");
        }

        /* Mostra opções de movimento */
        printf("Escolha: (e) esquerda  (d) direita  (s) sair  (h) ajuda : ");
        if (!fgets(comando, sizeof(comando), stdin)) break;
        char c = tolower((unsigned char)comando[0]);
        if (c == 's') {
            printf("Você escolheu sair da exploração.\n");
            break;
        } else if (c == 'e') {
            if (atual->esq) {
                atual = atual->esq;
            } else {
                printf("Não há sala à esquerda.\n");
            }
        } else if (c == 'd') {
            if (atual->dir) {
                atual = atual->dir;
            } else {
                printf("Não há sala à direita.\n");
            }
        } else if (c == 'h') {
            printf("Ajuda: e = esquerda, d = direita, s = sair, h = ajuda\n");
        } else {
            printf("Comando desconhecido.\n");
        }
    }
    printf("\n--- FIM DA EXPLORAÇÃO ---\n");
}

BSTNode* novoBSTNode(const char *pista) {
    BSTNode *n = (BSTNode*) malloc(sizeof(BSTNode));
    if (!n) { fprintf(stderr, "Erro alocação (novoBSTNode)\n"); exit(EXIT_FAILURE); }
    n->pista = strdup(pista);
    n->left = n->right = NULL;
    return n;
}

void inserirPista(BSTNode **root, const char *pista) {
    if (*root == NULL) {
        *root = novoBSTNode(pista);
        return;
    }
    int cmp = strcmp(pista, (*root)->pista);
    if (cmp == 0) {
        /* já está na árvore */
        return;
    } else if (cmp < 0) {
        inserirPista(&((*root)->left), pista);
    } else {
        inserirPista(&((*root)->right), pista);
    }
}

void adicionarPista(BSTNode **root, const char *pista) {
    inserirPista(root, pista);
}

int bstContem(BSTNode *root, const char *pista) {
    if (!root) return FALSE;
    int cmp = strcmp(pista, root->pista);
    if (cmp == 0) return TRUE;
    if (cmp < 0) return bstContem(root->left, pista);
    else return bstContem(root->right, pista);
}

void imprimirPistasInOrder(BSTNode *root) {
    if (!root) return;
    imprimirPistasInOrder(root->left);
    printf("- %s\n", root->pista);
    imprimirPistasInOrder(root->right);
}

void liberarBST(BSTNode *root) {
    if (!root) return;
    liberarBST(root->left);
    liberarBST(root->right);
    free(root->pista);
    free(root);
}

unsigned long hashString(const char *str) {
    /* djb2 */
    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char)*str++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_TABLE_SIZE;
}

void inicializarHash(HashTable *ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) ht->buckets[i] = NULL;
}

void inserirNaHash(HashTable *ht, const char *pista, const char *suspeito) {
    unsigned long idx = hashString(pista);
    HashEntry *cur = ht->buckets[idx];
    while (cur) {
        if (strcmp(cur->pista, pista) == 0) {
            /* atualiza suspeito */
            free(cur->suspeito);
            cur->suspeito = strdup(suspeito);
            return;
        }
        cur = cur->next;
    }
    /* não existe -> cria nova entrada no início da lista */
    HashEntry *ne = (HashEntry*) malloc(sizeof(HashEntry));
    if (!ne) { fprintf(stderr, "Erro aloc (inserirNaHash)\n"); exit(EXIT_FAILURE); }
    ne->pista = strdup(pista);
    ne->suspeito = strdup(suspeito);
    ne->next = ht->buckets[idx];
    ht->buckets[idx] = ne;
}

char* encontrarSuspeito(HashTable *ht, const char *pista) {
    unsigned long idx = hashString(pista);
    HashEntry *cur = ht->buckets[idx];
    while (cur) {
        if (strcmp(cur->pista, pista) == 0) return cur->suspeito;
        cur = cur->next;
    }
    return NULL;
}

void liberarHash(HashTable *ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        HashEntry *cur = ht->buckets[i];
        while (cur) {
            HashEntry *next = cur->next;
            free(cur->pista);
            free(cur->suspeito);
            free(cur);
            cur = next;
        }
    }
}

void contarPistasParaSuspeito(BSTNode *root, HashTable *ht, const char *acusado, int *contador) {
    if (!root) return;
    contarPistasParaSuspeito(root->left, ht, acusado, contador);
    char *sus = encontrarSuspeito(ht, root->pista);
    if (sus && strcmp(sus, acusado) == 0) {
        (*contador)++;
    }
    contarPistasParaSuspeito(root->right, ht, acusado, contador);
}

int verificarSuspeitoFinal(BSTNode *pistasColetadas, HashTable *ht, const char *acusado) {
    int contador = 0;
    contarPistasParaSuspeito(pistasColetadas, ht, acusado, &contador);
    return (contador >= 2) ? 1 : 0;
}

void liberarSala(Sala *r) {
    if (!r) return;
    /* liberamos recursivamente */
    liberarSala(r->esq);
    liberarSala(r->dir);
    free(r->nome);
    if (r->pista) free(r->pista);
    free(r);
}


int main(void) {
    /* Construção manual do mapa da mansão (fixo) */
    Sala *raiz = criarSala("Entrada", NULL);
    raiz->esq = criarSala("Sala de Estar", "Pegada de lama com fragmento de tecido");
    raiz->dir = criarSala("Cozinha", "Faca com resíduo estranho");
    raiz->esq->esq = criarSala("Biblioteca", "Livro rasgado com anotações");
    raiz->esq->dir = criarSala("Escritório", "Bilhete ameaçador");
    raiz->dir->esq = criarSala("Despensa", NULL);
    raiz->dir->dir = criarSala("Quarto", "Colar quebrado");
    raiz->esq->esq->esq = criarSala("Sótão", "Fio de cabelo loiro");
    raiz->esq->esq->dir = criarSala("Banheiro", NULL);

    /* Monta a tabela hash com associações pista -> suspeito (definidas por regras no código) */
    HashTable ht;
    inicializarHash(&ht);

    /* Regras codificadas: cada pista mapeia para um suspeito */
    inserirNaHash(&ht, "Pegada de lama com fragmento de tecido", "Sr. Verde");
    inserirNaHash(&ht, "Faca com resíduo estranho", "Sra. Rosa");
    inserirNaHash(&ht, "Livro rasgado com anotações", "Prof. Azul");
    inserirNaHash(&ht, "Bilhete ameaçador", "Sr. Verde");
    inserirNaHash(&ht, "Colar quebrado", "Sra. Rosa");
    inserirNaHash(&ht, "Fio de cabelo loiro", "Srta. Amarela");
    /* Note: algumas salas não têm pistas; mapa fixo, sem inserção dinâmica de salas */

    BSTNode *pistasColetadas = NULL;

    /* Início da interface: explicação curta */
    printf("Bem-vindo a Detective Quest (versão C)!\n");
    printf("Explore a mansão e colete pistas. Ao final, acuse um suspeito.\n");
    printf("Regras: para que a acusação seja aceita, pelo menos 2 pistas coletadas devem apontar para o acusado.\n");

    /* Exploração interativa */
    explorarSalas(raiz, &pistasColetadas, &ht);

    /* Mostrar as pistas coletadas */
    printf("\nPistas que você coletou (ordenadas):\n");
    if (pistasColetadas == NULL) {
        printf("Nenhuma pista coletada.\n");
    } else {
        imprimirPistasInOrder(pistasColetadas);
    }

    /* Se não coletou ao menos 1 pista, ainda permite acusar, mas provavelmente falhará */
    char buffer[128];
    printf("\nQuem você acusa? Digite o nome completo do suspeito (ex.: 'Sr. Verde'): ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Entrada inválida. Encerrando.\n");
    } else {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Nenhum suspeito informado. Encerrando.\n");
        } else {
            int correto = verificarSuspeitoFinal(pistasColetadas, &ht, buffer);
            if (correto) {
                printf("\nResultado: ACUSACAO ACEITA!\n");
                printf("Pelo menos duas pistas coletadas apontam para %s. Caso resolvido!\n", buffer);
            } else {
                printf("\nResultado: ACUSACAO REJEITADA.\n");
                printf("Menos de duas pistas coletadas apontam para %s. Você falhou em sustentar a acusação.\n", buffer);
            }
        }
    }

    /* Limpeza de memória */
    liberarBST(pistasColetadas);
    liberarHash(&ht);
    liberarSala(raiz);

    printf("\nObrigado por jogar! Até a próxima.\n");
    return 0;
}
