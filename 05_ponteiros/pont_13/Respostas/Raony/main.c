#include <stdio.h>
#include <string.h>
#include "rolagem.h"

int main () {
    int numMsg = 0, timer = 0;
    char fraseTemp[1000];
    fraseTemp[0] = '\0';

    char frase[1000];
    frase[0] = '\0';

    scanf("%d", &numMsg);

    for (int i = 0; i < numMsg; i++) {
        scanf("%*[^-]-%*c");
        scanf("%[^\n]\n", fraseTemp);
        strcat(frase, fraseTemp);
        if (i != numMsg-1) strcat(frase, " ");
    }

    scanf("%d", &timer);


    return 0;
}