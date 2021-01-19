/*  Autor: Thelsandro Costa Antunes
*   Data: 19/01/2021
*   EXERCÍCIO MAIOR ELEMENTO NO ARRAY
*   Questao: Faça um programa que encontre o maior valor no vetor.
*
*/

#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

int main(){

    setlocale (LC_ALL, "portuguese");
    srand((unsigned) time(NULL));

    int tam;

    printf("Digite o tamnaho do vetor: ");
    scanf("%d",&tam);

    int numero[tam];
    int i,maior,posicao;

    for(i=0;i<tam;i++)
    {
       numero[i] = 1+(rand())%100;
    }

    maior=numero[0];

    for(i=1;i<tam;i++)
    {
      if(numero[i]>maior)
      {
          maior=numero[i];
          posicao=i;
      }
    }

    printf("O vetor: ");
    printf("[");
    for(i=0;i<tam;i++)
    {
        if(i != tam-1)
            printf("%d, ",numero[i]);
    }

    printf("%d]\n",numero[tam-1]);

    printf("ELEM:%d\n",maior);
    printf("POS:%d\n",posicao);

    system("pause");
    return 0;
}
