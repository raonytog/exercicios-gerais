#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[rows][cols]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        if (i != 0) printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d ", &matrix[rows][cols]);
        }
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2);

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2);

int possible_matrix_multiply(int cols1, int rows2);

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar);