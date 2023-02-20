#include <stdio.h>

// Función recursivo para calcular el factorial de un número
unsigned long factorial(int n){
    return (n < 1) ? 1 : n * factorial(n - 1);
}

int main(){
    int n = 6;
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("");
    printf("El Factorial de %d es %lu", n, factorial(n));

    return 0;
}