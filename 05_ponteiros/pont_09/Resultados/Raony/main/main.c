#include <stdio.h>
#include "pessoa.h"

int main () {
    int numPessoas = 0, i = 0, numAlteracoes = 0;
    scanf("%d%*c", &numPessoas);
    tPessoa pessoas[numPessoas], pessoaTemp;

    // le pessoas
    for (i = 0; i < numPessoas; i++) {
        pessoaTemp = CriaPessoa();
        pessoas[i] = pessoaTemp;
        LePessoa(&pessoas[i]);
    }

    // junta familias (que amor)
    scanf("%d%*c", &numAlteracoes);
    for (i = 0; i < numAlteracoes; i++) {
        AssociaFamiliasGruposPessoas(&(pessoas[i]));
    }

    // imprime quem n é orfao
    for (i = 0; i < numPessoas; i++) {
        ImprimePessoa(&pessoas[i]);
    }
    
    return 0;
}