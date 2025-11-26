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

//estrutura das salas
typedef struct Sala {
    char nome[50];
    char conteudoPista[100];
    int itemPista;
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




int main(){
    
    return 0;
}