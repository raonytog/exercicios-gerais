#include "funcionario.h"
#include <stdio.h>

tFuncionario criaFuncionario(int id, float salario) {
    tFuncionario funcionario;
    funcionario.id = id;
    funcionario.salario = salario;
    return funcionario;
}

tFuncionario leFuncionario() {
    tFuncionario funcionario;
    scanf("%d %f", &funcionario.id, &funcionario.salario);
    return funcionario;
}

int getIdFuncionario(tFuncionario funcionario) {
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario) {
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}