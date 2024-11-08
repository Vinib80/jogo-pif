#include <stdio.h>

#define LINHAS  24
#define COLUNAS  100

void printFase1(){
    char matriz1[LINHAS][COLUNAS];
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            printf("#");
        }
        printf("\n");
    }
}

int main(){
    printFase1();
    
    return 0;
}