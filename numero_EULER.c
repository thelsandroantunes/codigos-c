/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO NÚMERO DE EULER
*   Questao: Faça um programa que leia um valor N inteiro e positivo, calcule o mostre o valor E, conforme a fórmula a seguir
*							
*						 E = 1 + 1/1! + 1/2! + 1/3! + ... + 1/N!
*
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int N = 10;
	int i,j;
	float f, E = 1.0;
	
	for(i=1; i <= N; i++){
		
		f = 1;
		
		for(j=1;j <= i; j++)	{
			f = f * j;	
		}	
		
		E = E + 1.0/f ;
	}	
	
	printf("E = %f\n", E);
		
	system("pause");
	return 0;
}

