#include "../includes/hashtable.h"

#define MAX_WORD 100

// Codigos de cor ANSI
#define RESET   "\033[0m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

void limparTela() {
    system("cls");
}

void pausar() {
    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
    getchar();
}
void menuHashTable() {
    int size, op, key;
    limparTela();
    printf(CYAN "\nDigite o tamanho da Hash Table: " RESET);
    while (scanf("%d", &size) != 1) {
        printf(RED "Entrada invalida! Digite um numero para o tamanho: " RESET);
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    HashTable* ht = criarHashTable(size);

    do {
        limparTela();
        printf(BLUE "====== MENU HASH TABLE ======\n" RESET);
        printf(WHITE "1. Inserir chave\n" RESET);
        printf(WHITE "2. Remover chave\n" RESET);
        printf(WHITE "3. Imprimir chaves\n" RESET);
        printf(WHITE "4. Pesquisar chave\n" RESET);
        printf(WHITE "5. Voltar ao menu principal\n" RESET);
        printf(CYAN "Escolha uma opcao: " RESET);

        if (scanf("%d", &op) != 1) {
            printf(RED "Entrada invalida! Por favor, digite um numero.\n" RESET);
            while (getchar() != '\n');
            op = -1;
            pausar();
            continue;
        }
        while (getchar() != '\n');

        switch (op) {
            case 1:
                printf("Digite a chave para inserir: ");
                if (scanf("%d", &key) != 1) {
                    printf(RED "Entrada invalida! Digite um numero para a chave.\n" RESET);
                    while (getchar() != '\n');
                    pausar();
                    break;
                }
                while (getchar() != '\n');
                inserirChave(ht, key);
                printf(GREEN "Chave %d inserida\n" RESET, key);
                pausar();
                break;
            case 2:
                printf("Digite a chave para remover: ");
                if (scanf("%d", &key) != 1) {
                    printf(RED "Entrada invalida! Digite um numero para a chave.\n" RESET);
                    while (getchar() != '\n');
                    pausar();
                    break;
                }
                while (getchar() != '\n');
                if (removerChave(ht, key))
                    printf(GREEN "Chave %d removida\n" RESET, key);
                else
                    printf(RED "Chave %d nao encontrada\n" RESET, key);
                pausar();
                break;
            case 3:
                printf(CYAN "Chaves na Hash Table\n" RESET);
                imprimirChaves(ht);
                pausar();
                break;
            case 4:
                printf("Digite a chave para pesquisar: ");
                if (scanf("%d", &key) != 1) {
                    printf(RED "Entrada invalida! Digite um numero para a chave.\n" RESET);
                    while (getchar() != '\n');
                    pausar();
                    break;
                }
                while (getchar() != '\n');
                if (pesquisarChave(ht, key))
                    printf(GREEN "Chave %d encontrada\n" RESET, key);
                else
                    printf(RED "Chave %d nao encontrada\n" RESET, key);
                pausar();
                break;
            case 5:
                printf(YELLOW "Voltando ao menu principal\n" RESET);
                pausar();
                break;
            default:
                printf(RED "Opcao invalida\n" RESET);
                pausar();
        }
    } while (op != 5);

    liberarHashTable(ht);
}

int main() {
    menuHashTable();
    return 0;
}
