#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "balls.h"

void PosicaoBolas(){

    const int numBolas = 7;

    for(int i = 0; i < numBolas; i++){
        bolas[i].bolaX = 10 + (i * 10);
        bolas[i].bolaY = fase1.minY;
        bolas[i].bolaincY = i; 
    }
}
