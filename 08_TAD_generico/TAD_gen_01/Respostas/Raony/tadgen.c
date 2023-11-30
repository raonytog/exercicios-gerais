#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic {
    void * data;
    int size;
    Type type;
};

tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric * gen = malloc(sizeof(tGeneric));
    gen->size = numElem;
    gen->type = type;

    if (type == INT) gen->data = malloc(numElem * sizeof(int));
    else if (type == FLOAT) gen->data = malloc(numElem * sizeof(float));

    return gen;
}

void DestroiGenerico(tGeneric* gen) {
    free(gen->data);
    free(gen);
}

void LeGenerico(tGeneric* gen) {
    printf("\nDigite o vetor:\n");
    switch (gen->type) {
        case FLOAT:
            for (int i = 0; i < gen->size; i++) {
                scanf("%f", (float *) gen->data + i*sizeof(float));
                scanf("%*c");
            }
            break;

        case INT:
            for (int i = 0; i < gen->size; i++) {
                scanf("%d", (int *) gen->data + i*sizeof(int));
                scanf("%*c");
            }
            break;
    }
}

void ImprimeGenerico(tGeneric* gen) {
    switch (gen->type) {
        case FLOAT:
            for (int i = 0; i < gen->size; i++) {
                printf("%.2f ", *((float *) gen->data + i*sizeof(float)));
            }
            break;

        case INT:
            for (int i = 0; i < gen->size; i++) {
                printf("%d ", *((int *) gen->data + i*sizeof(int)) );
            }
            break;
    }
    printf("\n");
}
