#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "balls.h"

struct bola *bolasTopo;
struct bola *bolasBaixo;

const int numBolasT = 7;
const int numBolasB = 6;

void posicaoBolasT(){
    
    bolasTopo = malloc(numBolasT * sizeof(struct bola));

    for(int i = 0; i < numBolasT; i++){
        bolasTopo[i].bolaX = 10 + (i * 10);
        bolasTopo[i].bolaY = fase1.minY + 1;
    }
}

void printBolasT(){
    for(int i = 0; i < numBolasT; i++){
        int nextY = bolasTopo[i].bolaY; 

        if(matriz1[nextY][bolasTopo[i].bolaX] != '#' && nextY >= fase1.minY && nextY < fase1.maxY){
            screenSetColor(BLUE, DARKGRAY);
            screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
            printf(" ");
            screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
            printf("●");
        }
    }
}

void posicaoBolasB(){

    bolasBaixo = malloc(numBolasB * sizeof(struct bola));

    for(int i = 0; i < numBolasB; i++){
        bolasBaixo[i].bolaX = 15 + (i * 10);
        bolasBaixo[i].bolaY = fase1.minY - 1.2;
    }
}

void printBolasB(){
    for(int i = 0; i < numBolasB; i++){
        int nextY = bolasBaixo[i].bolaY;

        if(nextY >= fase1.minY && nextY < fase1.maxY&& matriz1[nextY][bolasBaixo[i].bolaX] != '#'){
            screenSetColor(BLUE, DARKGRAY);
            screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
            printf(" ");
            screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
            printf("●");
        }
    }
}