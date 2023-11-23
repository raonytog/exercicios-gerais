#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>

struct empresa {
    int idEmpresa;
    int qtdCandidatos;
    int qtdFuncionarios;
    tFuncionario ** funcionarios;
};

tEmpresa* CriaEmpresa() {
    tEmpresa * empresa = malloc(sizeof(tEmpresa));
    empresa->idEmpresa = -1;
    empresa->qtdFuncionarios = 0;
    empresa->qtdCandidatos = -1;
    empresa->funcionarios = NULL;
    return empresa;
}

void LeEmpresa(tEmpresa* empresa) {
    scanf("%d %d", &empresa->idEmpresa, &empresa->qtdCandidatos);
    for (int i = 0; i < empresa->qtdCandidatos; i++) {
        tFuncionario * f = CriaFuncionario();
        LeFuncionario(f);
        ContrataFuncionarioEmpresa(empresa, f);
    }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa) {
    if (!empresa) return;
    
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
        ApagaFuncionario(empresa->funcionarios[i]);

    free(empresa->funcionarios);
    free(empresa);
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario) {
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
        if (GetIdFuncionario(funcionario) == GetIdFuncionario(empresa->funcionarios[i])) {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->idEmpresa, GetIdFuncionario(funcionario));
            ApagaFuncionario(funcionario);
            return;
        }

    empresa->funcionarios = realloc(empresa->funcionarios, (empresa->qtdFuncionarios+1) * sizeof(tFuncionario *));
    empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
    (empresa->qtdFuncionarios)++;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa) {
    printf("Empresa %d:\n", empresa->idEmpresa);
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
        ImprimeFuncionario(empresa->funcionarios[i]);
}