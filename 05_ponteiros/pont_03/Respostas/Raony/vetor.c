#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam) {
     for (int i = 0; i < tam; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar) {
    int troca = 0;
    if (*vet > *paraTrocar) {
        troca = *paraTrocar;
        *paraTrocar = *vet;
        *vet = troca;
    }
}

void OrdeneCrescente(int * vet, int tam) {
    for (int i = 0; i < tam-1; i++) 
        for (int j = i+1; j < tam; j++) 
            TrocaSeAcharMenor(&vet[i], i, &vet[j]);
}