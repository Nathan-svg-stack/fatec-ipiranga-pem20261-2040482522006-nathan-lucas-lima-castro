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

typedef struct {
    int index;
    int nivel;
} Frame;

void processarHierarquia(int raiz, int limite_profundidade) {
    Frame pilha[MAX_PASTAS * 10];
    int topo = 0;
    int ordem[MAX_PASTAS * 10];
    int niveis[MAX_PASTAS * 10];
    int total = 0;

    pilha[topo++] = (Frame){raiz, 0};

    while (topo > 0) {
        Frame f = pilha[--topo];
        if (f.index == -1 || f.nivel > limite_profundidade) continue;

        ordem[total] = f.index;
        niveis[total] = f.nivel;
        total++;

        Pasta *p = &drive[f.index];
        for (int i = p->qtd_sub - 1; i >= 0; i--) {
            pilha[topo++] = (Frame){p->subpastas_indices[i], f.nivel + 1};
        }
    }

    for (int i = total - 1; i >= 0; i--) {
        int idx = ordem[i];
        drive[idx].tamanho_total = drive[idx].tamanho_proprio;
        for (int j = 0; j < drive[idx].qtd_sub; j++) {
            int filho = drive[idx].subpastas_indices[j];
            drive[idx].tamanho_total += drive[filho].tamanho_total;
        }
    }

    for (int i = 0; i < total; i++) {
        int idx = ordem[i];
        int nivel = niveis[i];
        for (int j = 0; j < nivel; j++) printf("  ");
        printf("|-- %s [%.2f GB]", drive[idx].nome, drive[idx].tamanho_total);
        if (drive[idx].tamanho_total > LIMITE_ALERTA) printf("GARGALO DETECTADO");
        printf("\n");
    }
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

    strcpy(drive[2].nome, "Backupss");
    drive[2].tamanho_proprio = 350.0;
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub = 0;

    int limite;
    scanf("%d", &limite);

    clock_t t = clock();
    processarHierarquia(0, limite);
    t = clock() - t;
    double tempo = ((double)t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo);

    return 0;
}