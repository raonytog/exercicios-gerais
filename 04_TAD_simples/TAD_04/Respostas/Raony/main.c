#include <stdio.h>
#include "aluno.h"

int main () {
    int nAlunos = 0, tempMatricula = 0, tempNota1 = 0, tempNota2 = 0, tempNota3 = 0, i = 0, j = 0;
    char tempNome[50];
    scanf("%d", &nAlunos);
    tAluno aluno[nAlunos], alunoAprovado[nAlunos], alunoTemp;

    // preenche tipo alunos
    for (i = 0; i < nAlunos; i++) {
        scanf("%s%*c", &tempNome);
        scanf("%d%*c", &tempMatricula);
        scanf("%d %d %d%*c", &tempNota1, &tempNota2, &tempNota3);
        aluno[i] = criar_aluno(tempNome, tempMatricula, tempNota1, tempNota2, tempNota3);

        // preenche alunos aprovados
        if (aluno_aprovado(aluno[i])) {
            alunoAprovado[j] = aluno[i];
            j++;
        }
    }

    // ordena por matricula (menor a maior)
    int tam = j;
    for (i = 0; i < tam-1; i++) {
        for (j = i+1; j < tam; j++) {
            if (comparar_matricula_aluno(alunoAprovado[i], alunoAprovado[j]) == 1) {
                alunoTemp = alunoAprovado[i];
                alunoAprovado[i] = alunoAprovado[j];
                alunoAprovado[j] = alunoTemp;
            }
        }
    }

    for (i = 0; i < tam; i++) {
        imprimir_aluno(alunoAprovado[i]);
    }

    return 0;
}
