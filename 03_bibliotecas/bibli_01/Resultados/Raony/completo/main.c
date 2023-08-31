#include <stdio.h>
#include "esfera_utils.h"

int main () {
    float num;
    scanf("%f", &num);
    printf("Area: %.2f\nVolume: %.2f\n", 
            calcula_area(num), calcula_volume(num));
    return 0;
}