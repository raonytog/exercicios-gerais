#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n) {
    int m1, n1;
    scanf("%d %d", &m1, &n1);
    *m = m1;
    *n = n1;
}

int EhPrimo(int n) {
    if (n <= 1) return 0;

    int count = 0, i = 0;
    for (i = 1; i <= n; i++) {
        if (n%i == 0) count++;
    }

    if (count == 2) return 1;
    return 0;
}

/**
 * @brief Obtém o maior e o menor número primo em um intervalo.
 * 
 * Esta função recebe como parâmetro dois números inteiros que representam o início e o fim de um intervalo, e dois ponteiros para inteiros que receberão os valores do maior e do menor número primo encontrado no intervalo.
 * 
 * @param m Início do intervalo.
 * @param n Fim do intervalo.
 * @param menor Ponteiro para a variável que receberá o menor número primo encontrado.
 * @param maior Ponteiro para a variável que receberá o maior número primo encontrado.
 */
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior) {
    *maior = 0, *menor = 99999;
    for (int i = m; i <= n; i++) {
        if (EhPrimo(i)) {
            if (i > *maior) *maior = i;
            if (i < *menor) *menor = i;
        }
    }
}

