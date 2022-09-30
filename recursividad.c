//Ejemplo de factorial de un numero

#include<stdio.h>

long Factorial(long numero); //incluimos la funcion

int main(){

	int numero;

	printf("Ingresa un numero\n");
	scanf("%i",&numero);

	for(int i = 0; i<= numero; i++)
	{	
	   printf("%ld--", Factorial(i));
	}
	return 0;
}

long Factorial(long numero)//definimos la funcion
{
  if(numero<=1){
	return 1;
  }else{
	  return(numero * Factorial(numero-1));
	}
}

