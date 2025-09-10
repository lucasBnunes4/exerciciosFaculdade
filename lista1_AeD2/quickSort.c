#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void quick(int x[], int inic, int fim);
int particao(int x[], int inic, int fim);
void troca(int x[], int i, int j);

int main()
{
    int x[TAM], i;

    printf("Digite %d numeros de uma vez e separados por espaços: ", TAM);

    for (i = 0; i < TAM; i++)
    {
    
        scanf("%d", &x[i]);
        
    }

    while (getchar() != '\n');

    quick (x, 0, TAM - 1);

    printf("Vetor ordenado:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("x[%d] = %d\n", i, x[i]);
    }
    
    return 0;
}

void troca (int x[], int i, int j) {
    int aux;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

void quick (int x[], int inic, int fim) {
    int meio;

    if (inic < fim)
    {
        meio = particao(x, inic, fim);
        quick(x, inic, meio);
        quick(x, meio+1, fim);
    }
}

int particao (int x[], int inic, int fim) {
    int pivo, i, j;
    pivo = x[(inic + fim) / 2];
    i = inic-1;
    j=fim+1;

    while (i<j)
    {
        do
        {
            j--;
        } while (x[j] > pivo);
        
        do
        {
            i++;
        } while (x[i] < pivo);
        
        if (i<j)
        {
            troca(x,i,j);
        }

        return j;
        
    }
    
}