#include <stdio.h>
#include "Lista.h"

int main()
{
    Nodo *head;
    crearLista(&head);
    esListaVacia(head)
        ? printf("La lista esta vacia\n")
        : printf("La lista no esta vacia\n");
    insertar(&head, 40);
    insertar(&head, 30);
    mostrar(head);
    printf("La lista tiene %d elementos\n", longitud(head));
    primerElemento(head);
    borrar(&head);
    pertenece(head, 40)
        ? printf("El elemento 40 pertenece a la lista\n")
        : printf("El elemento 40 no pertenece a la lista\n");
    mostrar(head);
    return 0;
}