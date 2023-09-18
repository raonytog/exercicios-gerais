#include "biblioteca.h"
#include <stdio.h>

int main () {
    tLivros livro;
    tBiblioteca biblioteca = inicializarBiblioteca();
    int i = 0, nOperacoes = 0, operacaoEscolhida = 0;
    char titulo[100];
    scanf("%d", &nOperacoes);
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");

    for (i = 0; i < nOperacoes; i++) {
        while (scanf("%d", &operacaoEscolhida) == 1) {
            switch (operacaoEscolhida) {
                case 1:
                    livro = lerLivro();
                    biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
                    break;

                case 2:
                    scanf("%s", titulo);
                    biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
                    break;

                case 3:
                    listarLivrosDaBiblioteca(biblioteca);
                    break;

                default:
                    printf("Operacao invalida!\n");
                    break;
            }
        }
    }
    return 0;
}