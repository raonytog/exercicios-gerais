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
    scanf(" %[^\n]", pessoa->nome);
}

void ImprimePessoa(tPessoa *pessoa) {
    if (pessoa->mae != NULL || pessoa->pai != NULL) { 
        
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
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int mae = 0, pai = 0, filho = 0, qtdAssociacoes = 0;
    scanf("%d", &qtdAssociacoes);

    for (int i = 0; i < qtdAssociacoes; i++) {
        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

        if (mae >= 0) {
            pessoas[filho].mae = &(pessoas[mae]);
        }

        if (pai >= 0) {
            pessoas[filho].pai = &(pessoas[pai]);
        }
    }
}