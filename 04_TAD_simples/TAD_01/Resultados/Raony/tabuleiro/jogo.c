#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"

#define TRUE 1
#define FALSE 0

tJogo CriaJogo() {
    tJogo jogo;
    tJogador player1, player2;
    player1 = CriaJogador(1);
    player2 = CriaJogador(2);

    tTabuleiro tabuleiro = CriaTabuleiro();

    jogo.tabuleiro = tabuleiro;
    jogo.jogador1 = player1;
    jogo.jogador2 = player2;
    return jogo;
}

void ComecaJogo(tJogo jogo) {
    jogo = CriaJogo();
    while (TRUE) {
        
    }
}

int AcabouJogo(tJogo jogo) {
    if (TemPosicaoLivreTabuleiro(jogo.tabuleiro)) return 0;
    return 1;
}

int ContinuaJogo() {
    char resposta;
    scanf("%c", &resposta);
    if (resposta == 's') return 1;
    else if (resposta == 'n') return 0;
}