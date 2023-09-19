#include <stdio.h>
#include "tabuleiro.h"

typedef struct{
    int x;
    int y;
    int sucesso;
} tJogada;

int FoiJogadaBemSucedida(tJogada jogada);

/**
 * Lê uma jogada e retorna uma estrutura do tipo tJogada.
 * 
 * @return a jogada lida.
 */
tJogada LeJogada() {
    tJogada jogada;
    scanf("%d %d", &jogada.x, &jogada.y);
    if (FoiJogadaBemSucedida(jogada)){
        jogada.sucesso = 1;
    } else
        jogada.sucesso = 0;
    return jogada;
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a jogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada jogada) {
    if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
        return 1;
    }
    return 0;
}