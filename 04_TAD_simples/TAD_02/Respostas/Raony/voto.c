#include "voto.h"
#include <stdio.h>

//Constantes que representam os identificadores dos candidatos à presidência.
#define DIJKSTRA 10
#define TURING 42
#define SHAW 26

//Constantes que representam os identificadores dos candidatos a Primeiro Ministro.
#define BERNERS 36
#define LINUS 64
#define LOVELACE 18

//Constante que representa o identificador do voto em branco.
#define BRANCO 0

//Constantes que representam votacao com empate ou sem decisão.
#define EMPATE 0
#define SEM_DECISAO -1

/**
 * @brief Inicializa a estrutura de votos com valores zerados.
 * @return Retorna uma estrutura tVoto com todos os campos zerados.
 */
tVoto inicializaVotos() {
    tVoto votos;
    // presidentes
    votos.ber = 0;
    votos.lin = 0;
    votos.lov = 0;

    // ministros
    votos.dij = 0;
    votos.tur = 0;
    votos.sha = 0;
    
    votos.brancosM = 0;
    votos.brancosP = 0;
    votos.nulosM = 0;
    votos.nulosP = 0;
    return votos;
}

float porcentagem(int valor, int total) {
    return (100 * valor)/total;
}

/**
 * @brief Contabiliza um voto para Presidente.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param votoP Identificador do candidato a Presidente.
 * @return Retorna a estrutura tVoto com o voto contabilizado.
 */
tVoto contabilizaVotoPrisidente(tVoto votos, int votoP) {
    switch (votoP) {
    case DIJKSTRA:
        votos.dij++;
        break;

    case TURING:
        votos.tur++;
        break;

    case SHAW:
        votos.sha++;
        break;
    }
    return votos;
}

/**
 * @brief Contabiliza um voto para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param votoM Identificador do candidato a Primeiro Ministro.
 * @return Retorna a estrutura tVoto com o voto contabilizado.
 */
tVoto contabilizaVotoPMinistro(tVoto votos, int votoM) {
    switch (votoM) {
    case BERNERS:
        votos.ber++;
        break;

    case LINUS:
        votos.lin++;
        break;

    case LOVELACE:
        votos.lov++;
        break;
    }
    return votos;
}

/**
 * @brief Verifica o vencedor da eleição para presidente.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o identificador do candidato vencedor, ou SEM DECISAO ou EMPATE em caso de empate.
 */
int vencedorPresidente(tVoto votos) {
    if (votos.brancosM + votos.nulosP > votos.dij + votos.tur + votos.sha) return SEM_DECISAO;
}

/**
 * @brief Verifica o vencedor da eleição para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o identificador do candidato vencedor, ou SEM DECISAO ou EMPATE em caso de empate.
 */
int vencedorPMinistro(tVoto votos);


int obtemTotalVotosPresidente(tVoto votos) {
    return votos.ber + votos.lin + votos.lov;
}

/**
 * @brief Obtém o total de votos para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o total de votos para Primeiro Ministro.
 */
int obtemTotalVotosPMinistro(tVoto votos) {
    return votos.dij + votos.tur + votos.sha;
}

/**
 * @brief Imprime o resultado da eleição.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param totalP Total de votos para a presidência.
 * @param totalM Total de votos para Primeiro Ministro.
 * @param vencedorP Identificador do candidato vencedor para a presidência.
 * @param vencedorM Identificador do candidato vencedor para Primeiro Ministro.
 * @param counterQtd Contador de votos válidos.
 * @param qtd Quantidade de eleitores.
 */
void printaResultado(tVoto votos, int totalP, int totalM, int vencedorP, int vencedorM, int counterQtd, int qtd);