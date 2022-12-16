/*primero se conoce la cardinalidad del arreglo
posteriormente ese numero se divide a la mitad
y ese sera el numero de casillas  a las que saltos hará
Finalmente el numero de espaciados que se den dependera de si se
ordenaron todas las casillas a las que se hizo el salto*/
#include <stdio.h>
#include <stdlib.h>
void shellSort(int valores[], int n){
    int salto = n/2;
    int i, j, k;
    while(salto > 0){
        for(i = 0; i<n; i++){
            
            j= i-salto;
            while(j >= 0){
                k = j + salto;

                if(valores[j]<= valores[k]){
                    j =-1;
                }else{
                    int temp = valores[j];
                    valores[j] = valores[k];
                    valores[k] = temp;

                    j-= salto;
                }
            }
        }
        
        
        salto = salto /2;
    }

}

void printArray(int valores[], int n){
     for(int i = 0; i<n; i++){
        printf("%i ", valores[i]);
    }
    printf("\n");
}

int main(){
    int valores[] = {15, 42, 3, 12, 4, 1, 8, 45,784,32,76,13,75,46,2,86};  
    int n = sizeof valores / sizeof *valores;
    int objetivo;
    int iteraciones = 0;

    printf("Que numero deseas buscar?: ");
    scanf("%d", &objetivo);

    while(iteraciones < n && objetivo != valores[iteraciones]){
        iteraciones++;
    }
    if(iteraciones < n){
        printf("El valor %d ha sido encontrado en la posicion: %d\n y se hicieron %d iteraciones\n\n", objetivo, iteraciones, iteraciones+1);
    }else{
        printf("El %d No se encontro en la lista...\n", objetivo);
    }

    printf("Hay %d elementos en el arreglo...\n", n);
    printf("Antes de ordernar: \n");
    printArray(valores, n);

    shellSort(valores, n);

    printf("Despues de ordernar: \n");
    printArray(valores, n);

    return 0;
}