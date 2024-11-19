#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "balls.h"
#include "fases.h"

struct bola *bolasTopo;
struct bola *bolasBaixo;

const int numBolasT = 7;
const int numBolasB = 6;

void posicaoBolasT(){
    
    bolasTopo =(struct bola *) malloc(numBolasT * sizeof(struct bola));

    for(int i = 0; i < numBolasT; i++){
        bolasTopo[i].bolaX = 10 + (i * 10);
        bolasTopo[i].bolaY = fase1.minY + 1;
        bolasTopo[i].bolaincY = 1;
    }
}

void printBolasT(){
    for(int i = 0; i < numBolasT; i++){

        screenSetColor(BLUE, DARKGRAY);
        screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
        printf(" ");
        bolasTopo[i].bolaY += bolasTopo[i].bolaincY;
        if(bolasTopo[i].bolaY == 15){
            bolasTopo[i].bolaY -= 1;
            bolasTopo[i].bolaincY = -1;
        } else if (bolasTopo[i].bolaY == 0){
            bolasTopo[i].bolaY += 1;
            bolasTopo[i].bolaincY = 1;
        }
        screenGotoxy(bolasTopo[i].bolaX, bolasTopo[i].bolaY);
        printf("●");
        
    }
}

void posicaoBolasB(){

    bolasBaixo = (struct bola *)malloc(numBolasB * sizeof(struct bola));

    for(int i = 0; i < numBolasB; i++){
        bolasBaixo[i].bolaX = 15 + (i * 10);
        bolasBaixo[i].bolaY = fase1.maxY - 2;
        bolasBaixo[i].bolaincY = -1;
    }
}

void printBolasB(){
    for(int i = 0; i < numBolasB; i++){

        
        screenSetColor(BLUE, DARKGRAY);
        screenGotoxy(bolasBaixo[i].bolaX, bolasBaixo[i].bolaY);
        printf(" ");
        bolasBaixo[i].bolaY += bolasBaixo[i].bolaincY;
        
        if(bolasBaixo[i].bolaY == 15){
            bolasBaixo[i].bolaY -= 1;
            bolasBaixo[i].bolaincY = -1;
        } else if (bolasBaixo[i].bolaY == 0){
            bolasBaixo[i].bolaY += 1;
            bolasBaixo[i].bolaincY = 1;
        }
        screenGotoxy(bolasBaixo[i].bolaX, bolasBaixo[i].bolaY);
        printf("●");
        
    }
}