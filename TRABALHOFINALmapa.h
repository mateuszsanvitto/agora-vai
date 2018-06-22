#ifndef MAPA_H
#define MAPA_H
#define MAX_LINHAS 25
#define MAX_COLUNAS 81
#define MAX_STR 30
#define MAX_INIMIGOS 10

typedef struct chave_st {
    int x;
    int y;
} CHAVE;

typedef struct saida_st {
    int x;
    int y;
} SAIDA;

typedef struct coord_inimigos_st {

    int x[MAX_INIMIGOS];
    int y[MAX_INIMIGOS];
    int quantidade;

} COORD_INIMIGOS;

typedef struct mapa_st {

    int largura;
    int altura;
    char matriz_mapa[MAX_LINHAS][MAX_COLUNAS];
    CHAVE chave;
    SAIDA saida;
    COORD_INIMIGOS coord_inimigos;

} MAPA;

int carregaMapa(char arquivo[MAX_STR + 1], MAPA *mapa);

void printMapa(MAPA *mapa);

#endif // MAPA_H
