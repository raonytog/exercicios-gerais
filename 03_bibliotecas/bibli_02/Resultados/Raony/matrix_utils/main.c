/*
Programa que manipula matrizes com a biblioteca criada
Raony Togneri
02/09/2023
*/

#include "matrix_utils.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX 256

int main () {
    int rows1 = 0, rows2 = 0, cols1 = 0, cols2 = 0;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

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
                if (possible_matrix_sum(rows1, cols1, rows2,cols2)) {
                    int result[rows1][cols2];
                    matrix_add(rows1, cols1, matrix1, 
                            rows2, cols2, matrix2, 
                            result);
                    matrix_print(rows1, cols1, result);
                } else printf("Erro: as dimensoes da matriz nao correspondem\n");
                break;

            case 2:
                if (possible_matrix_sub(rows1, cols1, rows2,cols2)) {
                    int result[rows1][cols2];
                    matrix_sub(rows1, cols1, matrix1, 
                            rows2, cols2, matrix2, result);
                    matrix_print(rows1, cols1, result);
                } else printf("Erro: as dimensoes da matriz nao correspondem\n");
                break;

            case 3:
                if (possible_matrix_multiply(cols1, rows2)) {
                    int result[rows1][cols1];
                    matrix_multiply(rows1, cols1, matrix1, 
                                    rows2, cols2, matrix2, result);
                    matrix_print(rows1, cols2, result);
                } else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                break;

            case 4:
                int scalar = 0, whichMatrix = 0;
                scanf("%d %d%*c", &scalar, &whichMatrix);
                switch (whichMatrix) {
                    case 1:
                        scalar_multiply(rows1, cols1, matrix1, scalar);
                        matrix_print(rows1, cols1, matrix1);
                        break;

                    case 2:
                        scalar_multiply(rows2, cols2, matrix2, scalar);
                        matrix_print(rows2, cols2, matrix2);
                        break;
                }
                break;

            case 5:
                int result1[MAX][MAX];
                transpose_matrix(rows1, cols1, matrix1, result1);
                matrix_print(cols1, rows1, result1);
                printf("\n");

                int result2[MAX][MAX];
                transpose_matrix(rows2, cols2, matrix2, result2);
                matrix_print(cols2, rows2, result2);
                break;

            case 6:
                flagExit = 1;
                break;
        }

        if (flagExit) break;
        printf("\n");
    }
    
    return 0;
}