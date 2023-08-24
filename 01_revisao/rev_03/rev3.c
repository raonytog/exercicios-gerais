#include <stdio.h>

void AnalisaSeTemCopia(int numLivros, int vet[numLivros]);

int main () {
    int numLivros;
    scanf("%d\n", &numLivros);

    int vet[numLivros];
    for (int i = 0; i < numLivros; i++) {
        scanf("%d%*c", &vet[i]);
    }

    AnalisaSeTemCopia(numLivros, vet);
    return 0;
}

void AnalisaSeTemCopia(int numLivros, int vet[numLivros]) {
    int i, j, imprimiu = 0;
    for (i = 0; i < numLivros; i++) {
        int cont = 0;
        for (j = 0; j < numLivros; j++) {
            if (vet[i] == vet[j]) { 
                cont++;
            }
        }

        if (cont == 1) {
            printf("%d ", vet[i]);
            imprimiu++;
        }
    }
    if (imprimiu == 0) printf("NENHUM\n");
}