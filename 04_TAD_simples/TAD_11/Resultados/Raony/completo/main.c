#include <stdio.h>
#include "loja.h"

#define MAX 1001
#define TRUE 1

int main () {
    int nLojas = 0, operacaoEscolhida = 0, id = 0;
    float valor = 0, aluguel = 0, pctComissao = 0;
    char nome[MAX];
    scanf("%d", &nLojas);
    tLoja loja[nLojas];
    tVendedor vendedor;

    while (TRUE) {
        scanf("%d", &operacaoEscolhida);
        switch (operacaoEscolhida) {
            case 0:
                return 0;
                break;

            case 1:
                scanf("%d %f", &id, &aluguel);
                loja[id-1] = AbreLoja(id, aluguel);
                break;

            case 2:
                scanf("%s %f .%f", nome, &valor, &pctComissao);
                scanf("%d", &id);
                vendedor = RegistraVendedor(nome, valor, pctComissao);
                loja[id-1] = ContrataVendedor(loja[id-1], vendedor);
                break;

            case 3:
                scanf("%d %s %f", &id, nome, &valor);
                loja[id-1] = RegistraVenda(loja[id-1], nome, valor);
                break;

            case 4:
                for (int i = 0; i < nLojas; i++) {
                    ImprimeRelatorioLoja(loja[i]);
                }
                break;
        }
    }
    return 0;
}