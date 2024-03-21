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

void main() {
    lista *listaNumero = crearLista();
    imprimirLista(listaNumero);
    esListaVacia(listaNumero) ? printf("La lista esta vacia\n") : printf("La lista no esta vacia\n");
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
    return e->dato == 0;
}