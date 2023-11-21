#include "produto.h"
#include <stdlib.h>
#include <string.h>

struct Produto {
    int codigo;
    char *nomeProduto;
    float preco;
    int qtd;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade) {
    tProduto * produto = malloc(sizeof(tProduto));
    if (!produto) exit(1);

    produto->codigo = codigo;
    produto->preco = preco;
    produto->qtd = quantidade;

    produto->nomeProduto = malloc((strlen(nome)+1) * sizeof(char));
    strcpy(produto->nomeProduto, nome);

    return produto;
}

void DestroiProduto(tProduto *produto) {
    free(produto->nomeProduto);
    free(produto);
}

tProduto *LeProduto(FILE *arquivo) {
    int code = 0, qtd = 0;
    char name[51];  float price = 0;

    fread(&code, sizeof(code), 1, arquivo);
    fread(&name, (stlens(name)+1) * sizeof(name), 1, arquivo);
    fread(&price, sizeof(price), 1, arquivo);
    fread(&qtd, sizeof(qtd), 1, arquivo);

    tProduto * produto = CriaProduto(code, name, price, qtd);
    return produto;
}

int TemEstoqueProduto(tProduto *produto) {
    if (produto->qtd > 0) return 1;
    return 0;
}

void ImprimeProduto(tProduto *produto) {
    printf("%d,%s,%.2f\n", produto->codigo, produto->nomeProduto, produto->preco);
}