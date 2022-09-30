/*Ing de Software 3-D
 *Miguel Agustin Alejandre Arreola
 *vie 30 de sep
 *Problema Uno Exponenciacion Entera
 *evaluaion 1era parcial 
 */

#include<stdio.h>

long exponente(long numero, long exp);

int main(){

	int numero, exp, resultado;
	
	printf("Ingresa un Numero: ");
	scanf("%i",&numero);

	printf("Ingresa el exponente: ");
	scanf("%i",&exp);

	resultado = exponente(numero,exp);

	printf("El resultado de elevar %i a la %i es igual a: %i\n",numero, exp, resultado);
}

long exponente(long numero, long exp)
{
	int resultado;

	if(exp==0){
		return 1;
	}else if(exp > 0){
		resultado = numero * exponente(numero, exp-1);
		return resultado;
	}else if(exp<0){
		resultado = 1/numero * exponente(numero, exp +1);
	}
	return resultado;
}
