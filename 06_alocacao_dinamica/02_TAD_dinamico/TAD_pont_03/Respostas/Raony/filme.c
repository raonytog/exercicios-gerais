#include "filme.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tFilme* CriarFilme() {
    tFilme * filme = (tFilme*) malloc(sizeof(tFilme));
    if (filme == NULL) {
        printf("Alocacao impropria no filme.c\n");
        exit(1);
    }

    filme->qtdAlugada = 0;
    return filme;
}

void LeFilme(tFilme *filme, int codigo) {
    filme->codigo = codigo;
    scanf("%[^,],%d,%d", filme->nome, &filme->valor, &filme->qtdEstoque);
}

void DestruirFilme (tFilme* filme) {
    free (filme);
}

int ObterCodigoFilme (tFilme* filme) {
    return filme->codigo;
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
    return filme->codigo == codigo;
}

void AlugarFilme (tFilme* filme) {
    filme->qtdAlugada++;
    filme->qtdEstoque--;
}

void DevolverFilme (tFilme* filme) {
    filme->qtdEstoque++;
    filme->qtdAlugada--;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2) {
    return strcmp(filme1->nome, filme2->nome);
}