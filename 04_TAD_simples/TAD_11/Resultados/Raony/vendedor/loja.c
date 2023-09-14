#include "vendedor.h"
#include "loja.h"

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
    tVendedor vendedor;
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (VerificaNomeVendedor(loja.vendedores[i], nome)) {
            vendedor = loja.vendedores[i];
            vendedor.valor_vendido += valor;
            break;
        }
    }
    loja.vendedores[i] = vendedor;
    return loja;
}

tLoja CalculaLucro(tLoja loja) {
    int i = 0;
    tVendedor vendedor;
    loja.lucro += loja.aluguel;

    for (i = 0; i < 10; i++) {
        vendedor = loja.vendedores[i];
        loja.lucro += GetTotalVendido(vendedor) - GetSalario(vendedor);  
    }

    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    printf("Loja %d: ");
    for (int i = 0; i < loja.totalVendedores; i++) {
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}