#include "screen.h"
#include "keyboard.h"
#include "timer.h"

void inicioFase2() {
    //codigo...
    screenClear();
    screenSetColor(GREEN, DARKGRAY);
    screenGotoxy(5, 5);
    printf("Parabéns!\n");
}
