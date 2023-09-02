#include <stdio.h>
#include "data.h"

int main () {
    int dia, mes, ano;
    scanf("%02d/%02d/%04d%*c", &dia, &mes, &ano);

    if (verificaDataValida(dia, mes, ano)) {
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);

        if (verificaBissexto(ano)) printf("O ano informado eh bissexto\n");
        else printf("O ano informado nao eh bissexto\n");

        printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));

        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
        printf("\n");

    } else printf("A data informada eh invalida\n");
    
    return 0;
}