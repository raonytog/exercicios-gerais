/*
Programa que, dado uma matriz de tamanho x e y com valores 0 (vazio) e 1 (parede), 
uma coordenada inicial e outra final e uma ordem de movimentos, imprime as coordenadas
do trajeto até acoordenada final se for possível.
Raony Togneri
17/08/2023
*/

#include <stdio.h>

#define MAX 256

#define BAIXO y+1
#define CIMA y-1
#define ESQUERDA x-1
#define DIREITA x+1 
#define VAZIO 0
#define PAREDE 1

typedef struct {
    int numLinhas;
    int numColunas;
    char prioridade[4];
    int mapa[MAX][MAX];
} tJogo;

typedef struct {
    int x;
    int xF;
    int y;
    int yF;
} tJogador;

tJogo LeJogo();
tJogo LePrioridade();
tJogador InicializaJogador();
void RealizaJogo(tJogo jogo, tJogador jogador);

int main () {
    tJogo jogo = LeJogo();
    tJogador jogador = InicializaJogador();
    jogo = LePrioridade();
    // RealizaJogo(jogo, jogador);
    
    return 0;
}

tJogo LeJogo() {
    tJogo jogo;
    scanf("%d %d\n", &jogo.numLinhas, &jogo.numColunas);

    for (int i = 0; i < jogo.numLinhas; i++) {
        for(int j = 0; j < jogo.numColunas; j++) {
            scanf("%d%*c", &jogo.mapa[i][j]);
        }
    }

    return jogo;
}

tJogo LePrioridade() {
    tJogo jogo;
    char prioridade[4];
    scanf("%c%c%c%c", &prioridade[0], &prioridade[1], &prioridade[2], &prioridade[3]);
    
    for (int i = 0; i != 4; i++) {
        jogo.prioridade[i] = prioridade[i];
    }

    return jogo;
}

tJogador InicializaJogador() {
    tJogador jogador;
    scanf("%d %d\n", &jogador.x, &jogador.y);
    scanf("%d %d\n", &jogador.xF, &jogador.yF);
    return jogador;
}
