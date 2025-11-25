//estrutura de uma árvore binária 

//estrutura de um nó 
struct No {
    int dado; //valor armazenado no nó
    struct No* esquerda; //ponteiro para o filho esquerdo
    struct No* direita; //ponteiro para o filho direito
};

NULL = 0;

//altura da arvore
int altura(struct No* raiz) { //calcula a altura da árvore
    if (raiz == NULL) //se o nó for nulo, a altura é 0
        return 0;

    int alturaEsquerda = altura(raiz->esquerda); //altura do lado esquerdo = altura da subárvore esquerda
    int alturaDireita = altura(raiz->direita); //altura do lado direito = altura da subárvore direita
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita); //retorna 1 + a maior altura entre os dois lados
}

//profundidade da árvore 
int profundidade(struct No* raiz, struct No* alvo, int nivel) {
    if (raiz == NULL) //se o nó for nulo, a profundidade é 0
        return -1;
    
    if (raiz == alvo) //se o nó atual for o nó alvo, retorna o nível atual
        return nivel;

    int profundidadeEsquerda = profundidade(raiz->esquerda, alvo, nivel + 1); //procura na subárvore esquerda
    if (profundidadeEsquerda != -1) //se encontrou na subárvore esquerda
        return profundidadeEsquerda; //retorna a profundidade encontrada

    return profundidade(raiz->direita, alvo, nivel + 1); //procura na subárvore direita


}