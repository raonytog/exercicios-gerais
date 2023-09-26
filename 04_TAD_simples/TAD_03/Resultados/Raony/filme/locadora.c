#include "filme.h"
#include "locadora.h"


tLocadora criarLocadora () {
    tLocadora locadora;
    locadora.lucro = 0;
    locadora.numFilmes = 0;
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    for (int i = 0; i < locadora.numFilmes; i++) {
        tFilme filme = locadora.filme[i];
        if (filme.codigo == codigo) return 1;
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade) {
    tFilme filme = criarFilme(nome, codigo, valor, quantidade);
    locadora.filme[locadora.numFilmes] = filme;
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora) {
    int codigo = 0, valor = 0, quantidade = 0;
    char nome[MAX_CARACTERES];
    scanf("%d,%[^,],%d,%d", &codigo, nome, &valor, &quantidade);
    locadora = cadastrarFilmeLocadora(locadora, nome, codigo, valor, quantidade);
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora);

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora);

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora);

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora);

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora);