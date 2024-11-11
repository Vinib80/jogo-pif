/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <string.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "fases.h"

char matriz1[MAX_Y][MAX_X];

int x = 3, y = 8;
int incX = 2, incY = 1;

void printHello(int nextX, int nextY){
    if (matriz1[nextY][nextX] != '#' && nextX > MIN_X) {
        
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

    printHello(x, y);
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

        printHello(nextX, nextY);
        screenUpdate();
        
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
