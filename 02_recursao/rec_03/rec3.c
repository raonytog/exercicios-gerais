/*
Programa para contar a ocorrência de X número em Y números de matrizes;
Raony Togneri
27/08/2023
*/

#include <stdio.h>

void LeArray(int tam, int vet[tam]);
int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main () {
    int numMat, numeroProcurado, numElementos;
    scanf("%d\n", &numMat);

    for (int i = 0; i < numMat; i++) {
        scanf("%d %d\n", &numeroProcurado, &numElementos);
        int vet[numElementos];
        LeArray(numElementos, vet);
        printf("%d\n", ContaOcorrencias(vet, numElementos, numeroProcurado));
    }
    return 0;
}

void LeArray(int tam, int vet[tam]) {
    for (int i = 0; i < tam; i++) {
        scanf("%d ", &vet[i]);
    }
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    numElementos--;
    if (numElementos == -1) return 0;
    if (vet[numElementos] == numeroProcurado) return 1 + ContaOcorrencias(vet, numElementos, numeroProcurado);
    return ContaOcorrencias(vet, numElementos, numeroProcurado);
}

