#include<stdio.h>
#include<stdlib.h>

int A[6];

//Input: 8 2 4 9 3 6
//Output: 2 3 4 6 8 9

void intercambio(int *n, int *y){
	int temp = *n;
	*n = *y; //cambiar la x por la n
	*y = temp;
}

void exchange(int A[], int n){
  int tm=0;
  for(int i=0; i<n; i++) // cambiar el i=1 por i=0
    for(int j=i; j<n; j++)//cambiar j<n-1 por j<n
      if(A[i]>A[j]) 
	      intercambio(&A[i],&A[j]);
}

void leer_archivo(){
  FILE* archivo;
  char texto[20];
  char c;
  int i=0;
  int j=0;

  archivo = fopen("datos.txt","rt");
  do{
    c = fgetc(archivo);
    if(c == '/'){
      A[j] = atoi(texto);
      j++;
      for(int z=0; z<i; z++)
              texto[z]=0;
      i=0;
      continue;
    }
    texto[i] = c;
    i++;
  }while(c != EOF); //EOF End Of File
}

void pantalla(int A[], int n){
  for(int i=0; i<n-1; i++)
	printf("%d, ", A[i]);
  printf("%d", A[n-1]);
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void main(){
  int n=6;

  leer_archivo();
  printf("\nValores antes de ordenarse: ");
  pantalla(A, n);

  exchange(A, n);  //  funcion para el cambio

  printf("\n\nValores ordenados: ");
  pantalla(A, n);
  printf("\n\n");
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
