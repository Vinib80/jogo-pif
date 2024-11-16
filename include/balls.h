#ifndef BALLS_H
#define BALLS_H

#include <stdio.h>
#include "fases.h"

struct bola {
    int bolaX;
    int bolaY;
    int bolaincY;
};

extern struct bola *bolasTopo;
extern struct bola *bolasBaixo;

extern const int numBolasT;
extern const int numBolasB;

void posicaoBolasT();
void printBolasT();
void posicaoBolasB();
void printBolasB();

#endif