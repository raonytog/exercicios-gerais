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

/**
 * @brief Troca o valor de duas variáveis se o segundo for menor que o primeiro.
 * 
 * Esta função recebe como parâmetro um vetor, seu tamanho e um ponteiro para uma variável que será usada para armazenar o índice do menor valor encontrado. A função percorre o vetor e, se encontrar um valor menor que o valor armazenado na variável apontada por paraTrocar, atualiza essa variável e troca os valores das posições correspondentes no vetor.
 * 
 * @param vet Ponteiro para o vetor a ser percorrido.
 * @param tam Tamanho do vetor.
 * @param paraTrocar Ponteiro para a variável que armazenará o índice do menor valor encontrado.
 */
void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar) {
    int troca = 0;
    if (*vet > *paraTrocar) {
        troca = *paraTrocar;
        *paraTrocar = *vet;
        *vet = troca;
    }
}

/**
 * @brief Ordena um vetor em ordem crescente.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e ordena os valores do vetor em ordem crescente.
 * 
 * @param vet Ponteiro para o vetor a ser ordenado.
 * @param tam Tamanho do vetor.
 */
void OrdeneCrescente(int * vet, int tam) {
    for (int i = 0; i < tam-1; i++) 
        for (int j = i+1; j < tam; j++) 
            TrocaSeAcharMenor(&vet[i], i, &vet[j]);
}