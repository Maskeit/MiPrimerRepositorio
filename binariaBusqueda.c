/*Tiene que estar completamente ordenado*/


#include <stdio.h>

int intentos = 0;

int busquedaBinaria(int valores[], int objetivo, int primero, int ultimo){

    intentos++;

    if (ultimo >= primero){
        int central = primero + (ultimo - primero)/2;
        if(valores[central] == objetivo){
            return central;
        }
        if(valores[central]>objetivo){
            return busquedaBinaria(valores, objetivo, primero, central-1);
        }
        return  busquedaBinaria(valores, objetivo, central + 1, ultimo);
    }
    
    return -1;
}

int main(){
    int valores[] = {13, 15, 18,23, 32, 45, 55, 81, 90};
    int n = sizeof valores / sizeof(valores[0]);  

    int objetivo = 13;

    int primero = 0;
    int ultimo = n-1;

    int resultado = busquedaBinaria(valores, objetivo, primero, ultimo);
    if(resultado == -1){
    printf("No se encontro ningun elemento..\n");
    }else{
        printf("El elemento esta en el indice: %d\n", resultado);
    }
    printf("Intentos: %d\n", intentos);

    return 0;
}