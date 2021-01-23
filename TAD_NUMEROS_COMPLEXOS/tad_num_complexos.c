#include<stdio.h>
#include "tad_num_complexos.h"

void setComplx(COMPLX *pnum, double really, double imagin)
{
    pnum->really = really;
    pnum->imgry = imagin;
}

void imprime(COMPLX *num)
{
    printf("(%.2lf) + (%.2lf)i\n", num->really, num->imgry);
}

COMPLX soma(COMPLX* num1, COMPLX* num2)
{
 COMPLX tempsoma;
 tempsoma.really = num1->really + num2->really;
 tempsoma.imgry = num1->imgry + num2->imgry;
 return tempsoma;
}

COMPLX multiplica(COMPLX* num1, COMPLX* num2)
{
 COMPLX tempmult;
 tempmult.really = num1->really * num2->really - num1->imgry * num2->imgry;
 tempmult.imgry = num1->really * num2->imgry + num1->imgry * num2->really;
 return tempmult;
}

COMPLX inverte(COMPLX* pnum)
{
 COMPLX temp;
 temp.really = (-1) * pnum->really;
 temp.imgry = (-1) * pnum->imgry;
 return temp;
}


