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
    tJogada jogada;
    tTabuleiro tabuleiro;

    tJogador p1, p2;
    p1 = jogo.jogador1;
    p2 = jogo.jogador2;

    jogo = CriaJogo();
    tabuleiro = jogo.tabuleiro;

    int rodada = 0;
    while (TRUE) {

        if (rodada%2 == 0) {
            printf("Jogador 1\n");
            printf("Digite uma posicao (x e y):");
            jogada = LeJogada();
            printf("\n");

            if (FoiJogadaBemSucedida(jogada)) {
                ImprimeTabuleiro(tabuleiro);
                printf("Jogada [%d,%d]!", ObtemJogadaX(jogada), ObtemJogadaY(jogada));

            } else {
                printf("Posicao invalida ");
                if (!EstaLivrePosicaoTabuleiro) {
                    printf("(OCUPADA ");
                } else printf("(FORA DO TABULEIRO ");

                printf("- [%d,%d] )", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }


            MarcaPosicaoTabuleiro(tabuleiro, p1.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));

        } else {
            printf("Jogador 2\n");
            printf("Digite uma posicao (x e y):");
            jogada = LeJogada();
            printf("\n");

            MarcaPosicaoTabuleiro(tabuleiro, p2.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }

        // caso de vitoria ou fim de jogo
        if (VenceuJogador(p1, tabuleiro) || VenceuJogador(p2, tabuleiro)) {
            if (!ContinuaJogo()) break;
        }
        rodada++;
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