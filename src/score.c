#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "score.h"



void ordem(struct jogadores jogadores[], char nome[], int count) {
    strcpy(jogadores[count].apelido, nome);
    jogadores[count].mortes = cont_mortes;  // Aqui você usa a variável cont_mortes diretamente

    // Ordenação
    for (int i = 0; i < count - 1; i++) {
        int menor_indice = i;
        for (int j = i + 1; j < count; j++) {
            if (jogadores[j].mortes < jogadores[menor_indice].mortes) {
                menor_indice = j;
            }
        }
        if (menor_indice != i) {
            struct jogadores temp = jogadores[i];
            jogadores[i] = jogadores[menor_indice];
            jogadores[menor_indice] = temp;
        }
    }
}



void escrever(struct jogadores jogadores[], int count, const char *nome_arquivo) {
    
    
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for (int i = 0; i < 3 && i < count; i++) {
        fprintf(arquivo, "nome: %s | mortes: %d\n", jogadores[i].apelido, jogadores[i].mortes);
    }

    fclose(arquivo);
}


void exibir(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[100];
    printf("\n---- TOP 3: ----\n\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}


void telaTop3() {
    screenClear();
    screenSetColor(YELLOW, BLACK);
    screenGotoxy(5, 5);
    printf("   TOP 3 JOGADOResES:\n");

    exibir("top_score.txt");  

    screenGotoxy(10, 15);
}