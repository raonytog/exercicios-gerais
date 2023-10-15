#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tUsuario *CriaUsuario() {
    tUsuario * usuario = (tUsuario*) malloc (sizeof(tUsuario));
    if (usuario == NULL) {
        printf("Alocacao impropria em usuario.c\n");
        exit(1);
    }

    return usuario;
}

void DestroiUsuario(tUsuario *user) {
    free(user);
}

void LeUsuario(tUsuario *user) {
    scanf("%s %s", user->nome, user->cpf);
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n\n", user->cpf);
}