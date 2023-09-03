/*
Programa para calcular area e volume de uma esfera atravez das funcoes da biblioteca criada
Raony Togneri
30/08/2023
*/

#include <stdio.h>
#include "esfera_utils.h"

int main () {
    float num;
    scanf("%f", &num);
    printf("Area: %.2f\nVolume: %.2f\n", 
            calcula_area(num), calcula_volume(num));
    return 0;
}