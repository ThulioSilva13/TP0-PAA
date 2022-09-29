#ifndef TP0_PAA_FIGURAS_H
#define TP0_PAA_FIGURAS_H
#include <stddef.h>
typedef struct quadro
{
    int linha;
    int coluna;
    char **matriz;
}Quadro;


void CriaAsterisco(Quadro *quadro , int quantidade);
void CriaMais(Quadro *quadro, int quantidade);
void CriaXis(Quadro *quadro, int quantidade);
void CriaPeixe(Quadro *quadro, int quantidade);
void CriaFiguraAleatoria(Quadro *quadro, int quantidade);
void ImprimeQuadro(Quadro *quadro);
void InicializaQuadroLimpo(Quadro *quadro);
void ImprimeMenu();
int EscolhaFigura(Quadro *quadro, int escolha);
#endif //TP0_PAA_FIGURAS_H