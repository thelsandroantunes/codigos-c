/*  Autor: Thelsandro Costa Antunes
*   Data: 22/01/2021
*   EXERCÍCIO TAD NÚMEROS COMPLEXOS - CODE::BLOCKS
*   Questao: Escreva uma especificação de tipos abstratos de dados (TAD) para os números
*            complexos, a + bi, onde abs(a + bi) é sqrt(a^2 + b^2), (a + bi) + (c + di)
*            é (a + c) + (b + d)i, (a + b) * (c + di) é (a * c – b * d) + (a * d + b * c)i e –(a + bi) é (-a) + (-b)i.
*            Então, implemente (cm C/C++ ou Java) números complexos, conforme especificado
*            acima, usando estruturas com partes reais e complexas. Escreva rotinas para somar,
*            multiplicar e negar (inverter) tais números.
*
*/


#include<stdio.h>
#include <locale.h>
#include "tad_num_complexos.h"


int main()
{
    setlocale (LC_ALL, "portuguese");

    COMPLX comp1;
    COMPLX comp2;
    COMPLX res;
    double r1,r2;

    printf("Digite Re(Z1): ");
    scanf("%lf",&r1);
    printf ("Digite Im(Z1): ");
    scanf("%lf",&r2);
    setComplx(&comp1, r1, r2);
    printf("\n");
    printf ("Digite Re(Z2): ");
    scanf("%lf",&r1);
    printf ("Digite Im(Z2): ");
    scanf("%lf",&r2);
    setComplx(&comp2, r1, r2);

    printf("\n");

    printf ("Z1 = a + bi \n");
    printf ("Z1 : ");
    imprime(&comp1);
    printf ("Z2 = c + di \n");
    printf ("Z2 : ");
    imprime(&comp2);

    printf("\n");

    res = soma(&comp1,&comp2);
    printf ("Z1 + Z2 = (a+c) + (b+d)i\n");
    printf ("Z1 + Z2 : ");
    imprime(&res);

    printf("\n");

    res = multiplica(&comp1,&comp2);
    printf ("Z1 * Z2 = (ac-bd)*(ad+cb)i\n");
    printf ("Z1 * Z2 : ");
    imprime(&res);

    printf("\n");

    res = inverte(&comp1);
    printf ("Inversão de Z1: ");
    imprime(&res);

    system("pause");
    return 0;
}
