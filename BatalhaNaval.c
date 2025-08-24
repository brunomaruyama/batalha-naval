#include <stdio.h>

#define TAM 10



// Função para validar posição
int podePosicionar(int tabuleiro[TAM][TAM], int x, int y) {
    if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
        return 0; // Fora dos limites
    }
    // Permite sobrepor destroyer (3), mas não outros navios
    if (tabuleiro[x][y] != 0 && tabuleiro[x][y] != 3) {
        return 0; // Já tem outro navio
    }
    return 1; // Válido
}

int main () {
    int tabuleiro[TAM][TAM] = {0};
    int destroyerX[3] = {3, 3, 3};
    int cone[5][5]= {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}
};

int cruz[5][5]= {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int octaedro[5][5]= {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};
    // Destroyer na linha 3
    for (int i = 0; i < 3; i++) {
        int x = 3, y = 4 + i;
        if (podePosicionar(tabuleiro, x, y)) {
            tabuleiro[x][y] = destroyerX[i];
        }
    }

    // Submarino na coluna 7
    for (int i = 0; i < 3; i++) {
        int x = 2 + i, y = 7;
        if (podePosicionar(tabuleiro, x, y)) {
            tabuleiro[x][y] = destroyerX[i];
        }
    }

    // Destroyer na diagonal
    for (int i = 0; i < 3; i++) {
        int x = 7 + i, y = 2 + i;
        if (podePosicionar(tabuleiro, x, y)) {
            tabuleiro[x][y] = destroyerX[i];
        }
    }

    // Posicionando o cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int x = 5 + i, y = 2 + j;
                if (podePosicionar(tabuleiro, x, y)) {
                    if (tabuleiro[x][y]==3) {
                        tabuleiro[x][y] = 5; // Representa o cone sobre o destroyer
                    }
                    else {
                        tabuleiro[x][y] = 1; // Representa o octaedro
                    }           
                }     
            }
        }
    }

    // Posicionando o cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int x = 2 + i, y = 5 + j;
                if (podePosicionar(tabuleiro, x, y)) {
                    if (tabuleiro[x][y]==3) {
                        tabuleiro[x][y] = 5; // Representa o cone sobre o destroyer
                    }
                    else {
                        tabuleiro[x][y] = 1; // Representa o octaedro
                    }        
                }
            }
        }
    }

    // Posicionando o octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int x = 0 + i, y = 0 + j;
                if (podePosicionar(tabuleiro, x, y)) {
                    if (tabuleiro[x][y] == 3) {
                        tabuleiro[x][y] = 5; // Representa o cone sobre o destroyer
                    }
                    else {
                        tabuleiro[x][y] = 1; // Representa o octaedro
                    }
                }
            }
        }
    }

    printf("Tabuleiro do jogo Batalha Naval:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}
