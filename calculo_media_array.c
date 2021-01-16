/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERC�CIO M�DIA DE UM ARRAY
*   Questao: Fa�a uma fun��o recursiva que consiga calcular a m�dia de um vetor de tamanho N. 
*
*/

#include<stdio.h>
#include<stdlib.h>

float media(int*,int,int);

int main(){
	
	int v[5] = {1,2,3,4,5};
	printf("Media = %f\n", media(v,5,5));
	
	system("pause");
	return 0;
}

float media(int *vetor,int n,int tam){
	
	if(n <= 0)
	{
		return 0;
	}
	else
	{
		return vetor[n-1]	/ (float)tam + media (vetor, n-1, tam);
	}

}
