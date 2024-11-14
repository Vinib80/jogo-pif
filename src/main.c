#include <string.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "fases.h"

int x = 34, y = 12;
int incX = 2, incY = 1;

void printHello(int nextX, int nextY){
    if (nextX >= MIN_X + 1 && nextX <= MAX_X - 1 && nextY >= MIN_Y + 1 && nextY <= MAX_Y - 2) {
        
        screenSetColor(CYAN, DARKGRAY);
        screenGotoxy(x, y);
        printf(" ");
        x = nextX;
        y = nextY;
        screenGotoxy(x, y);
        printf("■");
        
        //coordenadas
        printf("Posição atual: x = %d, y = %d\n", x, y);
    }
}

int main() 
{
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
