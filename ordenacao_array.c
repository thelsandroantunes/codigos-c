/*  Autor: Thelsandro Costa Antunes
*   Data: 20/01/2021
*   EXERCÍCIO ORDENAR ARRAY
*   Questao: Faça um programa que ordene um array de tamanho N.
*
*/

#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

int main(){

    setlocale (LC_ALL, "portuguese");
    srand((unsigned) time(NULL));

    int i, j, maior,aux, N;

    printf("Tamanho do array: \n");
    scanf("%d",&N);

    int arr[N];

    for(i=0;i<N;i++)
        arr[i] = 1+(rand())%100;

    printf("\nO vetor: \n");
    printf("[");
    for(i=0;i<N;i++)
    {
        if(i != N-1)
            printf("%d, ",arr[i]);
    }
    printf("%d]\n\n",arr[N-1]);

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(arr[i] < arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }

    printf("Vetor ordenado:\n");
    printf("[");
    for(i=0;i<N;i++)
    {
        if(i != N-1)
            printf("%d, ",arr[i]);
    }
    printf("%d]\n\n",arr[N-1]);

    system("pause");
    return 0;
}

