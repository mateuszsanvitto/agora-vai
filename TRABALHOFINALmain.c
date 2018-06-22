#include <stdio.h>
#include <string.h>
#include "mapa.h"
#include "inimigo.h"

int main() {

    MAPA mapa;
    char arquivo_txt[MAX_STR + 1];
    int status_mapa;
    INIMIGO inimigos[MAX_INIMIGOS];
    int i = 0;

    strcpy(arquivo_txt, "mapa0.txt");

    status_mapa = carregaMapa(arquivo_txt, &mapa);

    if(status_mapa) {
        printMapa(&mapa);
    }

    inicializa(&inimigos, &mapa);

    system("pause");

    while(i < 20) {
        i++;
        atualiza(&inimigos, &mapa);
        //system("cls");
        //print_inimigo(&inimigos);
        system("pause");
    }

    return 0;
}
