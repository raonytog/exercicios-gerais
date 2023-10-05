#include <stdio.h>
#include "vetor.h"

int soma (int a, int b) {
    return a + b;
}

int produto (int a, int b) {
    return a * b;
}

int main () {
    Vetor * vetor = NULL;
    LeVetor(&vetor);

    int sum = AplicarOperacaoVetor(&vetor, soma);
    int product = AplicarOperacaoVetor(&vetor, produto);

    printf("Soma: %d\n", sum);
    printf("Produto: %d\n", product);

    return 0;
}