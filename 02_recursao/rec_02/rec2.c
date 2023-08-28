/*
Programa que soma todos os números pares (n%2==0) de uma lista de arrays a partir da qtd de vetores,
o tamanho de cada um, seguido do conteudo dos vetores.
Raony Togneri
24/08/2023
*/

#include <stdio.h>

void PreencheVetor(int tam, int vet[tam]);
int SomaElementosPares(int* vet, int numElementos);

int main () {
    int numVetores = 0, tam = 0;
    scanf("%d", &numVetores);
    for(int i = 0; i < numVetores; i++) {
        scanf("%d", &tam);
        int vet[tam];
        PreencheVetor(tam, vet);
        printf("%d\n", SomaElementosPares(vet, tam));
    }
    return 0;
}

void PreencheVetor(int tam, int vet[tam]) {
    for(int i = 0; i < tam; i++) {
        scanf("%d%*c", &vet[i]);
    }
}

int SomaElementosPares(int* vet, int numElementos) {
    numElementos--;
    if (numElementos == -1) return 0;
    if (vet[numElementos]%2 == 0) return vet[numElementos] + SomaElementosPares(vet, numElementos);
    return SomaElementosPares(vet, numElementos);
}