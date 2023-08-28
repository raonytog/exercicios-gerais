/*
Programa que imprime um texto ao contrario utilizando os conhecimentos de funões recursivas;
Raony Togneri;
24/08/2023
*/

#include <stdio.h>

void ImprimeInvertido(char* string); 

int main () {
    char textoOriginal[1001];
    while (scanf("%s", textoOriginal) == 1) {
        ImprimeInvertido(textoOriginal); 
        printf(" ");
    }
    return 0;
}

void ImprimeInvertido(char* string) {
    if (string[0] == '\0') return;

    int i = 0;
    while(string[i] != '\0') {
        i++;
    }
    
    printf("%c", string[i-1]);
    string[i-1] = '\0';
    ImprimeInvertido(string);
}
