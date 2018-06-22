#ifndef _INIMIGO_H_
#define _INIMIGO_H_
#define MAX_INIMIGOS 10
#include "mapa.h"
typedef struct inimigo_st {

    int x;
    int y;
    int status;
    int contador;
    int quantidade;

} INIMIGO;

void mgotoxy(int x, int y);

// Inicializa os atributos do inimigo indicado com os valores desejados.
void inicializa(INIMIGO *i, MAPA *mapa);
// Atualiza os atributos do inimigo, relativa a 1 ciclo do jogo.
void atualiza(INIMIGO *i, MAPA *mapa);
// Imprime os atributos do inimigo na tela.
void print_inimigo(INIMIGO *i);

#endif
