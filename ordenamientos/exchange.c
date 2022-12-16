#include <stdio.h>
#include <stdlib.h>

void exchange(int valores[], int n){
    printf("Matriz Incial: ");
    for(int i = 0; i<n;i++){
        printf("%i, ", valores[i]);
    }


    for(int a = 0; a < n-1; a++){
        for(int b = a+1; b<n; b++){

            if(valores[a]>valores[b]){
            int temp = valores[a];
            valores[a] = valores[b];
            valores[b] = temp;
            }
        }
    }
}

int main(){

    int valores[] ={70, 43, 52,6, 18,92, 44, 7};

    exchange(valores, 8);
    printf("\n");
    exchange(valores, 8);
    //printf("");

    return 0;
}