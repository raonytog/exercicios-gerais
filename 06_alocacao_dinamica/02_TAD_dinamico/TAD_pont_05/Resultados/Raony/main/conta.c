#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tConta *CriaConta() {
    tConta * conta = (tConta*) malloc(sizeof(tConta));
    if (conta == NULL) {
        printf("Alocacao impropria em conta.c\n");
        exit(1);
    }
    return conta;
}

void DestroiConta(tConta *conta) {
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta) {
    tUsuario * usuario = CriaUsuario();
    LeUsuario(usuario);
    scanf("%d", &conta->numero);
}


void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: %f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    return conta->numero == numero;
}

void SaqueConta(tConta *conta, float valor) {
    conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor)  {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    origem->saldo -= valor;
    destino->saldo += valor;
}