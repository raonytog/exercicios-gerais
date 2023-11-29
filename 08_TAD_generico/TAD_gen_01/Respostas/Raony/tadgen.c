#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic {
    void * data;
    int size;
    Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric * gen = malloc(numElem * sizeof(tGeneric));
    gen->size = numElem;
    gen->type = type;
    gen->data = NULL;

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen) {

}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen) {
    for (int i = 0; i <)
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen) {
    switch (gen->type) {
        case 0: //float
            for (int i = 0; i < gen->size; i++)
                printf("%.2f ", gen->data[i]);
            break;

        case 1: //int     
            for (int i = 0; i < gen->size; i++)
                printf("%d ", gen->data[i]);
            break;
    
    }
}
