/*
Programa que recebe palavras enquanto o usuário digitar e retorna se elas são ou não palindromas 
(i.e. se lidas da direita a esquerda, continuam a mesma palavra lida da esquerda a direita).
Raony Togneri
27/08/2023
*/

#include <stdio.h>
#include <string.h>
#define MAX 1001

int EhPalindromo(char *string, int tamanho); 

int main () {
    char palavra[MAX];
    while (scanf("%s", palavra) == 1) {
        int tam = strlen(palavra);
        if (EhPalindromo(palavra, tam)) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}

int EhPalindromo(char *string, int tamanho) {
    if (tamanho <= 1) return 1;
    if (string[0] != string[tamanho--]) return 0;
    return EhPalindromo(string++, tamanho-2);
}