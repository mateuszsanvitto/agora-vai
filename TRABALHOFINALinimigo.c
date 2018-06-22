#include <stdio.h>
#include "inimigo.h"
#include <time.h>
#include "mapa.h"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

//funcao que muda coordenadas dos inimigos
void mgotoxy(int x, int y) {

    COORD p={x-1, y-1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

}

// Inicializa os atributos do inimigo indicado com os valores desejados.
void inicializa(INIMIGO *i, MAPA *mapa) {
    int n;

    srand(time(NULL));

    i->quantidade = mapa->coord_inimigos.quantidade;

    for(n = 0;n < mapa->coord_inimigos.quantidade; n++) {

        i[n].x = mapa->coord_inimigos.x[n];
        i[n].y = mapa->coord_inimigos.y[n];
        i[n].status = rand() % 4;
        if(i[n].status == 0) {
            i[n].contador = rand() % 50;
        }
        else {
            i[n].contador = 1 + (rand() % 4);
        }
    }

}
// Atualiza os atributos do inimigo, relativa a 1 ciclo do jogo.
void atualiza(INIMIGO* i, MAPA *mapa) {

    int n;
    char swapCoord;

    for(n = 0;n < i->quantidade; n++) {
        if(i[n].contador == 0) {
            i[n].status = rand() % 4;
            i[n].contador = 1 + (rand() % 4);
        }
        switch(i[n].status) {
            case 0:
                i[n].contador--;
                break;
            case 1:


                if(mapa->matriz_mapa[i[n].y][i[n].x--] == '#') {
                    i[n].contador--;
                }
                else {
                    mgotoxy(i[n].x--, i[n].y);
                    printf("@");
                    mgotoxy(i[n].x, i[n].y);
                    printf("%c", 32);
                    i[n].contador--;
                }

                break;
            case 2:

                if(mapa->matriz_mapa[i[n].y][i[n].x++] == '#') {
                    i[n].contador--;
                }
                else {
                    mgotoxy(i[n].x++, i[n].y);
                    printf("@");
                    mgotoxy(i[n].x, i[n].y);
                    printf("%c", 32);
                    i[n].contador--;
                }

                break;
            case 3:

                if(mapa->matriz_mapa[i[n].y--][i[n].x] == '#') {
                    i[n].contador--;
                }
                else {
                    mgotoxy(i[n].x, i[n].y--);
                    printf("@");
                    mgotoxy(i[n].x, i[n].y);
                    printf("%c", 32);
                    i[n].contador--;
                }
                break;
            case 4:

                if(mapa->matriz_mapa[i[n].y++][i[n].x] == '#') {
                    i[n].contador--;
                }
                else {
                    mgotoxy(i[n].x, i[n].y++);
                    printf("@");
                    mgotoxy(i[n].x, i[n].y);
                    printf("%c", 32);
                    i[n].contador--;
                }
                break;
            default:
                break;
        }
    }
    mgotoxy(0, 35);
}
// Imprime os atributos do inimigo na tela.
void print_inimigo(INIMIGO *i) {

    int n;

    for(n = 0;n < i->quantidade; n++) {

        printf("\nInimigo %d", n+1);
        printf("\nx = %d, y = %d", i[n].x, i[n].y);

        printf("\nStatus: ");
        switch(i[n].status) {
            case 0:
                printf("dormindo");
                break;
            case 1:
                printf("andando para a esquerda");
                break;
            case 2:
                printf("andando para a direita");
                break;
            case 3:
                printf("andando para cima");
                break;
            case 4:
                printf("andando para baixo");
                break;
            default:
                break;
        }
        printf("\nContador: %d\n", i[n].contador);
    }
}
