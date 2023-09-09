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

    int rodada = 0, jogadaTronxa = 0, ultimoJogador = 0;
    while (TRUE) {
        ultimoJogador = 0;
        jogadaTronxa = 0;

        // define quem é o jogador
        if (rodada%2 == 0) ultimoJogador = 1;
        else ultimoJogador = 2;

        printf("Jogador %d\n", ultimoJogador);
        printf("Digite uma posicao (x e y):");
        jogada = LeJogada();
        printf("\n");

        // se a jogada foi valida e nao ocupada
        if (FoiJogadaBemSucedida(jogada) && 
            EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {

            printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, ultimoJogador, 
                        ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            ImprimeTabuleiro(tabuleiro);
            jogo.tabuleiro = tabuleiro;
            rodada++;
        } else jogadaTronxa = 1; // se a jogada foi invalida por ocupacao ou limites

        if (jogadaTronxa) {
            printf("Posicao invalida ");
            if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) && 
                EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                printf("(OCUPADA ");
            } else printf("(FORA DO TABULEIRO ");
            printf("- [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }

        // caso de vitoria ou fim de jogo
        if (VenceuJogador(p1, tabuleiro) || VenceuJogador(p2, tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", ultimoJogador);
            printf("Jogar novamente? (s,n)\n");

            if (ContinuaJogo()) {   //reseta o jogo caso queira continuar
                jogo = CriaJogo();
                tabuleiro = jogo.tabuleiro;
                rodada = 0;
            } else break;
        } 

        if (AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            printf("Jogar novamente? (s,n)");
            if (ContinuaJogo()) {   //reseta o jogo caso queira continuar
                printf("\n");
                jogo = CriaJogo();
                tabuleiro = jogo.tabuleiro;
                rodada = 0;
            } else break;
        } 
    } 
}

int AcabouJogo(tJogo jogo) {
    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro)) return 1;
    return 0;
}

int ContinuaJogo() {
    char decisao;
    scanf("%c%*c", &decisao);
    if (decisao == 's') return 1;
    return 0;
}