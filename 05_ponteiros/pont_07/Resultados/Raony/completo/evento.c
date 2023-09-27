#include "evento.h"
#include <stdio.h>

#define MAX_NAME 50

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos) {
    int i = *numEventos;
    scanf("%s\n%d %d %d", eventos[i].nome, &eventos[i].dia, &eventos[i].mes, &eventos[i].ano);
    *numEventos++;
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos) {
    printf("Eventos cadastrados:\n");
    for (int i = 0; i < *numEventos; i++) {
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos) {
    int i = *numEventos;
    int dia = 0, mes = 0, ano = 0;
    scanf("%d %d %d", &dia, &mes, &ano);
    eventos[i].dia = dia;
    eventos[i].mes = mes;
    eventos[i].ano = ano;
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    Evento e1 = eventos[*indiceA], e2 = eventos[*indiceB];
    eventos[*indiceA] = e2;
    eventos[*indiceB] = e1;
}