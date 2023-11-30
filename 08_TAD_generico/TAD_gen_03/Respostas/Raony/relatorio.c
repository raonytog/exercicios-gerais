#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void ImprimeRelatorio(Vector *alunos) {
    int tamVet = VectorSize(alunos), genM = 0, genF = 0, genO = 0;
    float nota = 0, media = 0, qtdAlunoApv = 0, pctApvd = 0, pctM = 0, pctF = 0, pctO =0;

    for (int i = 0; i < tamVet; i++) {
        nota += GetNotaAluno(VectorGet(alunos, i));
        if (GetNotaAluno(VectorGet(alunos, i)) >= 6) qtdAlunoApv++;
        
        switch (GetGeneroAluno(VectorGet(alunos, i))) {
            case 'F':
                genF++;
                break;

            case 'M':
                genM++;
                break;

            case 'O':
                genO++;
                break;
        }
    }

    media = nota/tamVet;
    pctApvd = (qtdAlunoApv*100)/tamVet;
    pctM = (genM*100)/tamVet;
    pctF = (genF*100)/tamVet;
    pctO = (genO*100)/tamVet;

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%\n", pctApvd);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%\n", pctM);
    printf("Feminino: %.2f%\n", pctF);
    printf("Outro: %.2f%\n", pctO);

    // Media das notas: 7.05
    // Porcentagem de alunos aprovados: 75.00%
    // Porcentagem de cada genero:
    // Masculino: 25.00%
    // Feminino: 25.00%
    // Outro: 50.00%
}