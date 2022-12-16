#include <stdio.h>

int suma();
int num3 = 2;
int main(){
    int num1, num2;
    printf("Ingresa el PRIMER valor: ");
    scanf("%d",&num1);
    printf("Ingresa el SIGUIENTE valor: ");
    scanf("%d",&num2);

    printf("La suma de %d + %d es = %d\n",num1,num2, suma(num1, num2));
    return 0; //indica que el programa termino con exito
}
int suma(int num1, int num2){
    int suma = num1 + num2 + num3;
    return suma;
}