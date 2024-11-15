#ifndef FASES_H
#define FASES_H

#include <stdio.h>

typedef struct {
    int minY;
    int maxY;
    int minX;
    int maxX;
}TamanhoF;

/*#define MIN_Y  0
#define MAX_Y  16
#define MIN_X  0
#define MAX_X  80*/

extern TamanhoF fase1;
extern char **matriz1;


void printFase1();

#endif 