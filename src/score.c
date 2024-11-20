#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "score.h"

struct jogadores *ptr = NULL;

void ordem(struct jogadores jogador[], char nome[], int count) {
    strcpy(jogador[count].apelido, nome);
    jogador[count].mortes = cont_mortes;  // Aqui você usa a variável cont_mortes diretamente

    // Ordenação
    for (int i = 0; i < count - 1; i++) {
        int menor_indice = i;
        for (int j = i + 1; j < count; j++) {
            if (jogador[j].mortes < jogador[menor_indice].mortes) {
                menor_indice = j;
            }
        }
        if (menor_indice != i) {
            struct jogadores temp = jogador[i];
            jogador[i] = jogador[menor_indice];
            jogador[menor_indice] = temp;
        }
    }
}



void escrever(struct jogadores jogador[], int count, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for (int i = 0; i < 3 && i < count; i++) {
        fprintf(arquivo, "nome: %s, mortes: %d\n", jogador[i].apelido, jogador[i].mortes);
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

/*void telaNome(char *nomeJogador) {
    screenClear();
    screenSetColor(WHITE, BLACK);
    screenGotoxy(10, 5);
    printf("Digite seu nome: ");
    screenGotoxy(10 + strlen(nomeJogador), 5);
    printf("%s", nomeJogador);
}*/

void telaTop3() {
    screenClear();
    screenSetColor(YELLOW, BLACK);
    screenGotoxy(5, 5);
    printf("   TOP 3 JOGADORES:\n");

    exibir("top_score.txt");  

    screenGotoxy(10, 15);
}