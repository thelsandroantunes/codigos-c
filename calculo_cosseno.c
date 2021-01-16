/*  Autor: Thelsandro Costa Antunes
*   Data: 16/01/2021
*   EXERCÍCIO CÁLCULO COSSENO
*   Questao: Faça uma função que receba como parâmetro o valor de um ângulo em graus
*							e calcule o valor do cosseno desse ângulo usando sua respectiva 
*							série de Taylor
*							
*						 COS(X) = x - x^2/2! + x^4/4! + ...
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fatorial(int);
float cosseno(float);

int main(){ 
	
	float ang = 45.0;
	ang = 3.141593 * ang/180.0;
	
	printf("cosseno %f\n", cosseno(ang));
	printf("cos = %f\n",cos(ang));
	
		
	system("pause");
	return 0;
}

int fatorial(int N){
	
	int i, f = 1;
	
	for(i=1; i <= N; i++){
		f = f * i;	
	}
	
	return f;
}

float cosseno(float x){
	int n;
	float c =0.0;
	
	for(n=0;n <= 5;n++){
		c = c + pow(-1,n)*pow(x,2*n)/fatorial(2*n);
	}
	return c;
}


