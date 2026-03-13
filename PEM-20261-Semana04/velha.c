#include <stdio.h>

#define VAZIO ' '

char tabuleiro[3][3];
char jogador_atual;
int vencedor;

void inicializar() {
int i, j;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
tabuleiro[i][j] = VAZIO;
jogador_atual = 'X';
vencedor = 0;
}

void exibir() {
int i;
printf("\n");
for (i = 0; i < 3; i++) {
printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
if (i < 2) printf("-+-+-+-+-\n");
}
printf("\n");
}

int verificar() {
int i;
for (i = 0; i < 3; i++) {
if (tabuleiro[i][0] == jogador_atual && tabuleiro[i][1] == jogador_atual && tabuleiro[i][2] == jogador_atual) return 1;
if (tabuleiro[0][i] == jogador_atual && tabuleiro[1][i] == jogador_atual && tabuleiro[2][i] == jogador_atual) return 1;
}
if (tabuleiro[0][0] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][2] == jogador_atual) return 1;
if (tabuleiro[0][2] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][0] == jogador_atual) return 1;
return 0;
}

int espacos() {
int i, j, c = 0;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
if (tabuleiro[i][j] == VAZIO) c++;
return c;
}

int main() {
int linha, coluna;
inicializar();
while (espacos() > 0 && !vencedor) {
exibir();
printf("Jogador %c - linha (1-3): ", jogador_atual);
scanf("%d", &linha);
printf("Jogador %c - coluna (1-3): ", jogador_atual);
scanf("%d", &coluna);
linha--; coluna--;
if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != VAZIO) {
printf("Posicao invalida! Tente novamente.\n");
continue;
}
tabuleiro[linha][coluna] = jogador_atual;
vencedor = verificar();
if (!vencedor) jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
}
exibir();
if (vencedor) printf("O jogador %c venceu!\n", jogador_atual);
else printf("O jogo terminou em empate.\n");
return 0;
}
