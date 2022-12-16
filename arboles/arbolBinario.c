#include <stdlib.h>
#include <stdio.h>

struct nodo{
    struct nodo *padre;
    struct nodo *izquierdo;
    struct nodo *derecho;
    int valor;
};

struct nodo *crearNodo(struct nodo *padre, int valor);
struct nodo *buscarNodo(struct nodo *arbol, int valorAbuscar);
struct nodo *agregarValor(struct nodo *arbol, int valor);

int main(){
    struct nodo *arbol = NULL;
    char valor[20];
    int entero;
    arbol = crearNodo(NULL, 40);
    arbol = crearNodo(arbol, 10);
    arbol = crearNodo(arbol, 50);
    arbol = crearNodo(arbol, 30);

    printf("Que numero desea buscar en el arbol?: ");
    fgets(valor, 20, stdin);
    entero = atoi(valor);

    buscarNodo(arbol,entero);

    return 0;
}

struct nodo *crearNodo(struct nodo *padre, int valor){
    struct nodo *n = calloc(sizeof(struct nodo),1);
    n->padre = padre;
    n->valor = valor;
    return n;
};

struct nodo *agregarValor(struct nodo *arbol, int valor){
    struct nodo *temp, *pivote;
    int derecho = 0;
    if(arbol){
        temp=arbol;
        while(temp != NULL){
            pivote =temp;
            if(valor > temp->valor){
                temp = temp->derecho;
                derecho = 1;
            }else{
                temp = temp->izquierdo;
                derecho = 0;
                //izquierdo
            }
        }
        temp = crearNodo(pivote,valor);
        if(derecho){
            printf("Insertando %i del lado derecho de %i\n", valor, pivote->valor);
            pivote ->derecho = temp;
        }else{
            printf("Insertando %i del lado izquierdo de %i\n", valor, pivote->valor);
            pivote ->izquierdo = temp;
        }
        return arbol;
    }else{
        printf("Insertando %i como nodo raiz del arbol\n", valor);
        temp = crearNodo(NULL, valor);
        return temp;
    }
}

struct nodo *buscarNodo(struct nodo *arbol, int valorAbuscar){
    struct nodo *temp = NULL, *pivote = NULL;
    int contador = 0;
    int  entrar = 1;
    temp=arbol;
    while(entrar == 1 && temp != NULL){
        pivote =temp;
        contador++;
        if(valorAbuscar == temp->valor){
            printf("Nodo encontrado con %i comparaciones \n", contador);
            entrar = 0;
        }else{
            if(valorAbuscar > temp->valor){
                temp = temp->derecho;
            }else{
                temp = temp->izquierdo;
            }
        }
    }
    if(entrar == 1){
        printf("Nodo NO encontrado\n");
    }
        return temp;
}