#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2
#define PECA_1 'x'
#define PECA_2 '0'
#define PECA_VAZIA '-'

tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada = LeJogada();
    int x = ObtemJogadaX(jogada);
    int y = ObtemJogadaY(jogada);
    
    switch (jogador.id) {
    case 1:
        tabuleiro.posicoes[x][y] = PECA_1;
        break;

    case 2:
        tabuleiro.posicoes[x][y] = PECA_2;
        break;
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    switch (jogador.id) {
    case 1:
        for (int i = 0; i <= 2; i++) {
            if ( (tabuleiro.posicoes[i][0] == PECA_1 && // horizontal
                  tabuleiro.posicoes[i][1] == PECA_1 && 
                  tabuleiro.posicoes[i][2] == PECA_1) ||

                 (tabuleiro.posicoes[0][i] == PECA_1 && // vertical
                  tabuleiro.posicoes[1][i] == PECA_1 && 
                  tabuleiro.posicoes[2][i] == PECA_1) ) return 1;
        }

            if (tabuleiro.posicoes[0][0] == PECA_1 && // diagonal
                tabuleiro.posicoes[1][1] == PECA_1 && 
                tabuleiro.posicoes[2][2] == PECA_1 ||
            
                tabuleiro.posicoes[0][2] == PECA_1 && 
                tabuleiro.posicoes[1][1] == PECA_1 && 
                tabuleiro.posicoes[2][0] == PECA_1) return 1;
            return 0;
        break;
    }
}