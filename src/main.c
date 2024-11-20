#include <string.h>
#include <stdlib.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "fases.h"
#include "balls.h"
#include "fase2.h"
#include "score.h"

int x = 3, y = 8;
int incX = 1, incY = 1;
int cont_mortes = 0;
const char *nome_arquivo = "top_score.txt";

void printHello(int nextX, int nextY, int minX, int maxX, char **matriz){
    if (matriz[nextY][nextX] != '#' && nextX > minX && nextX < maxX) {
        
        screenSetColor(RED, DARKGRAY);
        screenGotoxy(x, y);
        printf(" ");
        x = nextX;
        y = nextY;
        screenGotoxy(x, y);
        printf("■");

    }
}

void resetar(){

    screenGotoxy(x,y);
    printf(" ");
    
    x = 3;
    y = 8;

    for(int i = 0; i < numBolasT; i++){
        screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
        printf(" ");
        bolasTopo[i].bolaY = 1;
    }
    
    for(int i = 0; i < numBolasB; i++){
        screenGotoxy(bolasBaixo[i].bolaX, bolasBaixo[i].bolaY);
        printf(" ");
        bolasBaixo[i].bolaY = 14;
    }

    screenGotoxy(x,y);
    printf("■");
    printBolasT();
    printBolasB();
    cont_mortes++;
    mortes(cont_mortes);
}

int colisao(){
    for(int i = 0; i < numBolasT; i++){
        if(bolasTopo[i].bolaX == x && bolasTopo[i].bolaY == y){
            return 1;
        }
    }
    
    for(int i = 0; i < numBolasB; i++){
        if(bolasBaixo[i].bolaX == x && bolasBaixo[i].bolaY == y){
            return 1;
        }
    }

    return 0;

}

int main() {
    int nextX, nextY;
    static int ch = 0;
    static long timer = 0;

    struct jogadores jogador[999];
    int count = 0;


    printFase1();
    mortes(cont_mortes);
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


    while(ch != 10){
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
            if(colisao()){
                resetar();
                screenUpdate();
                continue;
            }
            if (nextX == 79 && (nextY >= 6 && nextY <= 9)) {
                screenGotoxy(x, y);
                fim = 1;

            }
            
            screenUpdate();
        }

        if(timerTimeOver() == 1){
            if(colisao()){
                resetar();
                screenUpdate();
            }
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
