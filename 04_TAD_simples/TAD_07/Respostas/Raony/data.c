#include "data.h"
#include <stdio.h>

tData criaData(int dia, int mes, int ano) {
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int verificaDataValida(tData data) {
     if (data.dia > 0 && data.dia < 32 && 
        data.mes > 0 && data.mes < 13 &&
        data.ano >= 0) {
        if (data.dia <= numeroDiasMes(data)) return 1;
    } 
    return 0;
}

void imprimeMesExtenso(tData data) {
     switch (data.mes) {
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

void imprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    imprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

int verificaBissexto(tData data) {
     return ((data.ano%4 == 0) && (data.ano%100 != 0)) || (data.ano%400 == 0);
}

int numeroDiasMes(tData data) {
     if (data.mes == 2) {
        if (verificaBissexto(data)) return 29;
        else return 28;

    } else if (data.mes == 1 || data.mes == 3 || data.mes == 5 || 
               data.mes == 7 || data.mes == 8 || data.mes == 10 || 
               data.mes == 12) return 31;

    else return 30;
}

int comparaData(tData data1, tData data2) {
    if (data1.ano > data2.ano) return 1;
    if (data1.ano < data2.ano) return -1;
    
    // Se os anos forem iguais, compare os meses
    if (data1.mes > data2.mes) return 1;
    if (data1.mes < data2.mes) return -1;
    
    // Se os meses também forem iguais, compare os dias
    if (data1.dia > data2.dia) return 1;
    if (data1.dia < data2.dia) return -1;
    
    // Se chegamos até aqui, as datas são iguais
    return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int calculaDiasAteMes(tData data) {
    int dia = 0;
    for (int i = data.mes; i > 0; i--) {
        dia += numeroDiasMes(data);
    }
    return dia;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int calculaDiferencaDias(tData data1, tData data2) {
    int anoAux = 0, mesAux = 0, diferenca = 0, i = 0, subtracaoDias = 0;
    tData aux;
    
    if (data1.dia == data2.dia && data1.mes == data2.mes && data1.ano == data2.ano) return 0;
    
    // organiza o ano do menor pro maior
    if (data1.ano > data2.ano) {
        anoAux = data2.ano;
        data2.ano = data1.ano;
        data1.ano = anoAux;
    }

    // retorna qnts dias no intervalo dos anos
    aux.ano = data1.ano;
    while (aux.ano < data2.ano) {
        if (verificaBissexto(aux)) diferenca += 366;
        else diferenca + 365;
        aux.ano++;
    }

    // // retorna qnts dias no intervalo dos anos
    // for (i = data1.ano; i <  data2.ano; i++) {
    //     if (verificaBissexto(i)) diferenca += 366;
    //     else diferenca += 365;
    // }
 
    // organiza o ano do menor pro maior
    if (data1.mes > data2.mes) {
        mesAux = data2.mes;
        data2.mes = data1.mes;
        data1.mes = mesAux;
    }

    // retorna a qtd de dias no intervalo dos meses
    for (i = mes1; i < mes2; i++) {
        diferenca += numeroDiasMes(i, ano2);
    }

    // subtrai a diferenca dos dias para corrigir os dias dos meses
    diferenca += dia2 - dia1;
    return diferenca;
}
