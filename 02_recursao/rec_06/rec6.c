/*
Programa para calcular o numero de fibonacci a partir do N-ésimo termo adquirido na entrada padrão
Raony Togneri
28/08/2023
*/

#include <stdio.h>

int fibonacci(int n);

int main () {
    int num;
    scanf("%d", &num);
    printf("%d", fibonacci(num));
    return 0;
}

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
} 