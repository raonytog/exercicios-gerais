#include <stdio.h>
#include "pessoa.h"

int main () {
    int numPessoas = 0, i = 0;
    scanf("%d\n", &numPessoas);
    tPessoa pessoas[numPessoas];

    // le pessoas
    for (i = 0; i < numPessoas; i++) {
        pessoas[i] = CriaPessoa();
        LePessoa(&(pessoas[i]));
    }

    AssociaFamiliasGruposPessoas(pessoas);

    // imprime quem n é orfao
    for (i = 0; i < numPessoas; i++) {
        ImprimePessoa(&(pessoas[i]));
    }
    
    return 0;
}