#include "matrix_utils.h"
#include <stdio.h>

tMatrix matrix_create(int rows, int cols) {
    tMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

tMatrix matrix_read(tMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            scanf("%d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

void matrix_print(tMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        if (i != 0) printf("\n");
        printf("|");
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d", matrix.data[i][j]);
            if (j != matrix.cols - 1) printf(" ");
            else printf("|");
        }
    }
    printf("\n");
}

int possible_matrix_sum(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows;
}

int possible_matrix_sub(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows;
}

int possible_matrix_multiply(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.rows == matrix2.cols;
}


tMatrix matrix_add(tMatrix matrix1, tMatrix matrix2) {
    tMatrix sum;
    sum.cols = matrix1.cols;
    sum.rows = matrix1.rows;

    for (int i = 0; i < sum.rows; i++) {
        for (int j = 0; j < sum.cols; j++) {
            sum.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return sum;
}

tMatrix matrix_sub(tMatrix matrix1, tMatrix matrix2) {
    tMatrix sub;
    sub.cols = matrix1.cols;
    sub.rows = matrix1.rows;
    
    for (int i = 0; i < sub.rows; i++) {
        for (int j = 0; j < sub.cols; j++) {
            sub.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }

    return sub;
}

tMatrix matrix_multiply(tMatrix matrix1, tMatrix matrix2) {
    tMatrix multiply;
    multiply.rows = matrix1.rows;
    multiply.cols = matrix2.cols;

    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            multiply.data[i][j] = 0;
            for (int k = 0; k < matrix1.cols; k++) {
                multiply.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }

    return multiply;
}

tMatrix transpose_matrix(tMatrix matrix) {
    tMatrix transpose;
    transpose.rows = matrix.cols;
    transpose.cols = matrix.rows;

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            transpose.data[j][i] = matrix.data[i][j];
        }
    }

    return transpose;
}


tMatrix matrix_multiply_by_scalar(tMatrix matrix, int scalar) {
     for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            matrix.data[i][j] *= scalar;
        }
    }
    return matrix;
}