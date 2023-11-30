#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote {
    Type type;
    int maxSize;
    void * data;
    int numVerify;
};

tPacote* CriaPacote(Type type, int numElem) {
    tPacote * p = malloc(sizeof(tPacote));
    p->data = malloc(numElem * sizeof(type));
    p->type = type;
    p->maxSize = numElem;
    p->numVerify = 0;
    return p;
}

void DestroiPacote(tPacote* pac) {
    free(pac->data);
    free(pac);
}

void LePacote(tPacote* pac) {
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    switch (pac->type) {
        case INT:
            for (int i = 0; i < pac->maxSize; i++)
                scanf("%d ", *((int *)pac->data + i*sizeof(int)));
            break;

        case CHAR:
            scanf("%[^\n]%*c", pac->data);
            break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac) {
    printf("%d", pac->numVerify);
    for (int i = 0; i < pac->maxSize; i++) {
        switch (pac->type) {
            case INT:
                printf(" %d", (int *)pac->data + i*sizeof(int));
                break;

            case CHAR:
                printf("%s", (char *)pac->data);
                break;
        }
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac) {
    int sum = 0;
    for (int i = 0; i < pac->maxSize; i++) {
        switch (pac->type) {
            case INT:
                sum += *((int*) pac->data + i*sizeof(int));
                break;

            case CHAR:
                sum += *((char*) pac->data + i*sizeof(char));
                break;
        }
    }

    pac->numVerify = sum;
}