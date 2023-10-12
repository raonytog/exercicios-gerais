#include <stdio.h>
#include "vetor.h"

int soma (int a, int b);

int produto (int a, int b);

int main () {
    Vetor vetor;
    int sum = 0, prod = 0;
    LeVetor(&vetor);

    sum = AplicarOperacaoVetor(&vetor, soma);
    prod = AplicarOperacaoVetor(&vetor, produto);

    printf("Soma: %d\n", sum);
    printf("Produto: %d\n", prod);

    return 0;
}

int soma (int a, int b) {
    return a + b;
}

int produto (int a, int b) {
    return a * b;
}