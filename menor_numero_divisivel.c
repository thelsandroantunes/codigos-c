/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERC�CIO MENOR N�MERO DIVIS�VEL
*   Questao: Fa�a um programa que calcule o menor n�mero divis�vel por cada um dos n�meros de 1 a 10.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int N, nro;
	N = nro = 20;
	int i, achou = 0;
	
	while(achou == 0){
	
		achou = 1;
		for(i = 2; i <= N; i++){
				if(nro % 2 != 0){
					achou = 0;
					break;
				}
		}
		
		if(achou == 1)
			printf("Nro = %d\n",nro);
		else 
			nro = nro + 2;
	
	}
	
	system("pause");
	return 0;
}



