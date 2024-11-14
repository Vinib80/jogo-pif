/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <string.h>
#include <stdlib.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "fases.h"


int x = 3, y = 8;
int incX = 2, incY = 1;

TamanhoF fase1;
char **matriz1;

void printHello(int nextX, int nextY, int minX, int maxX, char **matriz){
    if (matriz[nextY][nextX] != '#' && nextX > minX && nextX < maxX) {
        
        screenSetColor(CYAN, DARKGRAY);
        screenGotoxy(x, y);
        printf(" ");
        x = nextX;
        y = nextY;
        screenGotoxy(x, y);
        printf("■");
    }
}


int main() {
    int nextX, nextY;
    static int ch = 0;

    printFase1();
    keyboardInit();
    timerInit(50);

    printHello(x, y, fase1.minX, fase1.maxX, matriz1);
    screenUpdate();

    while(ch != 10){
        nextX = x;
        nextY = y;

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
        }

        printHello(nextX, nextY, fase1.minX, fase1.maxX, matriz1);
        screenUpdate();

        
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
