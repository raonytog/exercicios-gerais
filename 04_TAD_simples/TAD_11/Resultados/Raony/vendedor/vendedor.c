#include "vendedor.h"
#include <string.h>

tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao) {
    tVendedor vendedor;
    strcpy(vendedor.nome, nome);
    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;
    return vendedor; 
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]) {
    return strcmp(vendedor.nome, nome);
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor) {
    vendedor.valor_vendido = valor;
}

float GetSalario(tVendedor vendedor) {
    return vendedor.salario;
}


float GetComissao(tVendedor vendedor) {
    return vendedor.valor_vendido * vendedor.prct_comissao;
}

float GetTotalVendido(tVendedor vendedor) {
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor) {
    return vendedor.valor_vendido;
}

void ImprimeRelatorioVendedor(tVendedor vendedor) {
    printf("\t%s > Total vendido: R$%.2f\n", vendedor.nome, vendedor.valor_vendido);
    printf("\t\tTotal recebido: R$%.2f\n", vendedor.salario + (vendedor.valor_vendido * vendedor.prct_comissao));
}