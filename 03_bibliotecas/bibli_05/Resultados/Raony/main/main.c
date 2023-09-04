/*
Programa para manipular strings com a biblioteca criada
Raony Togneri
02/09/2023
*/

#include <stdio.h>
#include "string_utils.h"
#define MAX 1001
#define TRUE 1
#define FALSE 0

int main () {
    char string[MAX];
    char copiedString[MAX];
    scanf("%[^\n]", string);

    int choosenOption = 0, flagExit = 0;
    while (TRUE) {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");
        scanf("%d", &choosenOption);
        printf("\n");

        switch (choosenOption)
        {
        case 1:
            printf("Tamanho da string: %d\n", string_length(string));
            break;
        
        case 2:
            string_copy(string, copiedString);
            printf("String copiada: %s\n", copiedString);
            break;

        case 3:
            string_upper(string);
            printf("String convertida para maiusculas: %s\n", string);
            break;

        case 4:
            string_lower(string);
            printf("String convertida para minusculas: %s\n", string);
            break;

        case 5:
            string_reverse(string);
            printf("String invertida: \n%s\n", string);
            break;

        case 6:
            flagExit = 1;
            break;
        }

        if (flagExit) break;
        printf("\n");
    }

    return 0;
}