#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"

tJogada LeJogada() {
    tJogada jogada;
    scanf("%d %d", jogada.x, jogada.y);
    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) {
    if (ObtemJogadaX(jogada) >= 0 && ObtemJogadaX(jogada) <= 2 &&
        ObtemJogadaY(jogada) >= 0 && ObtemJogadaY(jogada) <= 2) {
        return 1;
       }

    return 0;
}
