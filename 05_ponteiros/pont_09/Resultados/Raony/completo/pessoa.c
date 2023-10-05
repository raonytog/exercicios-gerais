#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.nome[0] = '\0';
    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf("\n%[^\n]", pessoa->nome);
}


int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    if (pessoa->mae != NULL || pessoa->pai != NULL) return 1;
    return 0;
}

void ImprimePessoa(tPessoa *pessoa) {
    if (VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        printf("PAI: ");
        if (pessoa->pai != NULL) {
            printf("%s\n", pessoa->pai->nome);
        } else printf("NAO INFORMADO\n");

        printf("MAE: ");
        if (pessoa->mae != NULL) {
            printf("%s\n", pessoa->mae->nome);
        } else printf("NAO INFORMADO\n");

        printf("\n");
    }

    return;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int mae = 0, pai = 0, filho = 0, qtdAssociacoes = 0;
    scanf("%d\n", &qtdAssociacoes);

    for (int i = 0; i < qtdAssociacoes; i++) {
        scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho);

        if (mae != -1) {
            pessoas[filho].mae = &pessoas[mae];
        }

        if (pai != -1) {
            pessoas[filho].pai = &pessoas[pai];
        }
    }
}