#include <stdio.h>
//ejemplo del factorial de un numero

long factorial(long numero);

int main(){
    int numero;
    printf("Ingresa un numero: ");
    scanf("%d",&numero);

    for(int i = 0; i<=numero; i++){
        printf("%ld\n", factorial(i));
    }
    return 0;
}

long factorial(long numero){
    if(numero<= 1){
        return 1;
    } else{
        return(numero * factorial(numero - 1));
    }
}