#include <stdio.h>
#include "tela.h"

void buttom_0 () {
    printf("- Botao de SALVAR dados ativado!\n");
}

void buttom_1 () {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void buttom_2 () {
    printf("- Botao de OPCOES ativado!\n");
}

int main () {
    Tela telinha = CriarTela(400, 200);
    Botao botaozinho;

    botaozinho = CriarBotao("Salvar", 12, "FFF", 1, buttom_0);
    RegistraBotaoTela(&telinha, botaozinho);

    botaozinho = CriarBotao("Excluir", 18, "000", 1, buttom_1);
    RegistraBotaoTela(&telinha, botaozinho);

    botaozinho = CriarBotao("Opcoes", 10, "FF0000", 2, buttom_2);
    RegistraBotaoTela(&telinha, botaozinho);

    DesenhaTela(telinha);
    OuvidorEventosTela(telinha);
    
    return 0;
}