#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        scanf("%d", &array[i]);
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media) {
    int i = 0;
    *maior = -999999; *menor = 999999; *media = 0;
    for (i = 0; i < tamanho; i++) {

        if (array[i] > *maior)  //se for maior
            *maior = array[i];

        if (array[i] < *menor)  // se for menor
            *menor = array[i];

        *media += (float)array[i];
    }

    *media /= tamanho;
}