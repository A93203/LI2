#include "dados.h"
#include <stdlib.h>

ESTADO *inicializar_estado() {
    ESTADO *novo = (ESTADO *) malloc(sizeof(ESTADO));
    int i, j;
    novo->jogador_atual = 1;
    novo->num_jogadas = 0;
    novo->ultima_jogada.coluna = 4;
    novo->ultima_jogada.linha = 4;
    novo->num_comandos = 1;
    for (i=0; i<8; i++){
        for (j=0; j<8; j++){
            novo->tab[i][j] = VAZIO;
        }
    }
    novo->tab[4][4] = BRANCA;
    novo->tab[0][0] = UM;
    novo->tab[7][7] = DOIS;
    novo->total_jogadas_pos = 0;
    novo->numero_jogador_pos = 1;
    return novo;
}

CASA obter_casa (ESTADO *e, int c, int l){
    CASA casa;
    if (c>=0 && c<=8 && l>=0 && l<=8) {
        casa = e->tab[c][l];
        return casa;
    }
    else return ERRO;
}

int obter_numero_de_jogadas(ESTADO *e){
    int n;
    n = e->num_jogadas;
    return n;
}

void alterar_numero_de_jogadas(ESTADO *e, int n){
    e->num_jogadas = n;
}

int obter_jogador_atual(ESTADO *e){
    int j;
    j = e->jogador_atual;
    return j;
}

void alterar_jogador_atual(ESTADO *e, int n){
    e->jogador_atual = n;
}

int obter_numero_comandos(ESTADO *e){
    int n;
    n = e->num_comandos;
    return n;
}

void alterar_numero_comandos(ESTADO *e, int n){
    e->num_comandos = n;
}

int obter_total_jogadas(ESTADO *e){
    int n;
    n = e->total_jogadas_pos;
    return n;
}

void alterar_total_jogadas(ESTADO *e, int n){
    e->total_jogadas_pos = n;
}

int obter_numj_pos(ESTADO *e){
    int n;
    n = e ->numero_jogador_pos;
    return n;
}

void alterar_numero_jogador_pos(ESTADO *e, int n){
    e->numero_jogador_pos = n;
}