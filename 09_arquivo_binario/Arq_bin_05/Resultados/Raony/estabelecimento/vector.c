#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

struct Vector {
    DataType ** data;
    int qtdData;
};

Vector *VectorConstruct() {
    Vector * v = malloc(sizeof(Vector));
    v->data = NULL;
    v->qtdData = 0;
    return v;
}

void VectorPushBack(Vector *v, DataType val) {
    v->data[VectorSize(v)] = val;
    (v->qtdData)++;
    v->data = realloc(v->data, VectorSize(v) * sizeof(Vector));
}

DataType VectorGet(Vector *v, int i) {
    return v->data[i];
}

int VectorSize(Vector *v) {
    return v->qtdData;
}


void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    destroy(v->data);
    free(v);
}
