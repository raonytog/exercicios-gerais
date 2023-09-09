#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"

#define TAM_TABULEIRO 3
#define PECA_1 'x'
#define PECA_2 '0'
#define PECA_VAZIA '-'

tTabuleiro CriaTabuleiro() {
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = PECA_1;
    tabuleiro.peca2 = PECA_2;
    tabuleiro.pecaVazio = PECA_VAZIA;

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro.posicoes[i][j] = PECA_VAZIA;;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y) && EhPosicaoValidaTabuleiro(x, y)) {
        switch (peca){
            case 1:
                if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x, y, peca)) {
                    tabuleiro.posicoes[x][y] = PECA_1;
                }
                break;

            case 2:
                if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x, y, peca)) {
                    tabuleiro.posicoes[x][y] = PECA_2;
                }
                break;
        }
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro.posicoes[i][j] = PECA_VAZIA) return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    switch (peca) {
    case 1:
        if (PECA_1 == tabuleiro.posicoes[x][y]) return 1;
        break;

    case 2:
        if (PECA_2 == tabuleiro.posicoes[x][y]) return 1;
        break;
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    if (tabuleiro.posicoes == tabuleiro.pecaVazio) return 1;
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2) return 1;
    return 0;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("\t");
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
    }
}