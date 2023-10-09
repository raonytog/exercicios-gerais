#include <stdio.h>
#include "vetor.h"

void LeVetor(Vetor *vetor) {
    int tam = 0;
    scanf("%d", &tam);
    vetor->tamanhoUtilizado = tam;
    
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    int resultado = vetor->elementos[0];

    for (int i = 0; i < vetor->tamanhoUtilizado-1; i++) {
        resultado += op(vetor->elementos[i+1], resultado);
    }

    return resultado;
}