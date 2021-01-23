/*  Autor: Thelsandro Costa Antunes
*   Data: 23/01/2021
*   EXERCÍCIO TAD PONTO CARTESIANO - CODE::BLOCKS
*   Questao: Faça um programa que utiliza TAD para pontos cartesianos.
*
*/


#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include "tad_ponto.h"


int main()
{
    setlocale (LC_ALL, "portuguese");

    float d;
    Ponto *p,*q;

    float x1,x2;
    float y1,y2;

    printf("Digite o ponto A(x1,y1)\n");
    printf("x1: ");
    scanf("%f",&x1);
    printf("y1: ");
    scanf("%f",&y1);
    printf("\n");
    printf("Digite o ponto B(x2,y2)\n");
    printf("x2: ");
    scanf("%f",&x2);
    printf("y2: ");
    scanf("%f",&y2);

    p = pto_cria(x1,y1);
    q = pto_cria(x2,y2);

    d = pto_distancia(p,q);

    printf("Distância entre dois pontos: %f\n",d);
    pto_libera(p);
    pto_libera(q);


    system("pause");
    return 0;
}
