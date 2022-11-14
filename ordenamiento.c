#include<stdio.h>
#include<stdlib.h>

int A[5];

//Input: 8 2 4 9 3 6
//Output: 2 3 4 6 8 9

void intercambio(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int particion(int a[], int izq, int der){
  int pivote = a[izq];
    while(1){
      while(a[izq] < pivote){
        izq++;
      }
      while(a[der] > pivote){
        der--;
      }
      if(izq >= der){
        return der;
      }else{
        intercambio(&a[izq], &a[der]);
	izq++;
	der--;
      }
    }
}

void quicksort(int A[], int izq, int der){
  if(izq < der){
    int indice_de_particion = particion(A,izq,der);
    quicksort(A, izq, indice_de_particion);
    quicksort(A, indice_de_particion + 1, der);
  }
}


void insertion_sort(int A[], int n){
  int key=0, i=0;
  for(int j=1; j<n; j++){
      key = A[j];
      i = j-1;
      while(i>-1 && A[i]>key){
	A[i+1] = A[i];
	i = i-1;
      }
    A[i+1]=key;
  }
}

void bubble_sort(int A[], int n){
  int tm=0;
  for(int i=1; i<n; i++)
    for(int j=0; j<n-1; j++)
      if(A[j]>A[j+1]) intercambio(&A[j],&A[j+1]);
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
    if(c == ','){
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
  int n=5;
  leer_archivo();

  printf("\nValores antes de ordenarse: ");
  pantalla(A, n);
  //insertion_sort(A, n); funcion para el metodo insertion
  //bubble_sort(A, n);    funcion para el bubble
  quicksort(A,0,n);     //funcion para usar el quicksort

  printf("\n\nValores ordenados: ");
  pantalla(A, n);
  printf("\n\n");
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
