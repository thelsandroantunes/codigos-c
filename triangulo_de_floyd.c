/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO TRIÂNGULO DE FLOYD
*   Questao: Escreva um programa que dado um número inteiro positivo N,
*            imprima N linhas do chamado Triângulo de Floyd:
*							1
*							2		3
*							4		5		6
*							7		8		9		10
*							11	12	13	14	15
*							16	17	18	19	20	21
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int N = 7;
	int i,j, c = 0;
	
	for(i=1;i < N; i++){
		for(j=1;j <= i; j++){
			c++;
			printf("%d	",c);
		}
		
		printf("\n");
	}
	
	
	system("pause");
	return 0;
}
