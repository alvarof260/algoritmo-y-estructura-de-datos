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
    primerElemento(head);
    return 0;
}