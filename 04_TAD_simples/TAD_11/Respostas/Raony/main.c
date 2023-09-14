#include <stdio.h>
#include "loja.h"

int main () {
    int nLojas = 0, operacaoEscolhida = 0, id = 0, alugel = 0, i = 0;
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
            
            break;

        case 3:
            break;

        case 4:
            break;
        
        }

    }
    return 0;
}