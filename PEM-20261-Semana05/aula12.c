#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

float processarHierarquia(Pasta *d, int index, int nivel_atual, int limite_profundidade) {
    if (index == -1 || nivel_atual > limite_profundidade) return 0;

    Pasta *p = &d[index];
    p->tamanho_total = p->tamanho_proprio;

    for (int i = 0; i < p->qtd_sub; i++) {
        p->tamanho_total += processarHierarquia(d, p->subpastas_indices[i], nivel_atual + 1, limite_profundidade);
    }

    for (int i = 0; i < nivel_atual; i++) printf("  ");
    printf("|-- %s [%.2f GB]", p->nome, p->tamanho_total);
    if (p->tamanho_total > LIMITE_ALERTA) printf("GARGALO DETECTADO");

    return p->tamanho_total;
}

int main() {
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1;
    drive[0].subpastas_indices[1] = 2;

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3;

    strcpy(drive[2].nome, "Backups");
    drive[2].tamanho_proprio = 350.0;
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub = 0;

    int limite;
    scanf("%d", &limite);

    clock_t t = clock();
    processarHierarquia(drive, 0, 0, limite);
    t = clock() - t;
    double tempo = ((double)t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo);

    return 0;
}