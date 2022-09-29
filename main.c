#include <stdio.h>
#include "figuras.h"
Quadro quadro;
int main() { 
    quadro.linha = 20;
    quadro.coluna = 80;
    InicializaQuadroLimpo(&quadro);
    int escolha = 0;
    do {
        ImprimeMenu();

        scanf("%d", &escolha);

     }while(EscolhaFigura(&quadro, escolha));
    return 0;
}