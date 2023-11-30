#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco {
    char *nome;
    tAgencia **  agencias;
    int qtdAgencias;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco() {
    tBanco * b = malloc(sizeof(tBanco));
    b->nome[0] = '\0';
    b->agencias = NULL;
    b->qtdAgencias = 0;
    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco) {
    for (int i = 0; i < banco->qtdAgencias; i++)
        DestroiAgencia(banco->agencias[i]);

    DestroiAgencia(banco->agencias);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco) {
    char nome[101];
    scanf("%[^\n]", nome);
    scanf("%*c");

    int tam = strlen(nome);
    banco->nome = malloc(tam+1 * sizeof(char));
    strcpy(banco->nome, nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {
    (banco->qtdAgencias)++;
    int tam = banco->qtdAgencias;
    banco->agencias = realloc(banco->agencias, tam*sizeof(tAgencia *));
    banco->agencias[tam-1] = agencia;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente) {
    
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco) {
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for (int i = 0; i < banco->qtdAgencias; i++) {
        ImprimeDadosAgencia(banco->agencias[i]);
        printf("\n");
    }
}