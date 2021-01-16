/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO MENOR NÚMERO DIVISÍVEL
*   Questao: Faça um programa que calcule o menor número divisível por cada um dos números de 1 a 10.
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



