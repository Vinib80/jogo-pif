#include "screen.h"
#include "keyboard.h"
#include "timer.h"

void inicioFase2() {
    // Limpa a tela e configura a cor
    screenClear();
    screenSetColor(GREEN, DARKGRAY);
    
    // Define a posição do cursor
    screenGotoxy(5, 5);

    // Imprime o texto com as quebras de linha e escapes necessários
    printf("\n      ██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗░█████╗░███╗░░██╗   ██╗██╗\n");
    printf("      ╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██╔══██╗████╗░██║   ██║██║\n");
    printf("      ░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║░░██║██╔██╗██║   ██║██║\n");
    printf("      ░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║░░██║██║╚████║   ╚═╝╚═╝\n");
    printf("      ░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░╚█████╔╝██║░╚███║   ██╗██╗\n");
    printf("      ░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚══╝   ╚═╝╚═╝\n");
}
