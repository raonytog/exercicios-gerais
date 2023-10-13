#include <stdio.h>
#include "aluno.h"

int main () {
    int numAlunos = 0, i = 0, j = 0, total_aprovado = 0;
    scanf("%d", &numAlunos);
    tAluno *aluno[numAlunos], *aprovados[numAlunos], *temp;

    for (i = 0; i < numAlunos; i++) {
        aluno[i] = CriaAluno();
        LeAluno(aluno[i]);

        // salva na estrutura de alunos aprovados os que forem
        if (VerificaAprovacao(aluno[i])) {
            aprovados[j] = aluno[i];
            j++;
            total_aprovado++;
        }
    }
    
    for (i = 0; i < total_aprovado-1; i++) {
        for (j = i + 1; j < total_aprovado; j++) {
            if (ComparaMatricula(aprovados[i], aprovados[j]) == 1) {
                temp = aprovados[i];
                aprovados[i] = aprovados[j];
                aprovados[j] = temp;
            }
        }
    }

    for (i = 0; i < total_aprovado; i++) {
        ImprimeAluno(aprovados[i]);
        ApagaAluno(aprovados[i]);
    }

    return 0;
}