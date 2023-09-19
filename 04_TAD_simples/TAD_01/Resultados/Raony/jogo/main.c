#include <stdio.h>
#include "jogo.h"

int main () {
    while (1) {
        tJogo jogo = CriaJogo();
        ComecaJogo(jogo);
        printf("Jogar novamente? (s,n)\n");

        if (!ContinuaJogo()) break;
    }
    return 0;
}