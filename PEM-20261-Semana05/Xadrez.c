// Nome: Nathan Lucas Lima Castro
// RA: 2040482522006
// Professor: Carlos Verissimo
// Data de entrega: 19/03/2026
// Disciplina: Programacao Estruturada e Modular
// Atividade: Semana 5 - Xeque Pastor

#include <stdio.h>
#include <string.h>

#define LINHAS 8
#define COLUNAS 8
#define TAM_PECA 4

char tabuleiro[LINHAS][COLUNAS][TAM_PECA];

// inicia o tabuleiro com as pecas nas posicoes iniciais
void iniciarTabuleiro() {
    strcpy(tabuleiro[0][0], "tP1");
    strcpy(tabuleiro[0][1], "cP2");
    strcpy(tabuleiro[0][2], "bP3");
    strcpy(tabuleiro[0][3], "dP4");
    strcpy(tabuleiro[0][4], "rP5");
    strcpy(tabuleiro[0][5], "bP6");
    strcpy(tabuleiro[0][6], "cP7");
    strcpy(tabuleiro[0][7], "tP8");

    strcpy(tabuleiro[1][0], "PP1");
    strcpy(tabuleiro[1][1], "PP2");
    strcpy(tabuleiro[1][2], "PP3");
    strcpy(tabuleiro[1][3], "PP4");
    strcpy(tabuleiro[1][4], "PP5");
    strcpy(tabuleiro[1][5], "PP6");
    strcpy(tabuleiro[1][6], "PP7");
    strcpy(tabuleiro[1][7], "PP8");

    int i, j;
    for(i = 2; i <= 5; i++) {
        for(j = 0; j < COLUNAS; j++) {
            strcpy(tabuleiro[i][j], "...");
        }
    }

    strcpy(tabuleiro[6][0], "PB1");
    strcpy(tabuleiro[6][1], "PB2");
    strcpy(tabuleiro[6][2], "PB3");
    strcpy(tabuleiro[6][3], "PB4");
    strcpy(tabuleiro[6][4], "PB5");
    strcpy(tabuleiro[6][5], "PB6");
    strcpy(tabuleiro[6][6], "PB7");
    strcpy(tabuleiro[6][7], "PB8");

    strcpy(tabuleiro[7][0], "TB1");
    strcpy(tabuleiro[7][1], "CB2");
    strcpy(tabuleiro[7][2], "BB3");
    strcpy(tabuleiro[7][3], "DB4");
    strcpy(tabuleiro[7][4], "RB5");
    strcpy(tabuleiro[7][5], "BB6");
    strcpy(tabuleiro[7][6], "CB7");
    strcpy(tabuleiro[7][7], "TB8");
}

// mostra o tabuleiro no terminal
void mostrarTabuleiro() {
    int i, j;
    for(i = 0; i < LINHAS; i++) {
        printf("%d ", 8 - i);
        for(j = 0; j < COLUNAS; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// move uma peca de uma posicao para outra
void moverPeca(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    strcpy(tabuleiro[linhaDestino][colunaDestino], tabuleiro[linhaOrigem][colunaOrigem]);
    strcpy(tabuleiro[linhaOrigem][colunaOrigem], "...");
}

// jogada 1 peao branco e4 e peao preto e5
void jogada1() {
    printf("Jogada 1\n");
    printf("Brancas jogam e4\n");
    moverPeca(6, 4, 4, 4);
    mostrarTabuleiro();
    printf("Pretas jogam e5\n");
    moverPeca(1, 4, 3, 4);
    mostrarTabuleiro();
}

// jogada 2 bispo branco c4 e cavalo preto c6
void jogada2() {
    printf("Jogada 2\n");
    printf("Brancas jogam Bc4\n");
    moverPeca(7, 2, 4, 2);
    mostrarTabuleiro();
    printf("Pretas jogam Cc6\n");
    moverPeca(0, 1, 2, 2);
    mostrarTabuleiro();
}

// jogada 3 dama branca h5 e cavalo preto f6
void jogada3() {
    printf("Jogada 3\n");
    printf("Brancas jogam Dh5\n");
    moverPeca(7, 3, 3, 7);
    mostrarTabuleiro();
    printf("Pretas jogam Cf6\n");
    moverPeca(0, 6, 2, 5);
    mostrarTabuleiro();
}

// jogada 4 dama captura peao em f7 xeque mate
void checkematepastor() {
    printf("Jogada 4\n");
    printf("Brancas capturam peao em f7 Xeque Mate Dxf7\n");
    moverPeca(3, 7, 1, 5);
    mostrarTabuleiro();
}

int main() {
    iniciarTabuleiro();
    mostrarTabuleiro();
    jogada1();
    jogada2();
    jogada3();
    checkematepastor();
    return 0;
}
