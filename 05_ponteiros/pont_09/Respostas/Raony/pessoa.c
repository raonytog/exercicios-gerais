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
    scanf("%[^\n]%*c", pessoa->nome);
}

void ImprimePessoa(tPessoa *pessoa) {
    if (pessoa->mae != NULL || pessoa->pai != NULL) { 
        
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if (pessoa->pai != NULL) {
            printf("PAI: %s\n", pessoa->pai->nome);
        } else printf("PAI: NAO INFORMADO\n");

        if (pessoa->mae != NULL) {
            printf("MAE: %s\n", pessoa->mae->nome);
        } else printf("MAE: NAO INFORMADO\n");

        printf("\n");
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int mae = 0, pai = 0, filho = 0;
    scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho);
 
    if (mae == 1) printf(" ");

    if (mae >= 0) {
        pessoas[filho].mae = &(pessoas[mae]);
    }

    if (pai >= 0) {
        pessoas[filho].pai = &(pessoas[pai]);
    }
}