#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"
#include <stdio.h>

tJogada LeJogada() {
    tJogada jogada;
    scanf("%d %d%*c", &jogada.x, &jogada.y);
    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) {
    if (EhPosicaoValidaTabuleiro(jogada.x, jogada.y)) return 1;
    return 0;
}
