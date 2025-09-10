#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void merge(int x[], int inic, int fim);
void intercala(int x[], int inic, int meio, int fim);

int main()
{
    int x[TAM], i;

    printf("Digite %d numeros de uma vez e separados por espaços: ", TAM);

    for (i = 0; i < TAM; i++)
    {
    
        scanf("%d", &x[i]);
        
    }

    while (getchar() != '\n');

    merge (x, 0, TAM - 1);

    printf("Vetor ordenado:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("x[%d] = %d\n", i, x[i]);
    }
    
    return 0;
}


void merge (int x[], int inic, int fim) {
    int meio;

    if (inic < fim)
    {
        meio = (inic + fim) / 2;
        merge(x, inic, meio);
        merge(x, meio + 1, fim);
        intercala(x, inic, meio, fim);
    }
}


void intercala (int x[], int inic, int meio, int fim) {
    int pos, c1, c2, i;
    int aux[TAM];
    
    c1 = inic;
    c2 = meio + 1;
    pos = inic;
    
    while (c1<=meio && c2<=fim) {
        if (x[c1] <= x[c2]) {
            aux[pos] = x[c1];
            c1++;
    } else {
        aux[pos] = x[c2];
        c2++;
    }
    pos++;
    }

    //Se ainda existirem numeros no 1o vetor
    for (i=c1; i<=meio; i++) {
        aux[pos] = x[i];
        pos++;
    }

    //Se ainda existirem numeros no 2o vetor
    for (i=c2; i<=fim; i++) {
        aux[pos] = x[i];
        pos++;
    }

    //retorna os valores de aux para o vetor x
    for (i=inic; i<=fim; i++) {
        x[i] = aux[i];
    }
}
    
