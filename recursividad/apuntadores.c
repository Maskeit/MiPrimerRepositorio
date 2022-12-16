#include <stdio.h>

void cubo(int *n);
int main(){

    int num = 5;
    printf("Valor original = %d\n",num);
    cubo(&num);
    printf("El nuevo valor = %d\n", num);
    return 0;
}
void cubo(int *n){
    *n= *n * *n * *n;
}