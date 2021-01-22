#ifndef TAD_NUM_COMPLEXOS_H
#define TAD_NUM_COMPLEXOS_H

struct complx
{
 double really;
 double imgry;
};

typedef struct complx COMPLX;

void setComplx(COMPLX *pnum, double really, double imagin);

void imprime(COMPLX *num);

COMPLX soma(COMPLX* num1, COMPLX* num2);

COMPLX multiplica(COMPLX* num1, COMPLX* num2);

COMPLX inverte(COMPLX* pnum);



#endif
