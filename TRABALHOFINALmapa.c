#include <stdio.h>
#include "mapa.h"
#include "inimigo.h"

int carregaMapa(char arquivo[MAX_STR + 1], MAPA *mapa) {

    FILE *arq;
    char ch;
    int linha=0, coluna=0, i;
    int ret = 1;
    int n_inimigos = 0;

    if( !(arq = fopen(arquivo, "r")) ) {
        printf("\nErro ao abrir o arquivo do mapa.");
    }
    else {

        mapa->coord_inimigos.quantidade = 0;

        while( (ch = fgetc(arq)) != EOF && ret != 0 ) {

            if( linha + 1 > MAX_LINHAS || coluna + 1 > MAX_COLUNAS) {
                ret = 0;
                printf("\nLimite ultrapassado.");
            }
            else {

                if(ch == '@') {
                    mapa->coord_inimigos.x[n_inimigos] = coluna;
                    mapa->coord_inimigos.y[n_inimigos] = linha;
                    mapa->coord_inimigos.quantidade++;
                    n_inimigos++;
                }

                if(ch == 'K') {
                    mapa->chave.x = coluna;
                    mapa->chave.y = linha;
                }
                else if(ch == 'x') {
                    mapa->saida.x = coluna;
                    mapa->saida.y = linha;
                }

                mapa->matriz_mapa[linha][coluna] = ch;

                coluna++;

                if(ch == '\n') {
                    coluna = 0;
                    linha++;
                }

            }
        }

        //printf("\naltura: %d\nlargura: %d\n", linha+1, coluna);

        mapa->altura = linha + 1;
        mapa->largura = coluna;


        fclose(arq);
    }
    return ret;
}

void printMapa(MAPA *mapa) {

    int linha, coluna;
    int i;

    for(linha = 0;linha < mapa->altura; linha++) {
        for(coluna = 0;coluna < mapa->largura; coluna++) {

            printf("%c", mapa->matriz_mapa[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nLargura: %d", mapa->largura);
    printf("\nAltura: %d", mapa->altura);
    printf("\n\nCoordenadas da chave: %d, %d", mapa->chave.x, mapa->chave.y);
    printf("\nCoordenadas da saida: %d, %d", mapa->saida.x, mapa->saida.y);
    printf("\nQuantidade de inimigos: %d", mapa->coord_inimigos.quantidade);
    printf("\n");

    //for(i = 0;i < mapa->coord_inimigos.quantidade; i++) {
    //    printf("\nCoordenadas do inimigo %d: x = %d, y = %d", i+1, mapa->coord_inimigos.x[i], mapa->coord_inimigos.y[i]);
    //}

}
