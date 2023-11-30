#include "tadgen.h"
#include <stdio.h>

int main () {
    printf("tad_gen_01\n");
    int tipo = 0, sizeVet = 0;

    printf("Digite o tipo e numero de elementos: \n");
    scanf("%d %d%*c", &tipo, &sizeVet);
    tGeneric * gen = CriaGenerico(tipo, sizeVet);

    
    LeGenerico(gen);

    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}