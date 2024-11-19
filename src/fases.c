#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "fases.h"

TamanhoF fase1;
char **matriz1;

void printFase1(){

    fase1.minY = 0;
    fase1.maxY = 16;
    fase1.minX = 0;
    fase1.maxX = 80; //as dimensões da fase 1

    matriz1 = (char **)malloc(fase1.maxY*sizeof(char *));

    for(int i = 0; i < fase1.maxY; i++){
        matriz1[i] = (char *)malloc(fase1.maxX*sizeof(char));
    }

    for(int i = fase1.minY; i < fase1.maxY; i++){ //funcao para preencher a matriz
        for(int j = fase1.minX; j < fase1.maxX; j++){
            if(i == 0){
                matriz1[i][j] = '#';
            } else if(i == fase1.maxY-1){
                matriz1[i][j] = '#';
            } else if(j == 0){
                 matriz1[i][j] = '#';
            } else if(j == fase1.maxX-1){
                 matriz1[i][j] = '#';
            } else {
                 matriz1[i][j] = ' ';
            }
        }
    }
    matriz1[(fase1.maxY/2) - 2][fase1.maxX-1] = ' ';
    matriz1[(fase1.maxY/2) - 1][fase1.maxX-1] = ' ';
    matriz1[fase1.maxY/2][fase1.maxX-1] = ' ';
    matriz1[(fase1.maxY/2) + 1][fase1.maxX-1] = ' ';

    screenClear();


    for(int i = fase1.minY; i < fase1.maxY; i++){
        for(int j = fase1.minX; j < fase1.maxX; j++){
            printf("%c", matriz1[i][j]);
        }
        printf("\n");
    }


    screenHomeCursor();
    screenHideCursor();
    

}

void mortes(){
    screenGotoxy(0, 16);
    screenSetColor(RED, DARKGRAY);
    printf("Mortes: 0");
}