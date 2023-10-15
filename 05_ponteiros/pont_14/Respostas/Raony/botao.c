#include "botao.h"
#include <stdio.h>
#include <string.h>

void SetarTexto(Botao *b, char *novoTexto) {
    if (strlen(novoTexto) > MAX_TAM_TEXTO) return;
    else strcpy(b->texto, novoTexto);
}

void SetarTamFonte(Botao *b, int novoTamFonte) {
    if (novoTamFonte <= 0) return;
    else b->tamFonte = novoTamFonte;
}

void SetarCor(Botao *b, char *novaCor) {
    strcpy(b->corHex, novaCor);
}

void SetarTipo(Botao *b, int novoTipo) {
    b->tipo = novoTipo;
}

Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)) {
    Botao buttom;
    SetarTexto(&buttom, texto);
    SetarTamFonte(&buttom, tamFonte);
    SetarCor(&buttom, cor);
    SetarTipo(&buttom, tipo);
    buttom.executa = executa;
    return buttom;
}

/**
 * @brief Executa a função associada ao botão especificado de acordo com o tipo de evento que o botão pode receber.
 * Se o tipo de evento for inválido, o programa é encerrado.
 * 
 * @param b Botão que terá sua função executada.
 */
void ExecutaBotao(Botao b) {
    switch (b.tipo) {
        case LONGO_CLICK:
            printf("- Executando o botao com evento de longo click\n");
            break;

        case CLICK:
            printf("- Executando o botao com evento de click\n");
            break;

        case HOVER:
            printf("- Executando o botao com evento de hover\n");
            break;
    }
    
    b.executa();
}

/**
 * @brief Desenha o botão especificado na posição especificada na tela.
 * 
 * @param b Botão a ser desenhado.
 * @param idx Índice do botão na tela em que será desenhado.
 */
void DesenhaBotao(Botao b, int idx) {
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n\n");
}
