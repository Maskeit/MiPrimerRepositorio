#include <stdio.h>

void selectionSort(int valores[], int n){
    int valorMinimo;

    for(int a = 0; a<n-1; a++){
        valorMinimo = a;

        for(int b = a+1; b < n; b++){
            if(valores[b]< valores[valorMinimo]){
                valorMinimo = b; //aqui se cambia si se cumple la condicion
            }
        }

        if(a != valorMinimo){
            int temp = valores[a];
            valores[a] = valores[valorMinimo];
            valores[valorMinimo] = temp;
        }
    }
}

int main(){

    int valores[] = {78, 87, 3, 54, 21, 1, 2,5,99,12,534};

    int n =  sizeof valores / sizeof *valores;

    printf("\nArreglo desirdenado: \n");
    for(int i=0; i<n; i++){
        printf("%i ", valores[i]);
    }

    selectionSort(valores, n);

    printf("\nFinal: \n");
    for(int i=0; i<n; i++){
        printf("%i ", valores[i]);
    }
    printf("\n");

    return 0;

}