#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos) {
    int tamVet = VectorSize(alunos);
    float media = 0;

    for (int i = 0; i < tamVet; i++) {
        media += GetNotaAluno(alunos[i]);
    }


    // Media das notas: 7.05
    // Porcentagem de alunos aprovados: 75.00%
    // Porcentagem de cada genero:
    // Masculino: 25.00%
    // Feminino: 25.00%
    // Outro: 50.00%
}