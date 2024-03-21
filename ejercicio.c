#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *sig;
}typedef lista;

lista *crearLista();
void imprimirLista(lista *head);
int esListaVacia(lista *e);
int primerElemento(lista *e);
lista *insertarElemento(lista *e, int dato);
void insertarValor(lista *e, int dato, int posicion);
lista *eliminarElemento(lista *e, int posicion);

void main() {
    lista *listaNumero = crearLista();
    esListaVacia(listaNumero) ? printf("La lista esta vacia\n") : printf("La lista no esta vacia\n");
    listaNumero = insertarElemento(listaNumero, 10);
    listaNumero = insertarElemento(listaNumero, 20);
    printf("La lista tiene estos elementos\n");
    imprimirLista(listaNumero);
    insertarValor(listaNumero, 30, 1);
    printf("luego de insertar el valor 30 en la posicion 1\n");
    imprimirLista(listaNumero);
    listaNumero = eliminarElemento(listaNumero, 1);
    printf("luego de eliminar el valor en la posicion 1\n");
    imprimirLista(listaNumero);
    free(listaNumero);
    printf("Hola mundo\n");
}

lista *crearLista() {
    return NULL;
}

void imprimirLista(lista *head) {
    lista *aux = head;
    while (aux != NULL) {
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }
}

int esListaVacia(lista *e) {
    return e == NULL;
}

int primerElemento(lista *e) {
    if(esListaVacia(e)) {
        printf("La lista esta vacia\n");
        return -1;
    }
    return e->dato;
}

lista *insertarElemento(lista *e, int dato) {
    lista *nuevo = (lista *)malloc(sizeof(lista));
    nuevo->dato = dato;
    nuevo->sig = e;
    return nuevo;
}

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
