#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;
    return empresa;
}

tEmpresa leEmpresa() {
    int id = 0, qtdFunc = 0;
    tEmpresa empresa;       tFuncionario funcionario;

    scanf("%d %d", &id, &qtdFunc);
    empresa = criaEmpresa(id);

    for (int i = 0; i < qtdFunc; i++) {
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
    tFuncionario aux;
    int i = 0, tam = 0;
    for (i = 0; i < empresa.qtdFuncionarios; i++) {
        aux = empresa.funcionarios[i];
        if (aux.id == funcionario.id) { // verifica se ja ta na empresa
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);
            return empresa;
        }
    }

    empresa.qtdFuncionarios++;
    tam = empresa.qtdFuncionarios;
    empresa.funcionarios[tam-1] = funcionario;
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
    tFuncionario funcionario;
    printf("Empresa %d:\n", empresa.id);
    for (int i = 0; i < empresa.qtdFuncionarios; i++) {
        funcionario = empresa.funcionarios[i];
        imprimeFuncionario(funcionario);
    }
    printf("\n");
}