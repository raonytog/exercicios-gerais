#include "empresa.h"
#include <stdio.h>

int main () {
    int i = 0, qtdEmpresas = 0;
    scanf("%d", &qtdEmpresas);
    tEmpresa empresa[20];
    for (i = 0; i < qtdEmpresas; i++) {
        empresa[i] = leEmpresa();
    }

    for (i = 0; i < qtdEmpresas; i++) {
        imprimeEmpresa(empresa[i]);
    }

    return 0;
}