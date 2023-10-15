#include "tela.h"
#include <stdio.h>

Tela CriarTela(int altura, int largura) {
    Tela tela;
    tela.altura = altura;
    tela.largura = largura;
    tela.qntBotoes = 0;
    return tela;
}

void RegistraBotaoTela(Tela *t, Botao b) {
    if (t->qntBotoes >= MAX_BOTOES) return;

    int num = t->qntBotoes;
    t->botoes[num] = b;
    t->qntBotoes++;
}

void DesenhaTela(Tela t) {
    if (t.qntBotoes <= 0) return;

    printf("##################\n");
    for (int i = 0; i < t.qntBotoes; i++) 
        DesenhaBotao(t.botoes[i], i);
    printf("##################\n");
}

void OuvidorEventosTela(Tela t) {
    int num = 0;
    printf("- Escolha sua acao: ");
    scanf("%d", &num);

    if (num >= 0 && num < t.qntBotoes) 
        ExecutaBotao(t.botoes[num]);

    return;
}
