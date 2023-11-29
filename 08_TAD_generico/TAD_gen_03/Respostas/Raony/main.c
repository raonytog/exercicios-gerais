#include "aluno.h"
#include "vector.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int qtdAlunos = 0;
    scanf("%d%*c", &qtdAlunos);
    Vector * vetor = VectorConstruct();
    for (int i = 0; i < qtdAlunos; i++) {
        tAluno * aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetor, aluno);
    }

    ImprimeRelatorio(vetor);

    VectorDestroy(vetor, DestroiAluno);
    
    return 0;
}