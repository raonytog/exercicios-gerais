#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main () {
    int qtdEmpresas = 0;
    scanf("%d%*c%*c", &qtdEmpresas);

    tEmpresa ** empresa = malloc(qtdEmpresas * sizeof(tEmpresa *));
    for (int i = 0; i < qtdEmpresas; i++)
        empresa[i] = CriaEmpresa();

    for (int i = 0; i < qtdEmpresas; i++) 
        LeEmpresa(empresa[i]);

    for (int i = 0; i < qtdEmpresas; i++) 
        ImprimeEmpresa(empresa[i]);

    for (int i = 0; i < qtdEmpresas; i++) 
        ApagaEmpresa(empresa[i]);
    free(empresa);

    return 0;
}