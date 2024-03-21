#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para los nodos de la lista
struct nodo {
    int dato;  // Valor del nodo
    struct nodo *sig;  // Puntero al siguiente nodo
}typedef lista;

// Declaración de funciones
lista *crearLista();
void imprimirLista(lista *head);
int esListaVacia(lista *e);
int primerElemento(lista *e);
/* lista *insertarElemento(lista *e, int dato); */
void insertarValor(lista *e, int dato, int posicion);
lista *eliminarElemento(lista *e, int posicion);
int longitudLista(lista *e);
int perteneceValor(lista *e, int dato);

void main() {
    // Crear una lista vacía
    lista *listaNumero = crearLista();

    // Comprobar si la lista está vacía
    esListaVacia(listaNumero) ? printf("La lista esta vacia\n") : printf("La lista no esta vacia\n");

    // Insertar elementos en la lista
    listaNumero = insertarElemento(listaNumero, 10);
    listaNumero = insertarElemento(listaNumero, 20);

    // Imprimir la lista
    printf("La lista tiene estos elementos\n");
    imprimirLista(listaNumero);

    // Insertar un valor en una posición específica
    insertarValor(listaNumero, 30, 1);
    printf("luego de insertar el valor 30 en la posicion 1\n");
    imprimirLista(listaNumero);
    printf("La longitud de la lista es: %d\n", longitudLista(listaNumero));

    // Eliminar un elemento de una posición específica
    listaNumero = eliminarElemento(listaNumero, 1);
    printf("luego de eliminar el valor en la posicion 1\n");
    imprimirLista(listaNumero);
    perteneceValor(listaNumero, 20) ? printf("El valor 20 pertenece a la lista\n") : printf("El valor 20 no pertenece a la lista\n");

    // Liberar la memoria de la lista
    free(listaNumero);

    printf("Hola mundo\n");
}

// Función para crear una lista vacía
lista *crearLista() {
    return NULL;
}

// Función para imprimir los elementos de la lista
void imprimirLista(lista *head) {
    lista *aux = head;
    while (aux != NULL) {
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }
}

// Función para comprobar si la lista está vacía
int esListaVacia(lista *e) {
    return e == NULL;
}

// Función para obtener el primer elemento de la lista
int primerElemento(lista *e) {
    if(esListaVacia(e)) {
        printf("La lista esta vacia\n");
        return -1;
    }
    return e->dato;
}

// Función para insertar un elemento al inicio de la lista
lista *insertarElemento(lista *e, int dato) {
    lista *nuevo = (lista *)malloc(sizeof(lista));
    nuevo->dato = dato;
    nuevo->sig = e;
    return nuevo;
}

// Función para insertar un valor en una posición específica
void insertarValor(lista *e, int dato, int posicion) {
    lista *aux = e;
    for(int i = 0; i < posicion; i++) {
        if(aux == NULL) {
            printf("La posicion es mayor que la longitud de la lista\n");
            return;
        }
        aux = aux->sig;
    }
    if(aux != NULL) {
        aux->dato = dato;
    }
}

// Función para eliminar un elemento de una posición específica
lista *eliminarElemento(lista *e, int posicion) {
    if(esListaVacia(e)) {
        printf("La lista esta vacia\n");
        return e;
    }
    if (posicion == 0) {
        lista *siguienteNodo = e->sig;
        free(e);
        return siguienteNodo;
    }

    lista *nodoActual = e;
    for(int i = 0; i < posicion - 1; i++) {
        if (nodoActual->sig == NULL) {
            printf("La posicion es mayor que la longitud de la lista\n");
            return e;
        }
        nodoActual = nodoActual->sig;
    }

    lista *nodoAEliminar = nodoActual->sig;
    nodoActual->sig = nodoAEliminar->sig;
    free(nodoAEliminar);
    return e;
}

// Función para obtener la longitud de la lista
int longitudLista(lista *e) {
    int longitud = 0;
    lista *aux = e;
    while(aux != NULL){
        longitud++;
        aux = aux->sig;
    }
    return longitud;
}

// Función para comprobar si un valor pertenece a la lista
int perteneceValor(lista *e, int dato) {
    lista *aux = e;
    while(aux != NULL) {
        if(aux->dato == dato) {
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
}