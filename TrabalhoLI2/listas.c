#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

LISTA criar_lista(){
    LISTA L;
    L = malloc(sizeof(struct nodo));
    L->proximo = NULL;
    return L;
}

LISTA insere_cabeca(LISTA L, void *v){
    LISTA n = criar_lista();
    n->valor = v;
    n->proximo = L;
    return n;
}

COORDENADA *devolve_cabeca(LISTA L){
    COORDENADA *cabeca;
    if (L == NULL) cabeca = NULL;
    else cabeca = L->valor;
    return cabeca;
}

LISTA proximo(LISTA L){
    LISTA p;
    if (L == NULL) p = NULL;
    else p  = L->proximo;
    return p;
}

LISTA remove_cabeca(LISTA L){
    LISTA n;
    n = L;
    L = proximo(L);
    free (n);
    return L;
}

int lista_esta_vazia(LISTA L){
    int r = 0;
    if (L == NULL) r=1;
    return r;
}