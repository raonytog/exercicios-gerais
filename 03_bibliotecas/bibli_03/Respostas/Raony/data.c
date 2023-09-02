#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano) {
    if (dia > 0 && dia < 32 && mes > 0 && mes < 13) {
        if (dia <= numeroDiasMes(mes, ano)) return 1;
    } 
    return 0;
}

void imprimeMesExtenso(int mes) {
    switch (mes) {
    case 1:
        printf("Janeiro");
        break;

    case 2:
        printf("Fevereiro");
        break;

    case 3:
        printf("Marco");
        break;

    case 4:
        printf("Abril");
        break;

    case 5:
        printf("Maio");
        break;

    case 6:
        printf("Junho");
        break;

    case 7:
        printf("Julho");
        break;

    case 8:
        printf("Agosto");
        break;

    case 9:
        printf("Setembro");
        break;

    case 10:
        printf("Outubro");
        break;

    case 11:
        printf("Novembro");
        break;

    case 12:
        printf("Dezembro");
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int verificaBissexto(int ano) {
    return ((ano%4 == 0) && (ano%100 != 0)) || (ano%400 == 0);
}

int numeroDiasMes(int mes, int ano) {
    if (mes == 2) {
        if (verificaBissexto(ano)) return 29;
        else return 28;

    } else if (mes == 1 || mes == 3 || mes == 5 || 
               mes == 7 || mes == 8 || mes == 10 || 
               mes == 12) return 31;

    else return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (dia1 == dia2) {
        if (mes1 == mes2) {
            if (ano1 == ano2) return 0;
            else if (ano1 > ano2) return 1;
            else return -1;
        }
            
        else if (mes1 > mes2) return 1;
        else return -1;
    }
        
    else if (dia1 > dia2) return 1;
    return -1;
}

int calculaDiasAteMes(int mes, int ano) {
    int dia = 0;
    for (int i = mes; i > 0; i--) {
        dia += numeroDiasMes(i, ano);
    }
    return dia;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int mesAux = 0, diaAux = 0, diferenca = 0;
    if (dia1 == dia2 && mes1 == mes2 && ano1 == ano2) return 0;

    if (dia1 == dia2 && mes1 == mes2 && ano1 != ano2) {
        if (verificaBissexto(ano2)) return 366;
        return 365;
    }

    if (ano1 == ano2) {
        if (mes1 > mes2) {
            mesAux = mes2;
            diaAux = dia2;

            mes1 = mes2;
            dia1 = dia2;

            mes2 = mesAux;
            dia2 = diaAux;
        }

    } else {
        if (verificaBissexto(ano2)) diferenca += 366;
        else diferenca += 365;

        if (mes1 > mes2) {
            mesAux = mes2;
            diaAux = dia2;

            mes1 = mes2;
            dia1 = dia2;

            mes2 = mesAux;
            dia2 = diaAux;
        }
    }

    for (int i = mes1; i < mes2; i++) {
        diferenca += numeroDiasMes(i, ano2);
    }

    if (dia1 > dia2) diferenca += dia1 - dia2;
    else if (dia2 > dia1) diferenca += dia2 - dia1;

    return diferenca;
}