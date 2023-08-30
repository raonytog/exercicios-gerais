#include <math.h>
#include "esfera_utils.h"

float calcula_volume (float R) {
    return (4/3) * PI * pow(R,3);
}

float calcula_area (float R) {
    return 4*PI*pow(R,2);
}