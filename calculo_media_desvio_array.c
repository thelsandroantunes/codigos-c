/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO MÉDIA E DESVIO PADRÃO DE UM ARRAY
*   Questao: Faça um programa que calcule a média e o desvio padrão de um vetor contendo n números.
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void calcular(int*, int, float*,float*);

int main(){
	
	int v[5] = {1,2,3,4,5};	
	float media, desvio;
	
	calcular(v, 5, &media, &desvio);
	printf("%f\n%f\n", media, desvio);
	
	system("pause");
	return 0;
}

void calcular(int *vetor, int n, float *m,float *dp){
	int i;
	*m = 0.0;
	for(i=0;i<n;i++){
		*m = *m + vetor[i];
	}
	
	*m = *m/n;
	*dp = 0.0;
	
	for(i=0;i<n;i++){
		*dp = *dp + pow(vetor[i] - *m,2);
	}
	
	*dp = sqrt(*dp/(n-1));
	
}

