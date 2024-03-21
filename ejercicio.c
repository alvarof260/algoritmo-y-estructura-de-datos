#include <stdio.h>
#include <stdlib.h>

struct nodo {
    // Dato que almacena el nodo
    int dato;
    // Apuntador a la estructura nodo
    struct nodo *sig;
}typedef lista;

lista *crearLista();
void imprimirLista(lista *head);
int esListaVacia(lista *e);
int primerElemento(lista *e);
lista *insertarElemento(lista *e, int dato);

void main() {
    lista *listaNumero = crearLista();
    int numero;
    imprimirLista(listaNumero);
    esListaVacia(listaNumero) ? printf("La lista esta vacia\n") : printf("La lista no esta vacia\n");
    printf("El primer elemento de la lista es: %d\n", primerElemento(listaNumero));
    listaNumero = insertarElemento(listaNumero, 5);
    imprimirLista(listaNumero);
    printf("El primer elemento de la lista es: %d\n", primerElemento(listaNumero));
    printf("Hola mundo\n");
}

// Función que crea una lista vacía
lista *crearLista() {
    lista *head = (lista *)malloc(sizeof(lista));
    head->dato = 0;
    head->sig = NULL;
    return head;
}

// Función que imprime los elementos de la lista
void imprimirLista(lista *head) {
    lista *aux = head;
    while (aux != NULL) {
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }
}

// Función que verifica si la lista está vacía
int esListaVacia(lista *e) {
    return (e->dato == 0 && e->sig == NULL);
}

// Función que retorna el primer elemento de la lista
int primerElemento(lista *e) {
    if(esListaVacia(e)) {
        printf("La lista esta vacia\n");
        return -1;
    }
    return e->dato;
}

// Función que inserta un elemento en la lista en la primera posición
lista *insertarElemento(lista *e, int dato) {
    lista *nuevo = (lista *)malloc(sizeof(lista));
    nuevo->dato = dato;
    nuevo->sig = e;
    return nuevo;
}