/*
Programa criado para manipular as datas com a biblioteca criada
Raony Togneri
02/09/2023
*/

#include <stdio.h>
#include "data.h"

int main () {
    int dia1, dia2, mes1, mes2, ano1, ano2;
    scanf("%02d/%02d/%04d%*c", &dia1, &mes1, &ano1);
    tData data1 = criaData(dia1, mes1, ano1);

    scanf("%02d/%02d/%04d%*c", &dia2, &mes2, &ano2);
    tData data2 = criaData(dia2, mes2, ano2);

    if (verificaDataValida(data1) && verificaDataValida(data2)) {
        printf("Primeira data: ");
        imprimeDataExtenso(data1);

        printf("Segunda data: ");
        imprimeDataExtenso(data2);

        if (comparaData(data1, data2) == 1) {
            printf("A primeira data eh mais antiga\n");
        }

        if (comparaData(data1, data2) == 0) {
            printf("As datas sao iguais\n");
        }

        if (comparaData(data1, data2) == -1) {
            printf("A segunda data eh mais antigal\n");
        }

        printf("A diferenca em dias entre as datas eh: %02d dias\n", 
                calculaDiferencaDias(data1, data2));

    } else printf("A primeira e/ou segunda data(s) invalida(s)\n");
    
    return 0;
}