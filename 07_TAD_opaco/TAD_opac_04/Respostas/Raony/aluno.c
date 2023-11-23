#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    int matricula;
    char * nome;
    int n1, n2, n3; 
};

tAluno* CriaAluno() {
    tAluno * aluno = malloc(sizeof(tAluno));
    aluno->matricula = 01;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    aluno->nome = NULL;
}

void ApagaAluno(tAluno *aluno) {
    if (aluno == NULL) return;
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno) {
    char aux[50];
    scanf("%s%*c", aux);
    aluno->nome = realloc(aluno->nome, (strlen(aux)+1) * sizeof(char));
    strcpy(aluno->nome, aux);

    scanf("%d%*c", &aluno->matricula);
    scanf("%d %d %d%*c", &aluno->n1, &aluno->n2, &aluno->n3);
    return;
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    if (aluno1->matricula > aluno2->matricula) return 1;
    if (aluno1->matricula < aluno2->matricula) return -1;
    else return 0;
}

int CalculaMediaAluno(tAluno* aluno) {
    return ( aluno->n1 + aluno->n2 + aluno->n3 )/3;
}


int VerificaAprovacao(tAluno* aluno) {
    if (CalculaMediaAluno(aluno) >= 7) return 1;
    else return 0;
}

void ImprimeAluno(tAluno* aluno) {
    printf("%s\n", aluno->nome);
}
