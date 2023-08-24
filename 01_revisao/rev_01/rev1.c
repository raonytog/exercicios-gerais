#include <stdio.h>
#include <math.h>

typedef struct {
    float alvoX;
    float alvoY;
    float alvoR;
} tAlvo;

typedef struct {
    float disparoX;
    float disparoY;
    float disparoR;
} tDisparo;

tAlvo LeAlvo();
tDisparo LeDisparo();
void CalculaEVerificaColisao(tAlvo alvo, tDisparo disparo);

int main () {
    tAlvo alvo;
    tDisparo disparo;
    alvo = LeAlvo();
    disparo = LeDisparo();
    CalculaEVerificaColisao(alvo, disparo);
    return 0;             
}

tAlvo LeAlvo() {
    tAlvo alvo;
    scanf("%f %f %f\n", &alvo.alvoX, &alvo.alvoY, &alvo.alvoR);
    return alvo;
}

tDisparo LeDisparo() {
    tDisparo disparo;
    scanf("%f %f %f\n", &disparo.disparoX, &disparo.disparoY, &disparo.disparoR);
    return disparo;
}

void CalculaEVerificaColisao(tAlvo alvo, tDisparo disparo) {
    float distanciaEntrePontos, dX, dY;
    dX = pow( (fabs(alvo.alvoX - disparo.disparoX) ),2);
    dY = pow( (fabs(alvo.alvoY - disparo.disparoY) ),2);
    distanciaEntrePontos = sqrt(dX + dY);
    
    if (distanciaEntrePontos >= 0 && 
        distanciaEntrePontos <= alvo.alvoR) {
        printf("ACERTOU\n");
    } else printf("ERROU\n");
}