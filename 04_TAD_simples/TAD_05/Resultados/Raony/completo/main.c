#include "conta.h"
#include "usuario.h"
#include <stdio.h>

int main () {
    int numContas = 0, option = 0, valor = 0,
        user = 0, num = 0;
    scanf("%d%*c", &numContas);
    tConta contas[numContas];
    tUsuario usuario;

    char nome[50], cpf[15];
    while (scanf("%d", &option) == 1) {
        switch (option) {
        case 0:
            return 0;
            break;

        case 1: //saque
            scanf("%d %d", &user, &valor);
            contas[user-1] = saque(contas[user-1], valor);
            break;  

        case 2: //deposito
            scanf("%d %d", &user, &valor);
            contas[user-1] = deposito(contas[user-1], valor);
            break;  

        case 3: //cadastra
            scanf("%50s %15s %d", &nome, &cpf, &num);
            usuario = criar_usuario(nome, cpf);
            contas[num-1] = criar_conta(num, usuario);
            break;

        case 4: //relatorio
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < numContas; i++) {
                imprime_conta(contas[i]);
            }
            break;
        }
    }
    return 0;
}