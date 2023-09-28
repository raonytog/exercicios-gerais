#include <stdio.h>
#include "pessoa.h"

int main () {
    int numPessoas = 0;
    scanf("%d", &numPessoas);
    tPessoa pessoas[numPessoas];

    for (int i = 0; i < numPessoas; i++) {
       pessoas[i] = CriaPessoa();
    }

    int numAlteracoes = 0;
    scanf("%d", &numAlteracoes);
    for (int i = 0; i < numAlteracoes; i++) {
        AssociaFamiliasGruposPessoas(&pessoas[i]);
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}