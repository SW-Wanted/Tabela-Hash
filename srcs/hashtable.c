#include "../includes/hashtable.h"

// Estrutura para um no na cadeia
struct no {
    int chave;
    struct no* proximo;
};

// Estrutura para a tabela hash
struct hashTable {
    int tamanho;
    No** tabela;
};

// Cria uma nova tabela hash
HashTable* criarHashTable(int tamanho) {
    HashTable* th = (HashTable*)malloc(sizeof(HashTable));
    th->tamanho = tamanho;
    th->tabela = (No**)malloc(tamanho * sizeof(No*));
    int i;
    for (i = 0; i < tamanho; i++) {
        th->tabela[i] = NULL;
    }
    return th;
}

// Função de hashing simples
int hashing(int chave, int tamanho) {
    return chave % tamanho;
}

// Insere uma chave na tabela hash no final da lista
void inserirChave(HashTable* th, int chave) {
    int indice = hashing(chave, th->tamanho);
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->proximo = NULL;

    if (th->tabela[indice] == NULL) {
        th->tabela[indice] = novoNo;
    } else {
        No* atual = th->tabela[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

// Remove uma chave da tabela hash
bool removerChave(HashTable* th, int chave) {
    int indice = hashing(chave, th->tamanho);
    No* atual = th->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->chave == chave) {
            if (anterior == NULL) {
                th->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

// Busca uma chave na tabela hash
bool pesquisarChave(HashTable* th, int chave) {
    int indice = hashing(chave, th->tamanho);
    No* atual = th->tabela[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

// Imprime todas as chaves na tabela hash
void imprimirChaves(HashTable* th) {
    int i;
    printf("HashTable (%d baldes):\n", th->tamanho);
    for (i = 0; i < th->tamanho; i++) {
        printf("[%2d]: ", i);
        No* atual = th->tabela[i];
        while (atual != NULL) {
            printf("%d", atual->chave);
            if (atual->proximo != NULL) {
                printf(" -> ");
            }
            atual = atual->proximo;
        }
        printf(" -> NULL\n");
    }
}

// Libera a tabela hash
void liberarHashTable(HashTable* th) {
    int i;
    for (i = 0; i < th->tamanho; i++) {
        No* atual = th->tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(th->tabela);
    free(th);
}
