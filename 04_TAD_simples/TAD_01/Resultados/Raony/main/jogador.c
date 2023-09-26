#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

#define PECA_DO_1 'X'
#define PECA_DO_2 '0'

tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    printf("Jogador %d\n", jogador.id);
    tJogada jogada = LeJogada();
    int x = jogada.x, y = jogada.y;

    if (jogada.sucesso) {
        if (EhPosicaoValidaTabuleiro(x, y) && 
            !EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x, y, jogador.id)) {
            printf("Jogada [%d,%d]!\n", x, y);
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
            return tabuleiro;

        } else if (EhPosicaoValidaTabuleiro(x, y) && 
                   EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x, y, jogador.id)) {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
                tabuleiro = JogaJogador(jogador, tabuleiro);
   
        } else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            tabuleiro = JogaJogador(jogador, tabuleiro);
        }
    }

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    switch (jogador.id) {
    case 1:
        for (int i = 0; i <= 2; i++) {
            if ( (tabuleiro.posicoes[i][0] == PECA_DO_1 && // horizontal
                  tabuleiro.posicoes[i][1] == PECA_DO_1 && 
                  tabuleiro.posicoes[i][2] == PECA_DO_1) ||

                 (tabuleiro.posicoes[0][i] == PECA_DO_1 && // vertical
                  tabuleiro.posicoes[1][i] == PECA_DO_1 && 
                  tabuleiro.posicoes[2][i] == PECA_DO_1) ) {
                return 1;
            }
        }

        if (tabuleiro.posicoes[0][0] == PECA_DO_1 && // diagonal
                tabuleiro.posicoes[1][1] == PECA_DO_1 && 
                tabuleiro.posicoes[2][2] == PECA_DO_1 ||
            
                tabuleiro.posicoes[0][2] == PECA_DO_1 && 
                tabuleiro.posicoes[1][1] == PECA_DO_1 && 
                tabuleiro.posicoes[2][0] == PECA_DO_1) {
                return 1;
            }
        break;

    case 2:
        for (int i = 0; i <= 2; i++) {
            if ( (tabuleiro.posicoes[i][0] == PECA_DO_2 && // horizontal
                  tabuleiro.posicoes[i][1] == PECA_DO_2 && 
                  tabuleiro.posicoes[i][2] == PECA_DO_2) ||

                 (tabuleiro.posicoes[0][i] == PECA_DO_2 && // vertical
                  tabuleiro.posicoes[1][i] == PECA_DO_2 && 
                  tabuleiro.posicoes[2][i] == PECA_DO_2) ) {
                return 1;
            }
        }
        if (tabuleiro.posicoes[0][0] == PECA_DO_2 && // diagonal
                tabuleiro.posicoes[1][1] == PECA_DO_2 && 
                tabuleiro.posicoes[2][2] == PECA_DO_2 ||
            
                tabuleiro.posicoes[0][2] == PECA_DO_2 && 
                tabuleiro.posicoes[1][1] == PECA_DO_2 && 
                tabuleiro.posicoes[2][0] == PECA_DO_2) {
                return 1;
        }
        break;
    }
    return 0;
}