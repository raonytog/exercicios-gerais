#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int qtdAlnuos = 0, j = 0;
    scanf("%d", &qtdAlnuos);
    tAluno ** alunos = (tAluno **) malloc (qtdAlnuos * sizeof(tAluno *));
    tAluno ** alunosAprovados;

    // le alunos
    for (int i = 0; i < qtdAlnuos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    for (int i = 0; i < qtdAlnuos; i++) {
        if (VerificaAprovacao(alunos[i])) {
            j++;
            alunosAprovados = realloc(alunosAprovados, j * sizeof(tAluno *));
            alunosAprovados[i] = alunos[i];
        }
    }

    // ordena por matricula (menor a maior)
    int tam = j;
    tAluno * aux;
    for (int i = 0; i < tam-1; i++) {
        for (j = i+1; j < tam; j++) {
            if (ComparaMatricula(alunosAprovados[i], alunosAprovados[j]) == 1) {
                aux = alunosAprovados[i];
                alunosAprovados[i] = alunosAprovados[j];
                alunosAprovados[j] = aux;
            }
        }
    }

    for (int i = 0; i < tam; i++) {
        ImprimeAluno(alunosAprovados[i]);
    }


    return 0;
}