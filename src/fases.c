#include <stdio.h>
#include "screen.h"
#include "fases.h"



void printFase1(){

    for(int i = MIN_Y; i < MAX_Y; i++){ //funcao para preencher a matriz
        for(int j = MIN_X; j < MAX_X; j++){
            if(i == 0){
                matriz1[i][j] = '#';
            } else if(i == MAX_Y-1){
                matriz1[i][j] = '#';
            } else if(j == 0){
                 matriz1[i][j] = '#';
            } else if(j == MAX_X-1){
                 matriz1[i][j] = '#';
            } else {
                 matriz1[i][j] = ' ';
            }
        }
    }
    matriz1[(MAX_Y/2) - 2][MAX_X-1] = ' ';
    matriz1[(MAX_Y/2) - 1][MAX_X-1] = ' ';
    matriz1[MAX_Y/2][MAX_X-1] = ' ';
    matriz1[(MAX_Y/2) + 1][MAX_X-1] = ' ';

    screenClear();


    for(int i = MIN_Y; i < MAX_Y; i++){
        for(int j = MIN_X; j < MAX_X; j++){
            printf("%c", matriz1[i][j]);
        }
        printf("\n");
    }
    screenHomeCursor();
    screenHideCursor();

}

