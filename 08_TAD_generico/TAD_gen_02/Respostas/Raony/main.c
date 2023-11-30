#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdio.h>

void BufferClear () {
    scanf("%*c");
}

void ImprimeMenu () {
    printf("Escolha uma opcao:\n");
	printf("(1) Cadastrar um novo pacote\n");
	printf("(2) Imprimir um pacote específico\n");
	printf("(3) Imprimir todos os pacotes e sair\n");
}

typedef enum {
    NOVO_PACOTE = 1,
    IMPRIME_UNICO = 2,
    IMPRIME_TODOS = 3
} Opcoes;

int main () {
    printf("tad_gen_02\n");

    int opcao = 0, type = -1, size = 0, indice = 0;
    tGerenciador * gerenciador = CriaGerenciador();

    while (1) {
        ImprimeMenu();
        scanf("%d", &opcao);
        BufferClear();

        switch (opcao) {
            case NOVO_PACOTE:
                printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
                scanf("%d %d", &type, &size);
                BufferClear();
                tPacote * p = CriaPacote(type, size);
                LePacote(p);
                AdicionaPacoteNoGerenciador(gerenciador, p);
                break;

            case IMPRIME_UNICO:
                scanf("%d", &indice);
                ImprimirPacoteNoIndice(gerenciador, indice);
                BufferClear();
                break;

            case IMPRIME_TODOS:
                ImprimirTodosPacotes(gerenciador);
                DestroiGerenciador(gerenciador);
                exit(1);
                break;
        }
    }


    return 0;
}