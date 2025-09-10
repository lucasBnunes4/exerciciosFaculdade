#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int tno;

typedef struct tnoe {
    int chave;
    struct tnoe *esq;
    struct tnoe *dir;
} tnoe;

//funções básicas árvore
tnoe* cria_no(tno chave);
void cria_vazia(tnoe **arv);
int arvore_vazia(tnoe *arv);
int inserir(tnoe **arv, int valor);

//funções do percurso da arvore
void percorrer(tnoe *arv);

//funções utilitárias
int altura (tnoe * raiz);

#endif