/*
Programa que manipula matrizes com a biblioteca criada e o TAD implementado
Raony Togneri
11/09/2023
*/

#include "matrix_utils.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main () {
    int rows1 = 0, rows2 = 0, cols1 = 0, cols2 = 0;

    scanf("%d %d", &rows1, &cols1);
    tMatrix matrix1;
    matrix1 = matrix_create(rows1, cols1);
    matrix1 = matrix_read(matrix1);

    scanf("%d %d", &rows2, &cols2);
    tMatrix matrix2;
    matrix2 = matrix_create(rows2, cols2);
    matrix2 = matrix_read(matrix2);

    tMatrix result;
    int choosenOption = 0, flagExit = 0;
    while (TRUE) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");
        scanf("%d", &choosenOption);
        printf("\n");

        switch (choosenOption) {
            case 1:
                if (possible_matrix_sum(matrix1, matrix2)) {
                    result = matrix_create(rows1, cols1);
                    result = matrix_add(matrix1, matrix2);
                    matrix_print(result);

                } else printf("Erro: as dimensoes da matriz nao correspondem\n");
                break;

            case 2:
                if (possible_matrix_sub(matrix1, matrix2)) {
                    result = matrix_create(rows1, cols1);
                    result = matrix_sub(matrix1, matrix2);
                    matrix_print(result);

                } else printf("Erro: as dimensoes da matriz nao correspondem\n");
                break;

            case 3:
                if (possible_matrix_multiply(matrix1, matrix2)) {
                    result = matrix_create(rows1, cols2);
                    result = matrix_multiply(matrix1, matrix2);
                    matrix_print(result);

                } else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                break;

            case 4:
                int scalar = 0, whichMatrix = 0;
                scanf("%d %d%*c", &scalar, &whichMatrix);
                switch (whichMatrix) {
                    case 1:
                        matrix1 = matrix_multiply_by_scalar(matrix1, scalar);
                        matrix_print(matrix1);
                        break;

                    case 2:
                        matrix2 = matrix_multiply_by_scalar(matrix2, scalar);
                        matrix_print(matrix2);
                        break;
                }
                break;

            case 5:
                result = matrix_create(cols1, rows1);
                result = transpose_matrix(matrix1);
                matrix_print(result);
                printf("\n");

                result = matrix_create(cols2, rows2);
                result = transpose_matrix(matrix2);
                matrix_print(result);
                printf("\n");
                break;

            case 6:
                return 0;
                break;
        }

        printf("\n");
    }
    
    return 0;
}