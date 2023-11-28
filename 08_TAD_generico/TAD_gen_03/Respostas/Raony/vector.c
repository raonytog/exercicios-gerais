#include <vector.h>
#include <stdio.h>
#include <stdlib.h>

typedef void* data_type; // void pointer

struct Vector {
    data_type * data;
    int tam;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {
    Vector * v = malloc(sizeof(Vector));

    v->tam = 0;
    v->data = NULL;
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val) {
    if (!v) return;

    (v->tam)++;
    v->data[v->tam-1] = val;
    v->data = realloc(v->data, VectorSize(v) * sizeof(data_type));
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i) {
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {
    if (!v) return 0;
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    if (!v) return;
    for (int i = 0; i < VectorSize(v); i++)
        destroy(v->data[i]);
        
    destroy(v->data);
    free(v);
}