#include "usuario.h"
#include <string.h>
#include <stdio.h>

tUsuario criar_usuario(char nome[20], char cpf[15]) {
    tUsuario usuario;
    strcpy(usuario.nome, nome);
    strcpy(usuario.cpf, cpf);
    return usuario;
}

void imprime_usuario(tUsuario user) {
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}