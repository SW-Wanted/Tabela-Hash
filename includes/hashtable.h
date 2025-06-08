#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no No;
typedef struct hashTable HashTable;

HashTable* criarHashTable(int tamanho);
void inserirChave(HashTable* th, int chave);
bool removerChave(HashTable* th, int chave);
bool pesquisarChave(HashTable* th, int chave);
void imprimirChaves(HashTable* th);
void liberarHashTable(HashTable* th);

#endif