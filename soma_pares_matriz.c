/*  Autor: Thelsandro Costa Antunes
*   Data: 21/01/2021
*   EXERCÍCIO SOMA DE PARES DA MATRIZ
*   Questao: Some os elementos pares da matriz e escreva o resultado na tela.
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

    int matriz[N][N];

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            matriz[i][j] = 1+(rand())%100;



    printf("\nMATRIZ %dX%d\n", N,N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",matriz[i][j]);
        printf("\n");
    }

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            if(matriz[i][j]%2==0)
                soma_par=soma_par+matriz[i][j];
        }

    printf("\n SOMA dos elementos par = %d \n",soma_par);

    system("pause");
    return 0;
}
