#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

tBiblioteca inicializarBiblioteca() {
    tBiblioteca biblioteca;
    biblioteca.tamanho = 0;
    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    if (biblioteca.tamanho == MAX_LIVROS) {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
        return biblioteca;
    }

    // se chegou aqui, é pq ainda cabe pelo menos um livro
    biblioteca.tamanho++;
    int tam = biblioteca.tamanho;
    biblioteca.livros[tam-1] = livro;
    printf("Livro adicionado com sucesso!\n");
    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo) {
    tLivros livro;
    int i = 0, encontrado = 0;
    // procura o livro
    for (i = 0; i < biblioteca.tamanho; i++) {
        livro = biblioteca.livros[i];
        if (strcmp(livro.titulo, titulo) == 0) {
            encontrado = 1;
            break;
        }
    }

    // se nao encontrou
    if (!encontrado) {
        printf("Livro nao encontrado na biblioteca.\n");
        return biblioteca;
    }

    // se encontrou
    for (int j = i; j < biblioteca.tamanho && j+1 < biblioteca.tamanho; j++) {
        biblioteca.livros[j] = biblioteca.livros[j+1];
    }

    biblioteca.tamanho--;
    printf("Livro removido com sucesso!\n");
    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo) {
    return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    int i = 0;
    if (biblioteca.tamanho > 0 ) {
        printf("\nLista de Livros na Biblioteca:\n");
        for (i = 0; i < biblioteca.tamanho; i++) {
            imprimeLivro(biblioteca.livros[i]);
        }

    } else printf("A biblioteca esta vazia!");
}
