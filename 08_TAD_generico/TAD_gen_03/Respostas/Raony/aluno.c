#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[50];
    float nota;
    char genero;
};

tAluno *CriaAluno() {
    tAluno * a = malloc(sizeof(tAluno));
    if (!a) exit(1);

    a->nome[0] = '\0';
    a->genero = '\0';
    a->nota = -1;
    return a;
}

void DestroiAluno(data_type aluno) {
    tAluno * a = (tAluno *) aluno;
    free(a);
}

void LeAluno(tAluno *aluno) {
    scanf("%[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno) {
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno) {
    return aluno->nota;
}