#include "locadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 256

tLocadora* CriarLocadora () {
    tLocadora * locadora = (tLocadora*) malloc(sizeof(tLocadora));
    if (locadora == NULL) {
        printf("Alocacao incorreta na locadora\n");
        exit(1);
    }

    locadora->filme = NULL;
    locadora->numFilmes = 0;
    locadora->lucro = 0;
    return locadora;
}

void DestruirLocadora (tLocadora* locadora) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        DestruirFilme(locadora->filme[i]);
    }

    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) return 1;
    }
    return 0;
}

void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme) {
    if (VerificarFilmeCadastrado(locadora, filme->codigo) == 0) {
        locadora->filme[locadora->numFilmes] = filme;
        locadora->numFilmes++;
    } 
}

void LerCadastroLocadora (tLocadora* Locadora) {
    int codigo = 0;
    scanf("%d,", &codigo);
    tFilme * filme = CriarFilme();
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(Locadora, filme);
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        for (int j = 0; j < quantidadeCodigos; j++) {
            if (EhMesmoCodigoFilme(locadora->filme[i], codigos[j])) {
                locadora->filme[i]->qtdAlugada++;
                locadora->filme[i]->qtdEstoque--;
            }
        }
    }
}

void LerAluguelLocadora (tLocadora* locadora) {
    int codigos[MAX_MOVIES], i = 0;
    while (scanf("%d", codigos[i]) == 1) { 
        i++;
    }

    AlugarFilmesLocadora(locadora, codigos, i);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
        for (int i = 0; i < locadora->numFilmes; i++) {
        for (int j = 0; j < quantidadeCodigos; j++) {
            if (EhMesmoCodigoFilme(locadora->filme[i], codigos[j])) {
                locadora->filme[i]->qtdAlugada--;
                locadora->filme[i]->qtdEstoque++;
            }
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora) {
    LerAluguelLocadora(locadora);
}

int comparacao (const void *a, const void *b) {
    if (*(char*)a > *(char*)b) return 1;
    else if (*(char*)a < *(char*)b) return -1;
    else return 0;
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora) {
    tFilme filmeTemp;
    qsort(locadora->filme, locadora->numFilmes, sizeof(locadora->filme), comparacao);
}

void ConsultarEstoqueLocadora (tLocadora* locadora) {
    int estoque = 0;
    for (int i = 0; i < locadora->numFilmes; i++) {
        estoque += locadora->filme[i]->qtdEstoque;
    }
    printf("%d", estoque);
}

void ConsultarLucroLocadora (tLocadora* locadora) {
    printf("%d", locadora->lucro);
}