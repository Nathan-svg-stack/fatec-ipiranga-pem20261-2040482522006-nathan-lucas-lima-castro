#include <stdio.h>

#define MAX 10

int idProduto[MAX];

void listar() {
    printf("\n===== LISTA DE PRODUTOS =====\n");
    int achou = 0;
    for (int i = 0; i < MAX; i++) {
        if (idProduto[i] != 0) {
            printf("Posicao [%d] -> ID: %d\n", i, idProduto[i]);
            achou = 1;
        }
    }
    if (!achou) printf("Nenhum produto cadastrado.\n");
    printf("=============================\n");
}

void incluir() {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    for (int i = 0; i < MAX; i++) {
        if (idProduto[i] == 0) {
            idProduto[i] = id;
            printf("Produto ID %d incluido na posicao [%d].\n", id, i);
            return;
        }
    }
    printf("Array cheio!\n");
}

void consultar() {
    int id;
    printf("Digite o ID a consultar: ");
    scanf("%d", &id);
    for (int i = 0; i < MAX; i++) {
        if (idProduto[i] == id) {
            printf("Produto ID %d encontrado na posicao [%d].\n", id, i);
            return;
        }
    }
    printf("Produto ID %d nao encontrado.\n", id);
}

void alterar() {
    int id, novo;
    printf("Digite o ID a alterar: ");
    scanf("%d", &id);
    for (int i = 0; i < MAX; i++) {
        if (idProduto[i] == id) {
            printf("Digite o novo ID: ");
            scanf("%d", &novo);
            idProduto[i] = novo;
            printf("ID alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto ID %d nao encontrado.\n", id);
}

void excluir() {
    int id;
    printf("Digite o ID a excluir: ");
    scanf("%d", &id);
    for (int i = 0; i < MAX; i++) {
        if (idProduto[i] == id) {
            idProduto[i] = 0;
            printf("Produto ID %d excluido com sucesso!\n", id);
            return;
        }
    }
    printf("Produto ID %d nao encontrado.\n", id);
}

int main() {
    int opcao;
    do {
        printf("\n===== MENU =====\n");
        printf("1 - Incluir\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Listar todos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: incluir();   break;
            case 2: consultar(); break;
            case 3: alterar();   break;
            case 4: excluir();   break;
            case 5: listar();    break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
