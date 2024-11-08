#include <stdio.h>

#define MIN_Y  0
#define MAX_Y  24
#define MIN_X  0
#define MAX_X  100


void printFase1(){
    char matriz1[MAX_Y][MAX_X];

    for(int i = MIN_Y; i < MAX_Y; i++){
        for(int j = MIN_X; j < MAX_X; j++){
            if(i == 0){
                matriz1[i][j] = '#';
                printf("%c", matriz1[i][j]);
            } else if(i == 23){
                matriz1[i][j] = '#';
                printf("%c", matriz1[i][j]);
            } else if(j == 0){
                 matriz1[i][j] = '#';
                printf("%c", matriz1[i][j]);
            } else if(j == 99){
                 matriz1[i][j] = '#';
                printf("%c", matriz1[i][j]);
            } else {
                 matriz1[i][j] = ' ';
                printf("%c", matriz1[i][j]);
            }
        }
        printf("\n");
    }

}

int main(){
    printFase1();
    
    return 0;
}