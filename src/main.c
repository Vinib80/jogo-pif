#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "fases.h"
#include "fase2.h" 

char matriz1[MAX_Y][MAX_X];
int x = 3, y = 8;
int incX = 2, incY = 1;

void printHello(int nextX, int nextY){
    if (matriz1[nextY][nextX] != '#' && nextX > MIN_X && nextX < MAX_X) {
        
        screenSetColor(CYAN, DARKGRAY);
        screenGotoxy(x, y);
        printf(" ");
        x = nextX;
        y = nextY;
        screenGotoxy(x, y);
        printf("■");

        //coordenadas
        if (x == 79 && (y >= 6 && y <= 9)) {
            screenGotoxy(x, y);
            printf("Parabéns!\n");

            //chama a função de fase2.c
            inicioFase2();
        }
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
