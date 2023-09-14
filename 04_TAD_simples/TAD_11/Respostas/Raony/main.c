#include <stdio.h>
#include "loja.h"

#define MAX 1001

int main () {
    int nLojas = 0, operacaoEscolhida = 0, id = 0, alugel = 0, i = 0;
    float valor = 0;
    char nome[MAX];
    scanf("%d", &nLojas);
    tLoja lojas[nLojas];

    while (1) {
        scanf("%d", &operacaoEscolhida);
        switch (operacaoEscolhida) {
        case 0:
            return 0;
            break;

        case 1:
            scanf("%d %d", &id, &alugel);
            lojas[i] = AbreLoja(id, alugel);
            break;

        case 2:
            scanf("%s %f .%d", nome, &valor, &id);
            ContrataVendedor(loja, vendedor);
            break;

        case 3:
            break;

        case 4:
            break;
        
        }

    }
    return 0;
}