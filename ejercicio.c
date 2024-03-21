#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *sig;
}typedef lista;

lista *crearLista();
void imprimirLista(lista *head);

void main() {
    lista *listaNumero = crearLista();
    imprimirLista(listaNumero);
    printf("Hola mundo\n");
}

lista *crearLista() {
    lista *head = (lista *)malloc(sizeof(lista));
    head->dato = 0;
    head->sig = NULL;
    return head;
}

void imprimirLista(lista *head) {
    lista *aux = head;
    while (aux != NULL) {
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }
}