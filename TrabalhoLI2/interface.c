#include "interface.h"
#include "dados.h"
#include <stdio.h>
#include <string.h>
#include "logica.h"
#include <stdlib.h>

#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    for (int l = 0; l < 8; l++) {
        printf ("%i ",8-l);
        for (int c = 0; c < 8; c++) {
            printf((obter_casa(e, c, l) == VAZIO) ? "." : (obter_casa(e, c, l) == BRANCA) ? "*" : (obter_casa(e, c, l) == UM) ? "1" : (obter_casa(e, c, l) == DOIS) ? "2" : "#" );
        }
        putchar('\n');
    }
    printf ("  abcdefgh\n");
}

void prompt (ESTADO *e){
    printf ("# %i PL%i (%i)> ", obter_numero_comandos(e), obter_jogador_atual(e), obter_numero_de_jogadas(e));
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char *token;
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    printf("Jogador: %s\n",linha);
    token = strtok(linha," ");
    if (strcmp(token, "Q\n") == 0) {
        printf("A sair do programa.\n");
        exit(0);
    }
    else if (strcmp(token, "gr") == 0) {
        // Ler nome do ficheiro
        printf("Xico: ");
        token = strtok(NULL, " \n");
        if (token != NULL) {
            printf("Gravar o jogo no seguinte ficheiro: %s\n", token);
            FILE * ficheiro;
            ficheiro = fopen(token,"wb");
            fwrite(e,sizeof(ESTADO),1,ficheiro);
            fclose(ficheiro);
            prompt(e);
        }
    }
    else if (strcmp(token, "ler") == 0) {
        // Ler nome do ficheiro
        printf("Xico1: ");
        token = strtok(NULL, " \n");
        if (token != NULL) {
            printf("Ler o jogo no seguinte ficheiro: %s\n", token);
            FILE * ficheiro;
            ficheiro = fopen(token,"rb");
            fread(e,sizeof(ESTADO),1,ficheiro);
            fclose(ficheiro);
            mostrar_tabuleiro(e);
            prompt(e);
        }
    }
    else {
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', 7 - (*lin - '1')};
            if (valida_jogada(e, coord)) {
                jogar(e, coord);
                putchar('\n');
                mostrar_tabuleiro(e);
                prompt(e);
            } else jogada_invalida();
        } else jogada_invalida();
    }
    return 1;
}

void congratula_jogador (ESTADO *e){
    printf ("Parabéns jogador %i! Ganhaste!", verifica_vencedor(e));
}

void jogada_invalida(){
    printf("Jogada inválida, tenta novamente> ");
}