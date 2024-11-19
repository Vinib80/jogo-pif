#include <string.h>
#include <stdlib.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "fases.h"
#include "balls.h"
#include "fase2.h"

int x = 3, y = 8;
int incX = 2, incY = 1;

void printHello(int nextX, int nextY, int minX, int maxX, char **matriz){
    if (matriz[nextY][nextX] != '#' && nextX > minX && nextX < maxX) {
        
        screenSetColor(RED, DARKGRAY);
        screenGotoxy(x, y);
        printf(" ");
        x = nextX;
        y = nextY;
        screenGotoxy(x, y);
        printf("■");

        //coordenadas
        
    }
}
int main() {
    int nextX, nextY;
    static int ch = 0;
    static long timer = 0;

    printFase1();
    posicaoBolasT();
    posicaoBolasB();
    screenUpdate();
    keyboardInit();
    timerInit(50);

    printHello(x, y, fase1.minX, fase1.maxX, matriz1);
    printBolasT();
    printBolasB();
    screenUpdate();
    int fim = 0;


    while(ch != 10 && timer <= 100){
        nextX = x;
        nextY = y;

        if(fim == 1){
            break;
        }
        if(keyhit()){
            ch = getchar();

            switch(ch){
                case 119: 
                    nextY = y - incY;
                    break;

                case 115: 
                    nextY = y + incY;
                    break;

                case 97:
                    nextX = x - incX;
                    break;

                case 100: 
                    nextX = x + incX;
                    break;
            }

            printHello(nextX, nextY, fase1.minX, fase1.maxX, matriz1);
            if (nextX == 79 && (nextY >= 6 && nextY <= 9)) {
                screenGotoxy(x, y);
                fim = 1;

            }
            
            screenUpdate();
        }

        if(timerTimeOver() == 1){
            printHello(nextX, nextY, fase1.minX, fase1.maxX, matriz1);
            printBolasT();
            printBolasB();
            screenUpdate();
            timer++;

        }
        
    }
    inicioFase2();

    while(ch != 10){
        if(keyhit()){
            ch = readch();
        }
    }

    for(int i = 0; i < fase1.maxY; i++){
        free(matriz1[i]);
    }
    free(matriz1);

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
