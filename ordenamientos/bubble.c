#include <stdio.h>

void bubbleSort( int valores[], int n){

    for(int i = 0; i<n-1; i++){
        for(int j = 0; i<n-i-1; i++){
            if(valores[j]> valores[j+1]){
                int temp = valores[j];
                valores[j]= valores[j+1];
                valores[j+1] = temp;
            }
        }
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

        while(iteraciones < n && objetivo != valores[iteraciones]){
        iteraciones++;
    }

    printf("La iteraciones: %d\n", iteraciones+1);

    printf("Antes de ordernar: \n");
    printArray(valores, n);

    bubbleSort(valores, n);

    printf("Despues de ordernar: \n");
    printArray(valores, n);

    return 0;
}