/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO LENDO LISTA DE COMPRAS DE ARQUIVO
*   Questao: Faça um programa que leia um arquivo com os nomes, 
*							quantidades e preços de diversos produtos, um por linha e 
*							calcule o total da compra.
*
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char prod[30];
	float qtd, valor, total = 0.0;
	FILE *f = fopen("arq01-compras.txt","r");
	
	if(f == NULL){
		
		printf("Erro na abertura\n");
		system("pause");
		exit(1);
		
	}
	
	while(!feof(f)){
		
		fscanf(f, "%s %f %f", prod, &qtd, &valor);
		total += qtd * valor;
		
	}
	
	printf("Total = %f\n", total);
	
	system("pause");
	return 0;
}
