/*



*/

#include <stdio.h>
#include <string.h>
#define MAX 1001

int palindromo(char *string, int tamanho); 

int main () {
    char palavra[MAX];
    scanf("%s", palavra);
    int tam = strlen(palavra);
    printf("%d", tam);

    return 0;
}

int palindromo(char *string, int tamanho) {
    return 1;
}