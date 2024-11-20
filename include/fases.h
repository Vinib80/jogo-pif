#ifndef FASES_H
#define FASES_H

#include <stdio.h>

typedef struct {
    int minY;
    int maxY;
    int minX;
    int maxX;
}TamanhoF;

extern TamanhoF fase1;
extern char **matriz1;
extern int cont_mortes;


void printFase1();
void mortes(int mortes);


#endif 


