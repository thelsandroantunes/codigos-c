/*  Autor: Thelsandro Costa Antunes
*   Data: 20/01/2021
*   EXERCÍCIO CONTA DE PARES
*   Questao: Faça um programa que conte os N números pares.
*
*/

#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

int main(){

    setlocale (LC_ALL, "portuguese");
    srand((unsigned) time(NULL));


    int i=0,cont=0, N;

    printf("Tamanho do array: \n");
    scanf("%d",&N);

    int array[N];

    for(i=0;i<N;i++)
    {
        array[i] = 1+(rand())%100;
    }

    for(i=0;i<N;i++)
    {
        if(array[i]%2==0)
            cont=cont+1;
    }

    printf("O vetor: ");
    printf("[");
    for(i=0;i<N;i++)
    {
        if(i != N-1)
            printf("%d, ",array[i]);
    }
    printf("%d]\n",array[N-1]);

    printf("qdt PARES: %d\n",cont);

    system("pause");
    return 0;
}
