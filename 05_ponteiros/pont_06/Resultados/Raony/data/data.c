#include <stdio.h>
#include "data.h"

void InicializaDataParam(int dia, int mes, int ano, tData *data) {
    data->ano = ano;

    // trata meses incorretos
    data->mes = mes;
    if (mes > 12) {
        data->mes = 12;
    }
    
    // trata dias incorretos
    data->dia = dia;
    if (dia > InformaQtdDiasNoMes(data)) {
        data->dia = InformaQtdDiasNoMes(data);
    }
}

void LeData(tData *data) {
    int dia = 0, mes = 0, ano = 0;
    scanf("%2d %2d %4d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData(tData *data) {
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto(tData *data) {
    if (data->ano%4 == 0 && data->ano%100 != 0) return 1;
    if (data->ano%400 == 0) return 1;
    return 0;
}

int InformaQtdDiasNoMes(tData *data) {
    if (data->mes == 2) {
        if (EhBissexto(data)) return 29;
        else return 28;

    } else if (data->mes == 1 || data->mes == 3 || data->mes == 5 || 
               data->mes == 7 || data->mes == 8 || data->mes == 10 || 
               data->mes == 12) return 31;

    else return 30;
}

void AvancaParaDiaSeguinte(tData *data) {
    if (data->dia +1 > InformaQtdDiasNoMes(data)) {
        data->dia = 1;
        data->mes += 1;

        if (data->mes > 12) {
            data->ano += 1;
            data->mes = 1;
        }

    } else data->dia++;
}


int EhIgual(tData *data1, tData *data2) {
    if (data1->ano > data2->ano) return 0;
    else if (data1->ano < data2->ano) return 0;
    // anos iguais, entao verificamos os meses

    if (data1->mes > data2->mes) return 0;
    else if (data1->mes < data2->mes) return 0;
    // meses iguais, entao verificamos os dias tb

    if (data1->dia == data2->dia) return 1;
    // entao os dias tb sao diferentes
    return 0;
}