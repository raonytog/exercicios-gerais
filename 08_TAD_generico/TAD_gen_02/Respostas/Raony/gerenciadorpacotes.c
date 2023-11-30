#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes {
    tPacote **pacotes;
    int qtdPacotes;
};

tGerenciador* CriaGerenciador() {
    tGerenciador * ger = malloc(sizeof(tGerenciador));
    ger->pacotes = NULL;
    ger->qtdPacotes = 0;
    return ger;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    int i = geren->qtdPacotes;
    (geren->qtdPacotes)++;
    geren->pacotes = realloc(geren->pacotes, geren->qtdPacotes * sizeof(tPacote));
    geren->pacotes[i] = realloc(geren->pacotes, sizeof(tPacote));
}


void DestroiGerenciador(tGerenciador* geren) {
    for (int i = 0; i < geren->qtdPacotes; i++)
        DestroiPacote(geren->pacotes[i]);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {
    ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren) {
    for (int i = 0; i < geren->qtdPacotes; i++)
        ImprimirPacoteNoIndice(geren, i);
}