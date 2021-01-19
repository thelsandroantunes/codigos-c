/*  Autor: Thelsandro Costa Antunes
*   Data: 19/01/2021
*   EXERCÍCIO SOMA DE PARES
*   Questao: Faça um programa que calcule e mostre a soma dos N primeiros números pares.
*
*/

#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

int main(){

    setlocale (LC_ALL, "portuguese");

    int i=0,soma=0, N;

    printf("Digite um número: \n");
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
