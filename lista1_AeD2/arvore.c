#include "arvore.h"

tnoe * cria_no (tno chave) {
    tnoe *no;

    no = (tnoe*) malloc(sizeof(tnoe));
    if (no == NULL) exit (1);

    no -> chave = chave;
    no -> dir = NULL;
    no -> esq = NULL;
    return no;
}

void cria_vazia (tnoe **arv) {
    *arv = NULL;
    return;
}

int arvore_vazia (tnoe *arv) {
    return (arv == NULL);
}

int inserir (tnoe **arv, int valor) {
    tnoe *aux1, *aux2;

    aux1 = cria_no(valor);

    if (arvore_vazia(*arv))
    {
        *arv = aux1;
        return 1;
    } else {
        aux2 = *arv;
        if (valor == aux2 -> chave) return -1;

        if (valor > aux2->chave) {
            if (aux2->dir == NULL) { 
            aux2->dir = aux1;
            }else {
                aux2 = aux2->dir;
                inserir(&(aux2->dir), valor); 
            }
        } else
        {
            if (aux2->esq == NULL)
            {
                aux2->esq = aux1;
            } else
            {
                aux2 = aux2->esq;
                inserir (&(aux2->esq), valor);
            }
            
            
        }
        
    }
    
    return 1;
    
}

void percorrer (tnoe *arv) {
    if (arv == NULL) {
        printf("arvore vazia");
        return;
    }
        
    printf("\nChave = %d", arv->chave);

    if (arv->esq != NULL) percorrer (arv->esq);
    if (arv->dir != NULL) percorrer (arv->dir);
    
}

int altura (tnoe * raiz) {
    if (raiz==NULL)
    return 0;
    else {
        int he = altura (raiz->esq);
        int hd = altura (raiz->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
}

int remover (tnoe * raiz, tnoe ** nodo, tno chave) {
    tnoe *aux, *ant, *fe, *fe_ant;
    aux = *nodo;
    
    if (aux == NULL)
        return 0; // arvore vazia
    
    else if (chave < aux->chave)
        remover(raiz, &(aux->esq), chave);

    else if (chave > aux->chave)
        remover(raiz, &(aux->dir), chave);
    
    else if (chave == aux->chave)
    {
        busca_ant(raiz, &ant, chave);

        if (ant == NULL)
        {
            if ((aux->esq == NULL) && (aux->dir == NULL)) *nodo = NULL;
            else if (aux->dir != NULL)
            {
                fe = busca_folha_esq(aux->dir);
                
                if (aux->dir != fe)
                {
                    busca_ant(raiz, &fe_ant, fe->chave);
                    fe_ant->esq = fe->dir;
                    fe->dir = aux->dir;
                }

                fe->esq = aux->esq;
                *nodo = fe;
                
            } else if (aux->esq != NULL)
            {
                *nodo = aux->esq;
            }
            
            
        }
        
    }
    
}

int busca_ant (tnoe *raiz, tnoe **pant, tno chave) {

}

tnoe * busca_folha_esq(tnoe *sub) {

}

tnoe * busca_folha_dir(tnoe *sub) {
    
}