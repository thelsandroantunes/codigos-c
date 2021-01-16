/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO CÁLCULO DE UMA SÉRIE S
*   Questao: Faça uma função recursiva que calcule o valor da série S 
*							descrita a seguir para um valor n>0 a ser fornecido como 
*							parâmetro para a mesma:
*							
*						 S = 2 + 5/2 + 10/3 + ... + (1+n^2)/n
*
*/

#include<stdio.h>
#include<stdlib.h>

float serieS(int);

int main(){
	
	printf("S = %f \n", serieS(5));
		
	system("pause");
	return 0;
}


float serieS(int n){
	
	if(n > 0)
	{
		return (1+n*n)/(float)n + serieS(n-1);
	}
	else
	{
		return 0;
	}
}
