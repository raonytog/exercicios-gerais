#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    data_type * data;
    int tam;
};

Vector *VectorConstruct() {
    Vector * v = malloc(sizeof(Vector));
    v->tam = 0;
    v->data = NULL;
    return v;
}

void VectorPushBack(Vector *v, data_type val) {
    if (!v) return;

    (v->tam)++;
    v->data = realloc(v->data, VectorSize(v) * sizeof(data_type));
    v->data[v->tam-1] = val;
}

data_type VectorGet(Vector *v, int i) {
    return v->data[i];
}

int VectorSize(Vector *v) {
    if (!v) return 0;
    return v->tam;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    if (!v) return;
    for (int i = 0; i < VectorSize(v); i++)
        destroy(v->data[i]);
        
    destroy(v->data);
    free(v);
}