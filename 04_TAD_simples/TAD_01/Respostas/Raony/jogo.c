#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"
#include "jogo.h"
#include <stdio.h>

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

    tJogada jogada;

    tTabuleiro tabuleiro;
    tabuleiro = jogo.tabuleiro;

    tJogador p1, p2;
    p1 = jogo.jogador1;
    p2 = jogo.jogador2;


    int rodada = 0, jogadaTronxa = 0, ultimoJogador = 0, flagResetou = 0;
    while (TRUE) {
        if (flagResetou) {
            jogo = CriaJogo();
            tabuleiro = jogo.tabuleiro;
            flagResetou = 0;
        }

        ultimoJogador = 0;
        jogadaTronxa = 0;
        if (rodada%2 == 0) {    //player 1
            ultimoJogador = 1;
            printf("Jogador 1\n");
            printf("Digite uma posicao (x e y):");
            jogada = LeJogada();
            printf("\n");

            if (FoiJogadaBemSucedida(jogada)) {
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, p1.id, 
                            ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                ImprimeTabuleiro(tabuleiro);
            } else jogadaTronxa = 1;

        } else {    //player 2
            ultimoJogador = 2;
            printf("Jogador 2\n");
            printf("Digite uma posicao (x e y):");
            jogada = LeJogada();
            printf("\n");

            if (FoiJogadaBemSucedida(jogada) && EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, p2.id, 
                            ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                ImprimeTabuleiro(tabuleiro);
            } else jogadaTronxa = 1;
        }


        if (jogadaTronxa) {
            printf("Posicao invalida ");
            if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) && 
                EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                printf("(OCUPADA ");
            } else printf("(FORA DO TABULEIRO ");

            printf("- [%d,%d] )\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }

        // caso de vitoria ou fim de jogo
        if (VenceuJogador(p1, tabuleiro) || VenceuJogador(p2, tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", ultimoJogador);
            printf("Jogar novamente? (s,n) ");
            
            if (ContinuaJogo()) {
                flagResetou = 1;
                rodada = 0;
            } else break;;
        } 

        if (AcabouJogo) break;

        rodada++;
    }
}

int AcabouJogo(tJogo jogo) {
    if (TemPosicaoLivreTabuleiro(jogo.tabuleiro)) return 0;
    return 1;
}

int ContinuaJogo() {
    char decisao;
    scanf("%c%*c", &decisao);
    if (decisao == 's') return 1;
    return 0;
}