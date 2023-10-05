#include <stdio.h>
#include "calculadora.h"

// a - adicao
// s - subtracao
// m - multiplicacao
// d - divisao
// f - fim

float adicao(float x, float y) {
    return x+y;
}

float subtracao(float x, float y) {
    return x-y;
}

float multiplicacao(float x, float y) {
    return x*y;
}

float divisao(float x, float y) {
    if (y == 0) return -999999;
    return x/y;
}

int main () {
    char operacao = '0';
    float num1 = 0, num2 = 0, resultado = 0;

    while (1) {
        scanf("%c", &operacao);
        if (operacao == 'f') return 0;

        scanf("%f %f", &num1, &num2);

        switch (operacao) {
        case 'a':
            printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, adicao));
            break;

        case 's':
            printf("%.2f - %.2f = %.2f\n", num1, num2, Calcular(num1, num2, subtracao));
            break;

        case 'm':
            printf("%.2f x %.2f = %.2f\n", num1, num2, Calcular(num1, num2, multiplicacao));
            break;

        case 'd':
            printf("%.2f / %.2f = %.2f\n", num1, num2, Calcular(num1, num2, divisao));
            break;
        }
    }

    return 0;
}