#include "matrix_utils.h"
#include <stdio.h>

/**
 * @brief Lê os valores da matriz especificada a partir da entrada padrão.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser preenchida.
 */
void matrix_read(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

/**
 * @brief Imprime a matriz especificada na saída padrão.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser impressa.
 */
void matrix_print(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        if (i != 0) printf("\n");
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j != cols-1) printf(" ");
            else printf("|");
        }
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2) {
    return rows1 == rows2 && cols1 == cols2;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2) {
    return rows1 == rows2 && cols1 == cols2;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int possible_matrix_multiply(int cols1, int rows2) {
    return cols1 == rows2;
}

/**
 * @brief Soma duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da soma.
 */
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], 
                int rows2, int cols2, int matrix2[rows2][cols2], 
                int result[rows1][cols1]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/**
 * @brief Subtrai duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da subtração.
 */
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], 
                int rows2, int cols2, int matrix2[rows2][cols2], 
                int result[rows1][cols1]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

/**
 * @brief Multiplica duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da multiplicação.
 */
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], 
                     int rows2, int cols2, int matrix2[rows2][cols2], 
                     int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

/**
 * @brief Transpõe a matriz especificada.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser transposta.
 * @param result Matriz que armazenará o resultado da transposição.
 */
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

/**
 * @brief Multiplica a matriz especificada por um escalar.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser multiplicada.
 * @param scalar Escalar a ser multiplicado.
 */
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}
