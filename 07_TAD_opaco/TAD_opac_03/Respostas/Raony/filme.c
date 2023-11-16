#include "filme.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Filme {
    char  nome[MAX_CARACTERES];
    int   codFilme;
    int   valor;
    int   qtdEstoque;
    int   qtdAlugada;
};

tFilme* CriarFilme() {
    tFilme * filme = malloc(sizeof(tFilme));
    filme->qtdAlugada = 0;
    return filme;
}

void LeFilme(tFilme *filme, int codigo) {
    scanf("%[^,],%d,%d", filme->nome, &filme->valor, &filme->qtdEstoque);
    filme->codFilme = codigo;
}

void DestruirFilme (tFilme* filme) {
    free(filme);
}

int ObterCodigoFilme (tFilme* filme) {
    return filme->codFilme;
}

void ImprimirNomeFilme (tFilme* filme) {
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme) {
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme) {
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme) {
    return filme->qtdAlugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo) {
    return filme->codFilme == codigo;
}

void AlugarFilme (tFilme* filme) {
    (filme->qtdAlugada)++;
    (filme->qtdEstoque)--;
}

void DevolverFilme (tFilme* filme) {
    (filme->qtdAlugada)--;
    (filme->qtdEstoque)++;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2) {
    return (strcmp(filme1->nome, filme2->nome));
}