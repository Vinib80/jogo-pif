#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "balls.h"

struct bola *bolas = NULL;

const int numBolas = 7;

void PosicaoBolas(){
    
    bolas = malloc(numBolas * sizeof(struct bola));

    for(int i = 0; i < numBolas; i++){
        bolas[i].bolaX = 10 + (i * 10);
        bolas[i].bolaY = fase1.minY;
        bolas[i].bolaincY = 1; 
    }
}

void printBolas(){
    for(int i = 0; i < numBolas; i++){
        int nextY = bolas[i].bolaY + bolas[i].bolaincY;

        if(matriz1[nextY][bolas[i].bolaX] != '#' && nextY >= fase1.minY && nextY < fase1.maxY){
            screenSetColor(BLUE, DARKGRAY);
            screenGotoxy(bolas[i].bolaX, bolas[i].bolaY);
            printf(" ");
            bolas[i].bolaY = nextY;
            screenGotoxy(bolas[i].bolaX, bolas[i].bolaY);
            printf("●");

        }
    }
}