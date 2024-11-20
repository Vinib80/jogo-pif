#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>

struct jogadores {
    char apelido[5];
    int mortes;
};

extern struct jogadores *ptr;

void ordem(struct jogadores jogador[], int count);
void escrever(struct jogadores jogador[], int count, const char *nome_arquivo);
void exibir(const char *nome_arquivo);
void telaNome(char *nomeJogador);
void telaTop3();

#endif