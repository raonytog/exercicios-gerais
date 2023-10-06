#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    pessoa.nome[0] = '\0';
    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf("\n%[^\n]", pessoa->nome);
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    return ( (pessoa1->mae == pessoa2->mae) && (pessoa1->pai == pessoa2->pai) );
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

        printf("IRMAO: ");
        if (pessoa->irmao != NULL) {
            printf("%s\n", pessoa->irmao->nome);
        } else printf("NAO INFORMADO\n");

        printf("\n");
    }

    return;
}
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    int i = 0, j = 0, mae = 0, pai = 0, filho = 0, qtdAssociacoes = 0;

    // associa pais
    scanf("%d\n", &qtdAssociacoes);
    for (i = 0; i < qtdAssociacoes; i++) {
        scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho);

        if (mae != -1) {
            pessoas[filho].mae = &pessoas[mae];
        }

        if (pai != -1) {
            pessoas[filho].pai = &pessoas[pai];
        }
    }

    // associa irmaos
    for (i = 0; i < numPessoas - 1; i++) {
        for (j = i + 1; j < numPessoas; j++) {
            if (VerificaIrmaoPessoa(pessoas+i, pessoas+j)) {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}