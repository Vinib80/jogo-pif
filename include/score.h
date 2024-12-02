#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>

struct jogadores {
    char apelido[50];
    int mortes;
};



extern int cont_mortes;

void ordem(struct jogadores jogadores[], char nome[], int count);
void escrever(struct jogadores jogadores[], int count, const char *nome_arquivo);
void exibir(const char *nome_arquivo);
void telaTop3();

#endif