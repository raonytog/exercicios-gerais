#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int qtdAlunos = 0;
    scanf("%d", &qtdAlunos);
    tAluno ** alunos = (tAluno **) malloc (qtdAlunos * sizeof(tAluno *));

    // le alunos
    for (int i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    // ordena alunos por matricula
    tAluno * aux;
    for (int i = 0; i < qtdAlunos; i++) {
        for (int j = i+1; j < qtdAlunos; j++) {
            if (ComparaMatricula(alunos[i], alunos[j]) == 1) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }

    // imprime alunos aprovados
    for (int i = 0; i < qtdAlunos; i++) {
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }

    for (int i = 0; i < qtdAlunos; i++) {
        ApagaAluno(alunos[i]);
    }
    free(alunos);
    
    return 0;
}