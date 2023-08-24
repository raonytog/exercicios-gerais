#include <stdio.h>

int main () {
    int numN, cont = 0;
    scanf("%d\n", &numN);

    for (int i = 0; i < numN; i++) {
        if (i != 0) printf("\n");
        for (int j = 0; j <= i; j++) {
            cont++;
            printf("%d ", cont);
        }
    }

    return 0;
}