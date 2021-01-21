/*  Autor: Thelsandro Costa Antunes
*   Data: 21/01/2021
*   EXERCÍCIO MULTIPLICAÇÃO DE VETOR E MATRIZ
*   Questao: . Faça um programa que lê um vetor de N elementos e uma matriz de N x N elementos. Em
*              seguida o programa deve fazer a multiplicação do vetor pelas colunas da matriz.
*
*/


#include<stdio.h>

#include <locale.h>

int main()
{
    setlocale (LC_ALL, "portuguese");
    srand((unsigned) time(NULL));

    int i,j,soma_par=0;
    int N;

    do{
        printf("Digite o tamanho da MATRIZ AxA: \n");
        scanf("%d",&N);
    }while(N < 2);

    int matriz[N][N], vetor[N];

    printf("::: Os elementos do vetor e matriz são randômicos:::\n");
    for(i=0;i<N;i++)
        vetor[i] = 1+(rand())%10;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            matriz[i][j] = 1+(rand())%10;

    printf("\n::: VETOR :::\n");
    printf("[");
    for(i=0;i<N-1;i++)
        printf("%d, ",vetor[i]);
    printf("%d]\n",vetor[N-1]);
    printf("\n::: Valores Originais da Matriz :::\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",matriz[i][j]);
        printf("\n");
    }

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            matriz[i][j] = vetor[i]*matriz[i][j];

    printf("\n::: Vetor X Matriz :::\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",matriz[i][j]);
        printf("\n");
    }

    system("pause");
    return 0;
}
