/*  Autor: Thelsandro Costa Antunes
*   Data: 19/01/2021
*   EXERC�CIO SOMA DE PARES
*   Questao: Fa�a um programa que calcule e mostre a soma dos N primeiros n�meros pares.
*
*/

#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

int main(){

    setlocale (LC_ALL, "portuguese");

    int i=0,soma=0, N;

    printf("Digite um n�mero: \n");
    scanf("%d",&N);

    for(i=1;i<N;i++)
    {
       if(i%2==0)
        soma=(soma+i);
    }

    printf("A soma dos 50 primeiros numeros pares e: %d\n",soma);

    system("pause");
    return 0;
}
