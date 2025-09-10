#include "arvore.h"

int main (void) {
    tnoe *arvore;


    cria_vazia(&arvore);

    inserir(&arvore, 50);
    inserir(&arvore, 10);
    inserir(&arvore, 90);
    inserir(&arvore, 30);
    inserir(&arvore, 78);
    inserir(&arvore, 99);
    inserir(&arvore, 65);
    inserir(&arvore, 13);
    inserir(&arvore, 88);
    inserir(&arvore, 20);


    printf("Arvore\n");
    percorrer(arvore);

    printf("\nAltura: %d\n", altura(arvore));

    return 0;
}