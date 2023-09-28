#include <stdio.h>
#include "pessoa.h"
#include <string.h>

/**
 * @brief Cria uma nova pessoa e inicializa os ponteiros.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa() {
    tPessoa pessoa;
    strcpy(pessoa.mae, "NAO INFORMADO");
    strcpy(pessoa.pai, "NAO INFORMADO");
    strcpy(pessoa.nome, "Raony");
    // LePessoa(&pessoa);
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa) {
    scanf("%100[^\n]", pessoa->nome);
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa) {
    printf("NOME COMPLETO: %s\n", pessoa->nome);
    printf("PAI: %s\n", pessoa->pai);
    printf("MAE: %s\n", pessoa->mae);
}

/**
 * @brief Associa as famílias e grupos de pessoas.
 * Alem disso, e nessa funcao que sera lida a associacao entre as pessoas.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int mae = 0, pai = 0, filho = 0;
    scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

    if (mae > -1) {
        strcpy(pessoas[filho].mae, pessoas[mae].mae);
    }

    if (pai > -1) {
        strcpy(pessoas[filho].pai, pessoas[pai].pai);
    }
}