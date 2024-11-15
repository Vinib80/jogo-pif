#ifndef BALLS_H
#define BALLS_H

#include <stdio.h>
#include "fases.h"

struct bola {
    int bolaX;
    int bolaY;
    int bolaincY;
};

extern struct bola *bolas;
extern const int numBolas;

void PosicaoBolas();
void printBolas();

#endif