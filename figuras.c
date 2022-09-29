#include "figuras.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
void CriaAsterisco(Quadro *quadro, int quantidade)
{

    int eixoX, eixoY, controle = 0;
    while(controle < quantidade)
    {
        eixoX = rand() % quadro->linha;
        eixoY = rand() % quadro->coluna;
        if(quadro->matriz[eixoX][eixoY] == ' ' && eixoX < 20 && eixoY < 80)
        {
            quadro->matriz[eixoX][eixoY] = '*';
            controle++;
        }
    }
}

void CriaMais(Quadro *quadro, int quantidade)
{
    int eixoX, eixoY, controle = 0;
    while(controle < quantidade)
    {
        eixoX = rand() % quadro->linha;
        eixoY = rand() % quadro->coluna;
        if(quadro->matriz[eixoX][eixoY] == ' ' && quadro->matriz[eixoX+1][eixoY] == ' ' && quadro->matriz[eixoX-1][eixoY] == ' '
        && quadro->matriz[eixoX][eixoY+1] == ' ' && quadro->matriz[eixoX][eixoY-1] == ' ' && eixoX < 20 && eixoY < 80)
        {
            quadro->matriz[eixoX][eixoY] = '*';
            quadro->matriz[eixoX+1][eixoY] = '*';
            quadro->matriz[eixoX-1][eixoY] = '*';
            quadro->matriz[eixoX][eixoY+1] = '*';
            quadro->matriz[eixoX][eixoY-1] = '*';
            controle ++;
        }
    }
}

void CriaXis(Quadro *quadro, int quantidade)
{
    int eixoX, eixoY, controle = 0;
    while(controle < quantidade)
    {
        eixoX = rand() % quadro->linha;
        eixoY = rand() % quadro->coluna;
        if(quadro->matriz[eixoX][eixoY] == ' ' && quadro->matriz[eixoX+1][eixoY+1] == ' ' && quadro->matriz[eixoX-1][eixoY+1] == ' '
        && quadro->matriz[eixoX+1][eixoY-1] == ' ' && quadro->matriz[eixoX-1][eixoY-1] == ' ' && eixoX < 20 && eixoY < 80)
        {
            quadro->matriz[eixoX][eixoY] = '*';
            quadro->matriz[eixoX+1][eixoY+1] = '*';
            quadro->matriz[eixoX-1][eixoY+1] = '*';
            quadro->matriz[eixoX+1][eixoY-1] = '*';
            quadro->matriz[eixoX-1][eixoY-1] = '*';
            controle ++;
        }
    }

}

void CriaPeixe(Quadro *quadro, int quantidade)
{
    int eixoX, eixoY, controle = 0;
    while(controle < quantidade)
    {
        eixoX = rand() % quadro->linha;
        eixoY = rand() % quadro->coluna;
        if(quadro->matriz[eixoX][eixoY] == ' ' && quadro->matriz[eixoX+1][eixoY] == ' ' && quadro->matriz[eixoX-1][eixoY] == ' '
           && quadro->matriz[eixoX][eixoY+1] == ' ' && quadro->matriz[eixoX][eixoY-1] == ' ' && eixoX < 20 && eixoY < 80)
        {
            quadro->matriz[eixoX][eixoY] = '>';
            quadro->matriz[eixoX][eixoY-1] = '<';
            quadro->matriz[eixoX][eixoY+1] = '<';
            quadro->matriz[eixoX-1][eixoY] = ',';
            quadro->matriz[eixoX+1][eixoY] = '`';
            controle ++;
        }
    }
}

void CriaFiguraAleatoria(Quadro *quadro, int quantidade)
{
    for(int i = 0; i < quantidade; i++)
    {
        //rand() % 3 sem peixe e rand() % 4 com peixe
        int figura = 1 + (rand() % 3);
        if(figura == 1)
        {
            CriaAsterisco(quadro, 1);
        }
        else if(figura == 2)
        {
            CriaMais(quadro, 1);
        }
        else if(figura == 3)
        {
            CriaXis(quadro, 1);
        }
        // else if(figura == 4)
        // {
        //     CriaPeixe(quadro, 1);
        // }
    }

}

void ImprimeQuadro(Quadro *quadro)
{
    for(int i = 0; i < quadro->linha; i++)
    {
        printf("%s\n", quadro->matriz[i]);
    }
}

void InicializaQuadroLimpo(Quadro *quadro)
{
    quadro->matriz= (char **) malloc(sizeof(char *) * quadro->linha);
    for(int i = 0; i < quadro->linha; i++)
    {
        quadro->matriz[i] = (char *) malloc(sizeof(char) * quadro->coluna+1);
    }
    for(int i = 0; i < quadro->linha; i++)
    {
        for(int j = 0; j < quadro->coluna; j++)
        {
            if(i == 0 || i == 19)
            {
                quadro->matriz[i][j] = '-';
            }
            else if(j == 0 || j == 79)
            {
                quadro->matriz[i][j] = '|';
            }
            else
            {
                quadro->matriz[i][j] = ' ';
            }
        }
    }
}
void ImprimeMenu()
{
    printf("Digite qual figura: \n");
    printf("[1] para asterisco \n");
    printf("[2] para mais \n");
    printf("[3] para xis \n");
    printf("[4] para figuras aleatorias \n");
    printf("[5] para peixe\n");
    printf("[0] para sair\n");

    printf("Digite aqui: ");
}
int EscolhaFigura(Quadro *quadro, int escolha)
{
    if(escolha == 0)
    {
        return 0;
    }
    int quantidade = 0;
    printf("Digite a quantidade de figuras: ");
    scanf("%d", &quantidade);

    switch (escolha)
    {
        case 1:
            CriaAsterisco(quadro, quantidade);
            break;
        case 2:
            CriaMais(quadro, quantidade);
            break;
        case 3:
            CriaXis(quadro, quantidade);
            break;
        case 4:
            CriaFiguraAleatoria(quadro, quantidade);
            break;
        default:
            CriaPeixe(quadro, quantidade);
    }
    ImprimeQuadro(quadro);
    InicializaQuadroLimpo(quadro);
    return 1;
}
