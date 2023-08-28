/*
Programa que calcula o fatorial de um numero
Raony Togneri
27/08/2023
*/
#include <stdio.h>

int fatorial(int n);

int main () {
    int num;
    scanf("%d", &num);
    printf("%d", fatorial(num));
    return 0;
}

int fatorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorial(n-1);
}