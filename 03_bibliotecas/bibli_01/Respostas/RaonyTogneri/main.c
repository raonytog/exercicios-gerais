#include <stdio.h>
#include "esfera_utils.h"

int main () {
    int num;
    scanf("%d", &num);
    printf("Area: %.2f\nVolume: %.2f", 
            calcula_area(num), calcula_volume(num));
    return 0;
}