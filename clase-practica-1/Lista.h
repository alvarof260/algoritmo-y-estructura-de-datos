#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct nodo
{
    Item dato;
    struct nodo *sig;
} Nodo;

void crearLista(Nodo **h)
{
    *h = NULL;
}

int esListaVacia(Nodo *h)
{
    return h == NULL;
}

void mostrar(Nodo *l)
{
    Nodo *aux = l;
    if (esListaVacia(aux))
    {
        printf("La lista esta vacia\n");
        return;
    }
    while(aux != NULL)
    {
        printf("%d \n", aux->dato);
        aux = aux->sig;
    }
}

void primerElemento(Nodo *l)
{
    if(esListaVacia(l))
    {
        printf("La lista esta vacia\n");
        return;
    }
    printf("El primer elemento de la lista es: %d\n", l->dato);
}

void insertar(Nodo **l, Item x)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = x;
    nuevo->sig = *l;
    *l = nuevo;
}