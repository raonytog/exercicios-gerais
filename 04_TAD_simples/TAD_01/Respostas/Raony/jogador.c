#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"
#include <stdio.h>

#define PE_X 'X'
#define PE_0 '0'

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
            if ( (tabuleiro.posicoes[i][0] == PE_X && // horizontal
                  tabuleiro.posicoes[i][1] == PE_X && 
                  tabuleiro.posicoes[i][2] == PE_X) ||

                 (tabuleiro.posicoes[0][i] == PE_X && // vertical
                  tabuleiro.posicoes[1][i] == PE_X && 
                  tabuleiro.posicoes[2][i] == PE_X) ) {
                return 1;
            }
        }

        if (tabuleiro.posicoes[0][0] == PE_X && // diagonal
                tabuleiro.posicoes[1][1] == PE_X && 
                tabuleiro.posicoes[2][2] == PE_X ||
            
                tabuleiro.posicoes[0][2] == PE_X && 
                tabuleiro.posicoes[1][1] == PE_X && 
                tabuleiro.posicoes[2][0] == PE_X) {
                return 1;
            }
        break;

    case 2:
        for (int i = 0; i <= 2; i++) {
            if ( (tabuleiro.posicoes[i][0] == PE_0 && // horizontal
                  tabuleiro.posicoes[i][1] == PE_0 && 
                  tabuleiro.posicoes[i][2] == PE_0) ||

                 (tabuleiro.posicoes[0][i] == PE_0 && // vertical
                  tabuleiro.posicoes[1][i] == PE_0 && 
                  tabuleiro.posicoes[2][i] == PE_0) ) {
                return 1;
            }
        }
        if (tabuleiro.posicoes[0][0] == PE_0 && // diagonal
                tabuleiro.posicoes[1][1] == PE_0 && 
                tabuleiro.posicoes[2][2] == PE_0 ||
            
                tabuleiro.posicoes[0][2] == PE_0 && 
                tabuleiro.posicoes[1][1] == PE_0 && 
                tabuleiro.posicoes[2][0] == PE_0) {
                return 1;
        }
        break;
    }
    return 0;
}