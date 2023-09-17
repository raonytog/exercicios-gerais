#include "vendedor.h"
#include "loja.h"
#include <stdio.h>

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;
    loja.id = id;
    loja.aluguel = aluguel;
    loja.lucro = 0;
    loja.totalVendedores = 0;
    return loja;
}

int VerificaIdLoja(tLoja loja, int id) {
    return loja.id == id;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    int tVend = loja.totalVendedores;
    loja.vendedores[tVend] = vendedor;
    loja.totalVendedores++;
    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {

    int i = 0;
    for (i = 0; i < loja.totalVendedores; i++) {
        if (VerificaNomeVendedor(loja.vendedores[i], nome)) {
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            break;
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja) {
    tVendedor vendedor;
    int i = 0;
    loja.lucro -= loja.aluguel;

    for (i = 0; i < loja.totalVendedores; i++) {
        vendedor = loja.vendedores[i];
        loja.lucro += (GetTotalVendido(vendedor) - GetTotalRecebido(vendedor));  
    }
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    loja = CalculaLucro(loja);
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    for (int i = 0; i < loja.totalVendedores; i++) {
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}