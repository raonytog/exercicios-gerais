/*
Programa que imprime o fatorial de um numero utiliaando os conhecimentos de funões recursivas;
Raony Togneri;
24/08/2023
*/

#include <stdio.h>

int Fatorial(int num);

int main () {
    int num;
    printf("Digite um numero: ");   scanf("%d", &num);
    printf("\nO fatorial de %d é: %d\n", num, Fatorial(num));
    return 0;
}

int Fatorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    } else return num * Fatorial(num-1);
}